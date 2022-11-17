# Slow Motion

In this demonstration, a series of keystrokes from the `RP2040`'s `BOOT` button are recorded to the host computer's text file and played on the `Neopixel LED` by reading the file from the host. Encoding macros to do operations like recording a sequence (to the host) or playing it (on the RP2040) in fast-forward or slow-motion allows for the completion of this action.

<br>

https://user-images.githubusercontent.com/52575718/202341662-b0c4be22-3702-4bd8-b09c-0ffb2bd476fb.mp4

<br>

- This code simply extends the functionality of the `Part 3` by adding a few extra lines, allowing the user to replay the tape in either fast-forward or slow motion.
- A `fast-forward` or `slow-motion` effect is produced by adjusting the `wait_time` variable to achieve this behavior. In other words, the `CONST_TIME_SCALING_FACTOR` variable, by which the `wait_time` is multiplied, is decreased for the fast-forward option. However, the value of the `CONST_TIME_SCALING_FACTOR` variable is raised for the slow motion mode.
- By altering the `wait_time` the code acheives a good emulation of replaying a sequence in fast-forward and slow-motion mode.
- A bash script called `re_build.sh` deletes the old build directory and starts a new one. It then enters it and executes the commands `make`, `cmake`, and so forth. This script was created as a convenience to automate the building procedure.
- I have pasted the screenshot of the recorded sequence that was stored in the text file in the host.

<br>

![image](https://user-images.githubusercontent.com/52575718/202342587-1fcc6caa-acf5-4143-a007-138434c351fb.png)
