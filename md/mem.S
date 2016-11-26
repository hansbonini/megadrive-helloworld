#include "mem.h"

// clear memory in long (4byte) chunks
//   a0 - the starting address
//   a1 - the ending address
.global mem_clear_l
mem_clear_l:
  mem_clear_l_macro a0, a1
  rts

// set memory in long (4byte) chunks
//   a0 - the starting address
//   a1 - the ending address
//   d0 - the value
.global mem_set_l
mem_set_l:
  mem_set_l_macro a0, a1, d0
  rts

