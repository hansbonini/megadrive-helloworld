// clear memory in long (4byte) chunks
//   \a_start - the address register containing starting address
//   \a_end   - the address register containing ending address
.macro mem_clear_l_macro a_start:req, a_end:req
  mem_clear_l_loop\@:
    clr.l (\a_start)+
    cmpa.l \a_end, \a_start
    blt mem_clear_l_loop\@
.endm

// set memory in long (4byte) chunks
//   \a_start - the address register containing starting address
//   \a_end   - the address register containing ending address
//   \d_value - the data register containing the value
.macro mem_set_l_macro a_start:req, a_end:req, d_value:req
  mem_set_l_loop\@:
    move.l \d_value, (\a_start)+
    cmpa.l \a_end, \a_start
    blt mem_set_l_loop\@
.endm

