  # make tmss happy so we can use the vdp
  move.b 0xA10001, d0
  andi.b #0x0F, d0
  beq.b  skiptmss
  move.l #0x53454741, 0xA14000
skiptmss:
