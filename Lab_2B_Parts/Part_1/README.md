# REGISTERS

This is the video demonstration for reading directly from the register. In this program, when the on-board `BOOT` button is pressed, the `neopixel` LED blinks.

<div align='center'>
  <video src='https://user-images.githubusercontent.com/52575718/200737013-eecb0ece-44c7-4c24-b681-8eca244f081f.mp4'>
</div>

- We define the `QTPY_BOOT_PIN_REG` with the register address for `GPIO21` which is `IO_BANK0_BASE + 0x0A8`, because the `BOOT` button is connected to it. The `IO_BANK0_BASE` is defined in the SDK to `0x40014000`.
- We initilaize `GPIO21` is initialized in ***input*** mode in the `main` function.
- Then, in the `while` loop, the current value stored at the address `QTPY_BOOT_PIN_REG` is read using the `register_read` function and stored into a variable named
  `button_status`.
- We observed that the value in the register equals `0x00000000` when the button is pressed, so when the condition is met, the `neopixel` LED blinks.
- After that, the polling of the `BOOT` button and the condition check repeats indefinitely. 
- The `re_build.sh` file is a `bash` script that removes the exisiting `build` directory, and creates a new one. After that it navigates into it, and calls `cmake`,
  followed by `make`. This is a convinience script written to automate the build process.
