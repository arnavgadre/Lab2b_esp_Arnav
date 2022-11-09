# SEQUENCER HOST KEYS

This demonstration video shows, a sequence of `BOOT` button keypresses on the RP2040, recorded to the host (laptop) on a text file, and played on the `neopixel` LED,
by reading the file stored on the host.

https://user-images.githubusercontent.com/56625259/200099982-09bffb52-bebc-4565-a18f-ec3b253d7b94.mp4


- This program is divided into `2` parts, which work hand in hand to acheive the aforementioned behaviour.
- The first part is the `C` code running on the RP2040, and the second one is a python script named `rp2040_serial.py`, which utilizes the `pyserial` library to access
  the port on which the RP2040 is active.
- Firstly, the RP2040, prints the value of `wait_time` variable to the console during the recording is going on. This is read by the python script and written to a
  file on the host.
- Once, the recording is complete, the python script, reads the data stored in the text file, and writes it to the console, thereby acting as user input to the RP2040.
- Based on this data (wait time, i.e. the amount of time for which the LED should sleep before blinking again), the `neopixel` LED blinks.
- The overall process (i.e. the C code) is very similar to the one explained in the [previous part](https://github.com/Ruturajn/Lab2b-esp/tree/main/lab2b_parts/03_sequencer/sequencer_device_keys).
- Following, is a screenshot of the recorded data on the host.


![image](https://user-images.githubusercontent.com/56625259/200099870-8fcbb092-187b-4050-bef4-5c5e0ee715bf.png)
