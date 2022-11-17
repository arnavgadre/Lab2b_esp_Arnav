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



