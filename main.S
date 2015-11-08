#include "md/io.h"
#include "md/ssf.h"

  //make tmss happy so we can use the vdp
  move.b (MODEL + 1), d0
  andi.b #0x0F, d0
  beq.b  skiptmss
  move.l #TMSS_UNLOCK, TMSS
skiptmss:

  //turn the mega everdrive led on
  move.w #MAPPER_CMD(0, 0, 1, 0), MAPPER_CONTROL
