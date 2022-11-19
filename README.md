# ESE 5190 - Lab2b Expansion Board Proposal

This is the overview for the proposal for the expansion board.

## Video of the Protoboard:

<br>

https://user-images.githubusercontent.com/52575718/202836635-c932556d-d04d-4913-acfc-93fc4774dcfd.mp4

<br>

## OLD Proposal:

https://user-images.githubusercontent.com/52575718/202836694-7f6073c9-7193-4021-881f-96ab109ca94d.mp4

<br>

## Plan Outline
We plan to light 2 separate LEDs on our Breadboard using the RP20240 board. Two different LEDs will glow based on the input enetered by the user on the keyboard. When the `C` key is pressed, the Green LED lights up. When the `D` key is pressed, the Blue LED lights up. We use serial communication for controlling our LED this way. The `SCL1` and `SDA1` pins of the Adafruit QTPy RP2040 are conneted to the `GPIO23` and `GPIO22` pins respectively. This is evident from the RP2040 pinout diagram shown below.
<br>

![image](https://user-images.githubusercontent.com/52575718/197116289-085e771a-cd86-4a01-ad12-84b62071e2f9.png)

The Link for this documentation is: [RP2040_Pinout](https://learn.adafruit.com/adafruit-qt-py-2040/pinouts)

<br>

We are using the GPIO pins to control our LEDs. We have intitialized the `GPIO22` and `GPIO23` pins using the `gpio_init` and `gpio_det_dir` functions. The user input is being read using the `getchar_timeout_us(5000)`, which returns a character from `stdin` if available. When `C` is pressed, the message "GREEN SHOULD BE ON" is printed on the Serial Output, and the Green LED lights up. When `D` is pressed, the message "BLUE SHOULD BE ON" is printed on the Serial Output, and the Blue LED lights up. We drive the GPIO pins High and LOW using the `gpio_put` functions.

This project can be extended to be used as a Password Authenticator in lockers, where you will be granted access whenever the right password is entered.


## Components Used:
- Breadboard
- STEMMA QT Cable
- 1k ohm and 100 ohm Resistors
- Blue LED
- Green LED
- Adafruit QTPy: RP2040
