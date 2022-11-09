# REPL

The following demonstration video shows reading from and writing to a register directly. Atomic-bit setting can also be seen.

<div align='center'>
  <video src='https://user-images.githubusercontent.com/56625259/200098701-47202c52-a8ca-426d-9a1c-b52858556510.mp4'>
</div>

- The `QTPY_GPIO0_REG` macro is defined with the register address for `GPIO0` which is `IO_BANK0_BASE + 0x004`, since the `BOOT` button is connected to it. The
  `IO_BANK0_BASE` is defined in the SDK to `0x40014000`.
- In the `main` function, `GPIO0` is initialized in ***input*** mode.
- Then, in the `while` loop, the current value stored at the address `QTPY_GPIO0_REG` is read using the `register_read` function and stored into a variable named
  `reg_status`.
- After that the user is prompted for an input, which will be written to the `QTPY_GPIO0_REG` register using the `register_write` function.
- Once, this is done, the updated register value is printed out onto the console.
- Then, the user is prompted for an input again. This time, the input is ANDed with the current value stored in the `QTPY_GPIO0_REG` register, and the result
  of that operation is written to `QTPY_GPIO0_REG`.
- Finally, the updated value is printed out to the console again.
- The `re_build.sh` file is a `bash` script that removes the exisiting `build` directory, and creates a new one. After that it navigates into it, and calls `cmake`,
  followed by `make`. This is a convinience script written to automate the build process.
