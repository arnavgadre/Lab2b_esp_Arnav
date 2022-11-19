# PIO Sequencer:

This is a demonstration video for the PIO Sequencer using the PIO module.

<br>

https://user-images.githubusercontent.com/52575718/202828011-6a75a256-88ae-48dd-b580-0e804d04060c.mp4

<br>

- This code utilizes the `PIO` module to monitor the `BOOT` button presses.
- The `.pio` assembly file was updated to poll the `BOOT` pin (GPIO21) of the `RP2040`.
- Here, the in directive in the pio assembly language was used to shift the value read from the BOOT pin into the ISR.
- Once, the value was written to the `ISR`, it needed to be pushed to the `RX FIFO` of the `SM`.
- We did this by enabling the autopush functionality with a very low threshold, since we only needed to read the value for a single pin.
- After the data was pushed into the `RX FIFO`, the `pio_sm_get` function (defined in the SDK) was used in the C code to access the data read from the pin.
- Recording is created based on this data.
- The protocol for recording and replaying the data is similar to the one explained in Part 3 - Sequencer host keys macros.
- Note that the python serial library was also used here, for storing the recorded sequence on to the host, and then reading it to replay the sequence on the RP2040.
- The `re_build.sh` file is a bash script that removes the exisiting build directory, and creates a new one. After that it navigates into it, and calls `cmake`, followed by make. This is a convinience script written to automate the build process.
- Also, following is a screenshot of the recorded sequence that was stored in the text file on the host.

<br>

![image](https://user-images.githubusercontent.com/52575718/202827845-9cedf4c5-1adc-4578-9d43-c5387daec4c8.png)

