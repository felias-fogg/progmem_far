# PROGMEM_FAR: The missing macro

Have you ever dealt with PROGMEM data that exceeded the 64kB limit? And then wondered, why did your program start to behave completely strangely? This (tiny) library provides a cure to that problem. 

Certain PROGMEM data needs to be necessarily located in the first 64kB of flash memory. This includes lookup tables for core functions such as digitalWrite and strings stored in flash memory. If you put too much data into flash memory, then lookup tables or strings might end up somewhere above the limit and cannot be accessed any longer by the ordinary library macros. This could mean that the LED no longer blinks or that the outputs appear garbled. 

If you have such a large amount of constant data, probably some of it does not need to be accessed by the ordinary library functions (the ones with the `_P` suffix), and it is enough to access them byte by byte (or word by word). For this purpose, the following macros exist in the `pgmspace.h` library:

- `pgm_get_far_address`(\<var\>) returns a 32-bit address of the variable \<var\> stored in flash, 
- `pgm_get_byte_far`(\<32-bit address\>) returns a byte value from the address given as the argument,
- `pgm_get_word_far`(\<32-bit address\>) returns a word value from the address given as the argument, etc.

However, is there a way to make sure that data is stored at the 'far' end of the flash memory so that it does not interfere with strings and lookup tables? In avr-libc, version 2.2.0, the macro `PROGMEM_FAR` is part of the library. However, the Arduino code base still uses version 2.0.0. This library helps out by providing the missing macro, which pushes PROGMEM data to locations that do not interfere with PROGMEM data that needs to reside in the first 64 kB. 

