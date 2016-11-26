#include "md/io.h"
#include "md/mem.h"
#include "md/ssf.h"

  // make tmss happy so we can use the vdp
  move.b (MODEL + 1), d0
  andi.b #0x0F, d0
  beq.b  skiptmss
  move.l #TMSS_UNLOCK, TMSS
skiptmss:

init:
  // clear 68k RAM without having to use SP (because it's not initialized yet)
  move.l #RAM, a0          
  move.l #RAM_END, a1
  mem_clear_l_macro a0, a1

  // initialize SP (SP pre-decrements, so even though RAM_END is outside RAM bounds, we're still OK)
  move.l #RAM_END, sp

ready:
  // turn the mega everdrive led on
  move.w #MAPPER_CMD(0, 0, 1, 0), MAPPER_CONTROL

  // junk up 68k RAM
  move.l #RAM, a0
  move.l #(RAM+0x10), a1
  move.l #0xBEEFCAFE, d0
  jsr mem_set_l

  // clear Z80 RAM
  move.l #Z80RAM, a0
  move.l #Z80RAM_END, a1
  jsr mem_clear_l

  // loop forever
nothing:
  bra nothing

