/* Arduino library: progmem_far.h
 *
 * Version: 1.0.0
 *
 * Copyright: Bernhard Nebel 2025
 *
 * This library is free software (MIT license). It provides 
 * the missing PROGMEM_FAR macro for Arduino. This macro
 * can be used to place constant data into flash at a memory 
 * location, where it is not interfering with data that needs to be 
 * located in the first 64k bytes of flash memory. You then 
 * have to use the macros pgm_read_byte_far, pgm_read_word_far, 
 * pgm_read_dward_far, pgm_read_float_near, pgm_read_ptr_far. 
 * The parameter to these macros is always a 32-bit address,
 * which can be determined by pgm_get_far_address. 
 *
 */

// We (ab-)use the linker section .fini0, the last section in the .text segment:
#define PROGMEM_FAR __attribute__((section (".fini0")))

// In order to make sure that after program termination, we end up in an
// infinite loop, we make use of the user-definable section .fini1.
void terminate(void) __attribute__((naked, section(".fini1"), used)); 
void terminate(void)
{
  while(1);
}

