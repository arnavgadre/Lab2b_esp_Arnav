#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"
#include "/home/arnavgadre/pico/pico-sdk/src/boards/include/boards/adafruit_qtpy_rp2040.h"
#include "registers.h"

#define LED_PIN_NUM_1 5 // BLUE
#define LED_PIN_NUM_2 6 // YELlOW

#define CONST_MULT 4
#define CONST_ADD 3
#define CONST_MOD 10
#define NUM_ITERATIONS 5

#define IS_RGBW true
#define NUM_PIXELS 150
#define PICO_DEFAULT_WS2812_POWER_PIN 11

#define QTPY_BOOT_PIN_NUM 21
#define QTPY_BOOT_PIN_REG ((volatile uint32_t *)(IO_BANK0_BASE + 0x0A8))
#define CONST_TIME_SCALING_FACTOR 50

#define NUM_KEY_PRESS 5

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

// function to define a random number
int linear_congruential(int seed, int count){
    for (int i=0;i<count;i++){
        seed = (CONST_MULT * seed + CONST_ADD) % CONST_MOD;
    }
    return seed;
}

void set_neopixel_color(uint32_t color_num){
    uint32_t r_num = color_num >> 16;
    uint32_t g_num = color_num << 16;
    g_num = g_num >> 24;
    uint32_t b_num = color_num << 24;
    b_num = b_num >> 24;
    uint32_t color_final = ((r_num << 8) |
                            (g_num << 16)|
                            (b_num));
    pio_sm_put_blocking(pio0, 1, color_final << 8u);
}

void blink_led(PIO pio, uint sm, uint pin, uint offset){

    game_program_init(pio, sm, offset, pin);
    pio_sm_set_enabled(pio, sm, true);

    // PIO counter program takes 3 more cycles in total than we pass as
    // input (wait for n + 1; mov; jmp)
    pio->txf[sm] = 5000000;
}

int main() {
    const uint POWER_PIN_NAME = PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(POWER_PIN_NAME);
    gpio_init(QTPY_BOOT_PIN_NUM);
    gpio_set_dir(POWER_PIN_NAME, GPIO_OUT);
    gpio_set_dir(QTPY_BOOT_PIN_NUM, GPIO_IN);
    gpio_put(POWER_PIN_NAME, 1);

    gpio_init(LED_PIN_NUM_1);
    gpio_init(LED_PIN_NUM_2);
    gpio_set_dir(LED_PIN_NUM_1, GPIO_OUT);
    gpio_set_dir(LED_PIN_NUM_2, GPIO_OUT);
    stdio_init_all();

    char user_seed;
    int user_inp = 0;

    while(!stdio_usb_connected());

    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &game_program);
    printf("Loaded program at %d\n", offset);
    
    int sm_1 = 1;
    uint offset_1 = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm_1, offset_1, WS2812_PIN, 800000, IS_RGBW);
    int wait_time_arr[NUM_KEY_PRESS] = {0};

    while(1){

        //----------------------------Record Key presses---------------------------------
        int wait_time = 0, idx = 0;
        
        // Recording the wait time between key pressed.
        printf("Enter Major Input:\n");
        while((user_inp = getchar_timeout_us(5000)) < 0);
        printf("This is what you entered:%c\n", user_inp);
        if (user_inp == 'r') {
            printf("Starting Recording..\n");
            while (idx < NUM_KEY_PRESS){
                uint32_t button_status = register_read(QTPY_BOOT_PIN_REG);
                if(button_status != 0){
                    wait_time+=1;
                }else{
                    if (wait_time != 0){
                        printf("%d\n", wait_time);
                        wait_time_arr[idx] = wait_time;
                        idx += 1;
                    }
                    wait_time = 0;
                }
                sleep_ms(100);
            }
            printf("\n");
        } if (user_inp == 'p') {
            //----------------------------Replay Key presses---------------------------------
            int wait_time_input = 0;
            /* printf("Playing..\n"); */
            idx = 0;
            printf("Starting Playing..\n");
            while (idx < NUM_KEY_PRESS){
                /* printf("Waiting for time input"); */
                /* while((wait_time_input = getchar_timeout_us(5000)) < 0); */
                /* printf("This is what you entered:%d", wait_time_input); */
                set_neopixel_color(0xff00ff);
                sleep_ms(500);
                set_neopixel_color(0);
                sleep_ms(wait_time_arr[idx]*CONST_TIME_SCALING_FACTOR);
                idx += 1;
                printf("Done Blinking this iteration\n");
            }
            printf("Complete\n");
        } if (user_inp == 'g') {
            int flag = 0, rand_num = 0;
            while (1) {
                if (flag == 0){
                    sleep_ms(1000);
                    printf("Enter a seed between 1-10 for generating a random number:");
                    sleep_ms(1000);
                    while((user_seed = getchar_timeout_us(0)) < 0);
                    user_seed = user_seed - 48;
                    printf("This is your seed: %d\n", (int)user_seed);
                    rand_num = linear_congruential((int)user_seed, NUM_ITERATIONS);
                    printf("Your random number is generated which lies between 1 to 10!!\n\n");
                    flag = 1;
                }
                printf("Enter your guess:\n");
                while ((user_inp = getchar_timeout_us(0)) < 0);
                sleep_ms(100);
                user_inp = user_inp - 48;
                if (user_inp != 207){
                    printf("This is your number:%d\n", (int)user_inp);
                    if ((int)user_inp < rand_num){
                        blink_led(pio, sm, LED_PIN_NUM_1, offset);
                        printf("Think Higher!!\n");
                    }if ((int)user_inp > rand_num){
                        blink_led(pio, sm, LED_PIN_NUM_1, offset);
                        printf("Think Lower!!\n");
                    }if ((int)user_inp == rand_num){
                        blink_led(pio, sm, LED_PIN_NUM_2, offset);
                        printf("Woohoo!!!! That's great you won!!\n");
                        break;
                    }
                }
            }
        }
        sleep_ms(500);
    }
    return 0;
}
