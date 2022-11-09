# REGISTERS

The following demonstration video shows reading from a register directly. In this program the `neopixel` LED blinks, if the on-board `BOOT` button is pressed.

<div align='center'>
  <video src='https://user-images.githubusercontent.com/56625259/200098159-9cb6cdff-4dd3-42c3-b99d-4205c55e71ce.mp4'>
</div>

- The `QTPY_BOOT_PIN_REG` macro is defined with the register address for `GPIO21` which is `IO_BANK0_BASE + 0x0A8`, since the `BOOT` button is connected to it. The
  `IO_BANK0_BASE` is defined in the SDK to `0x40014000`.
- In the `main` function, `GPIO21` is initialized in ***input*** mode.
- Then, in the `while` loop, the current value stored at the address `QTPY_BOOT_PIN_REG` is read using the `register_read` function and stored into a variable named
  `button_status`.
- It is observed that the value in the register equals `0x00000000` when the button is pressed, so if that condition is met, the `neopixel` LED blinks.
- Then, the polling of the `BOOT` button and the condition check repeats indefinitely. 
- The `re_build.sh` file is a `bash` script that removes the exisiting `build` directory, and creates a new one. After that it navigates into it, and calls `cmake`,
  followed by `make`. This is a convinience script written to automate the build process.
