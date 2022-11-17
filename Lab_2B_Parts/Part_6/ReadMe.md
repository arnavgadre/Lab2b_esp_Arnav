# PIOSCOPE
This is a demo of getting an I2C trace captured on PuTTY.
<br>

https://user-images.githubusercontent.com/52575718/202362846-2a15ae73-10d4-48c9-8fc9-876644a8acb5.mp4

<br>

- When the `BOOT` button was pressed, an `I2C` trace was recorded using an adaptation of the logic analyser example from pico-examples.
- The capture includes both the `SDA` and `SCL` pins.
- The capture was shown on PuTTY using two different boards. The first board was running the modified logic analyser code, while the second board (RP2040) is running the micropython-based code that connects the `APDS9960` and `QtPy`.
