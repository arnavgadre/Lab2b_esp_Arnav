#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "registers.h"

#include "/home/arnavgadre/pico/pico-sdk/src/boards/include/boards/adafruit_qtpy_rp2040.h"

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


void set_neopixel_color(uint32_t color_num){
    uint32_t r_num = color_num >> 16;
    uint32_t g_num = color_num << 16;
    g_num = g_num >> 24;
    uint32_t b_num = color_num << 24;
    b_num = b_num >> 24;
    uint32_t color_final = ((r_num << 8) |
                            (g_num << 16)|
                            (b_num));
    pio_sm_put_blocking(pio0, 0, color_final << 8u);
}

uint8_t pio_get_boot_status(PIO pio, uint sm) {
    return (uint8_t)pio_sm_get(pio, sm);
}

int main() {
    //set_sys_clock_48();
    // Initialize the GPIO Pins
    const uint POWER_PIN_NAME = PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(POWER_PIN_NAME);
    gpio_init(QTPY_BOOT_PIN_NUM);
    gpio_set_dir(POWER_PIN_NAME, GPIO_OUT);
    gpio_set_dir(QTPY_BOOT_PIN_NUM, GPIO_IN);
    gpio_put(POWER_PIN_NAME, 1);
    stdio_init_all();

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    int sm_1 = 1;
    uint offset = pio_add_program(pio, &ws2812_program);
    uint offset_1 = pio_add_program(pio, &boot_status_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    boot_status_program_init(pio, sm_1, offset_1, QTPY_BOOT_PIN_NUM);
    int button_status = 0;

    while(!stdio_usb_connected());

    while(1){

        //----------------------------Record Key presses---------------------------------
        int wait_time = 0, idx = 0;
        int wait_time_arr[NUM_KEY_PRESS] = {0};
        
        // Recording the wait time between key pressed.
        printf("#######################################################################\n");
        printf("              Use the BOOT Button to record 5 Keypresses               \n");
        printf("#######################################################################\n");
        while (idx < NUM_KEY_PRESS){
            button_status = pio_get_boot_status(pio, sm_1);
            if(button_status != 0){
                wait_time+=1;
            }else{
                if (wait_time != 0){
                    printf("Wait time is : %d\n", wait_time);
                    wait_time_arr[idx] = wait_time;
                    idx += 1;
                }
                wait_time = 0;
            }
            sleep_ms(100);
        }

        //----------------------------Replay Key presses---------------------------------
        printf("#######################################################################\n");
        printf("               Replaying the BOOT Button Keypresses                    \n");
        printf("#######################################################################\n\n");
        for (int i=0;i<NUM_KEY_PRESS;i++){
            set_neopixel_color(0xff00ff);
            sleep_ms(500);
            set_neopixel_color(0);
            sleep_ms(wait_time_arr[i]*CONST_TIME_SCALING_FACTOR);
        } 

        /* sleep_ms(100); */
        /* user_inp = pio_get_boot_status(pio, sm1); */
        /* printf("%d\n", user_inp); */
        sleep_ms(100);
    }
}
