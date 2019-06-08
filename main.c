/*******************************************************************************
*                   : TUSUR
* File              : main.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 13.05.2019
* 
* Author            : Popova Dariyana
* Support mail      : dariyana-mail.ru
* 
*
* Target MCU        : MCU: MDR1986
* Description       : Work with bits
*
********************************************************************************/

#define REG0_ADDR 0x20000000
#define REG0 *((volatile unsigned long *) (REG0_ADDR))

void set_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 1;
}

void reset_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 0;
}

static char bait = 0;

struct bitField{
  char flag_a : 1; char flag_b : 1;
  char flag_c : 1; char flag_d : 1;
  char flag_e : 1; char flag_f : 1;
  char flag_g : 1; char flag_h : 1;
} _bitField;

void main(void){
  // Work with Bit Field
  _bitField.flag_d = 1; _bitField.flag_c = 1; _bitField.flag_b = 1;// set 14 to field
  _bitField.flag_d = 0; _bitField.flag_c = 0; _bitField.flag_b = 0; // reset to 0
  // Work with Bit Banding
  set_bit(14); // Set 14th bit
  reset_bit(14); // Reset 14th bit
  // Handwork with bits
  bait |= (1<<2); bait |= (1<<3); bait |= (1<<1); // set 14 to var «bait»
  bait &=~(1<<2); bait &=~(1<<3); bait &=~(1<<1); // reset var «bait» to 0
  // Just for check
  bait ^= (1<<0); // (Now, bit 0th = 0) inversion 
  bait ^= (1<<0); // (Now, bit 0th = 1) inversion 
}