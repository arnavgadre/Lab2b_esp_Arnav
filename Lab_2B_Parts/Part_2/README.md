# REPL

This is the demonstration video which shows the reading from and the writing to a register directly. Atomic-bit setting is also seen.

<div align='center'>
  <video src='https://user-images.githubusercontent.com/52575718/200742152-cd76193f-a5cb-40d7-aa61-c02835755ac7.mp4'>
</div>

- The `QTPY_GPIO0_REG` macro is defined with the register address for `GPIO0` which is `IO_BANK0_BASE + 0x004`, since the `BOOT` button is connected to it. The
  `IO_BANK0_BASE` is defined in the SDK to `0x40014000`.
- The `GPIO0` is initialized in ***input*** mode in the `main` code.
- After that, in the `while` loop, the current value stored at the address `QTPY_GPIO0_REG` is read using the `register_read` function and stored into a variable named
  `reg_status`.
- Now the user is prompted for an input, which will be written to the `QTPY_GPIO0_REG` register using the `register_write` function.
- Once, this is done, the updated register value is printed out onto the console.
- After that, the user is prompted for an input again. The input is ANDed with the current value stored in the `QTPY_GPIO0_REG` register, and the result
  of that operation is written to `QTPY_GPIO0_REG`.
- In the end, the updated value is printed out on the console.
- The `re_build.sh` file is a `bash` script that removes the exisiting `build` directory, and creates a new one. After that it navigates into it, and calls `cmake`,
  followed by `make`. This is a convinience script written to automate the build process.
