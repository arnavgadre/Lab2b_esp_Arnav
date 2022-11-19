# Protoboard

The following demonstration video shows the sequencer integrated along with the initial proposal board (that was used to play the game - guessing game).

<br>

https://user-images.githubusercontent.com/52575718/202834240-ea213229-e418-4842-94a0-947524854a6e.mp4

<br>

- Here, the guessing game proposed in the beginning of the lab was used, along with the `PIO` based sequencer that we created in the duration of the lab.
- There are various modes which can be activated using `macros`.
- The first macro, was `r`, which was used to record a sequence of `BOOT` pin presses.
- Secondly, `p` was used to play the recorded `BOOT` pin presses.
- Finally, the `g` macro was used to enter the *game* mode which activated the *guessing game*, where the user is asked to enter a number that would be
  considered as a `seed` to generate a random number.
- Based on the generated random number whose function can be found [here](https://github.com/Ruturajn/Lab2b-esp/blob/main/lab2b_parts/10_protoboard/ws2812.c#L37-L42).
- Then, the user is asked to enter a guess and based on whether the value entered is `higher` or `lower` than the random number generated, the user is prompted
  by printing `Think higher!!` or `Think Lower!!`.
- Until the user guesses the correct answer the `RED` LED blinks at each guess, once the user guesses the right answer the `BLUE` LED blinks, and the *game*
  mode is exited.
- The program then brings the user back to the beginning and waits for the user to enter a `macro`.
