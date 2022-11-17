# SEQUENCER

This directory houses 3 separate directories that implement the various sections in the `03_sequencer` part of LAB-2b.
I have provided the descriptions of all the 3 parts in this ReadMe itself.

## 1) Sequencer Device Keys:

<br>

https://user-images.githubusercontent.com/52575718/202324727-3aaf3f96-6c03-440f-8383-2cd51ec257db.mp4

<br>

- Here, the user is prompted to use 5 keypresses to record a sequence to the RP2040.
- Since the BOOT button is attached to  GPIO21  , which has the register address `IO ANK0 BASE + 0x0A8` is where the macro "QTPY BOOT PIN REG" is defined. The SDK defines the `IO BANK0 BASE` as `0x40014000`.
- In the main function, GPIO21 is initialized in input mode.
- Then, in the while loop, the current value stored at the address QTPY_BOOT_PIN_REG is read using the register_read function.
- The while loop above is nested inside of another one, which continues to execute until 5 user keystrokes have been captured. When a key press is recognized (when the value in the `QTPY BOOT PIN REG change`s to 0), the `wait_time` counter is updated. The counter is reset to 0 once a keypress is detected, and its value is saved in the `wait_time_arr array`. The idx variable, which counts the amount of keystrokes made by the user, is also updated.
- The sequence is encoded as the amount of time between two consecutive keypresses. This is stored in an array named wait_time_arr.
- A for loop that iterates over the `wait_time_arr` array and uses the `sleep_ms` function to wait according to the value in the array at that iteration is used to play back a sequence that the user has previously recorded. Using this, we may replay a sequence.
- The `re_build.sh` file is a bash script that removes the exisiting build directory, and creates a new one. After that it navigates into it, and calls `cmake`, followed by make. This is a convinience script written to automate the build process.

<br>

## 2) Sequencer Host Keys:

In this demonstration, a series of keystrokes from the RP2040's `BOOT` button are recorded to the host computer's text file and played on the Neopixel LED by reading the file from the host.

<br>

https://user-images.githubusercontent.com/52575718/202327135-c4e8d7b4-b6f5-43b4-9d83-0f4ce3f31624.mp4

<br> 

- There are 2 parts to this code. The RP2040's C code makes up the first part, and the second is a Python script called `rp2040 serial.py` that uses the `pyserial` package to access the port where the RP2040 is now active.
- First, while the recording is taking place, the RP2040 publishes the value of the `wait_time` variable to the console. The Python script reads this and writes it to a file on the host.
- The python script retrieves the data from the text file after the recording is finished and writes it to the console, acting as user input to the RP2040.
- Based on this data (wait time, i.e. the amount of time for which the LED should sleep before blinking again), the neopixel LED blinks.
- I have pasted a screenshot of the recorded data on the host.

<br>

![image](https://user-images.githubusercontent.com/52575718/202328147-a41baf97-8b7b-46b0-9f5d-72abcf775fbc.png)

<br>

## 3) Sequencer Host Keys Macros

In this demonstration, a series of keystrokes from the RP2040's BOOT button are recorded to the host computer's text file and played on the neopixel LED by reading the file from the host. Encoding macros to do actions like recording a sequence (to the host) or playing it allows for this operation (on the RP2040).

<br>

https://user-images.githubusercontent.com/52575718/202329608-325c248a-7ace-47d4-afda-a8327a2e4fe2.mp4

- This program too has 2 parts to it. The RP2040's C code is one of them, and the host's rp2040 `serial macros.py` script is the other. The host script communicates with the RP2040 via the established serial connection.

For the `C` code:
- The timing between two consecutive key presses, or wait time, is used to encode the sequence of `BOOT` button presses. An integer counter variable is used for this.
- According to the datasheet, the variables `QTPY_BOOT_PIN_NUM` and `QTPY_BOOT_PIN_REG` are initially set to 21 and ((`volatile_uint32_t*`)(`IO_BANK0_BASE + 0x0A8`)) accordingly. Additionally, the QtPy's `BOOT` pin is set up to operate in `INPUT` mode.
- Since the python script is accessing the serial communication, the code technically waits for "user input" in the main while loop. Once the "user input" is received, the code checks to see if the input was `r`; if so, it begins recording/monitoring wait time until the `BOOT` button is pressed five times. Using the previously defined address of the `QTPY_BOOT_PIN_REG` register, the status of the `BOOT` button is polled.
- Once this is done, the code jumps to the beginning of the while loop and waits for the "user input" again.
- Now, if the "user input" is `p`, the code takes a different branch, which is responsible for playing the sequence on the `Neopixel LED`.
- In this scenario, the number of times the LED needs to blink is kept track of using a counter called `idx` (which is 5 in this case). Every time the LED blinks, this counter is updated (or, to be more precise, decremented).
- The while loop is activated and continues until `idx > 0`. The code waits for the data or the wait time to be gathered during the loop. Since it is the Python script that accesses the serial transmission, it also provides this. The `neopixel` is made to blink once the wait time is received, and the `RP2040` waits till the wait time (as the name suggests). This continues until the while loop's condition is not met, at which point the code switches to the main while loop.

For the `Python` script:
- The python script now includes the macro that the user wants to transmit to the `RP2040`, which is where the user enters the command. `R` and `P`, which stand for `play` and `record`, respectively, are the available alternatives.
- Here the `pySerial` library is used to access the `COM` port that the RP2040 is connected to.
- Firstly, an object of the serial class is configured with the right `COM` port number and baudrate. An indefinite while loop is run to get user input (which is the macro) and perform actions accordingly.
- In the event that the user pushed the `r` key, Python begins reading and storing the `wait_time` that is being sent to the host (or printed into the `tty` by the `RP2040`) in a text file up until the user presses the single `\n` key. This means that a total of `5` keystrokes were captured, and the text file is now closed.
- The code then skips back to the start of the `while` loop and waits for user input. The code now starts delivering data (which is wait time) to the `RP2040` by reading values from the text file that was saved on the host when the `p` key is pushed. The code continues to examine the `tty`'s output as it performs this in order to see if it ever sees the word `Complete`, which denotes that the play operation is complete. After completing this, the code starts over at the beginning and waits for the user's input.
- A bash script called `re_build.sh` deletes the old build directory and starts a new one. It then enters it and executes the commands `make`, `cmake`, and so forth. This script was created as a convenience to automate the building procedure.
- I have pasted a screenshot of the recorded sequence that was stored in the file next to the host.

<br>

![image](https://user-images.githubusercontent.com/52575718/202332743-7d82bc7b-9867-45e3-8aaf-87abd1388b7d.png)
