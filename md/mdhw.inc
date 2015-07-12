.equ ROM     0x000000
.equ ROM_LEN 0x400000

.equ RAM     0xFF0000
.equ RAM_LEN 0x010000

.equ MODEL 0xA10000
.equ TMSS  0xA14000

.equ PADDATA    0x00
.equ PADCTRL    0x06
.equ PADSERTX   0x0C
.equ PADSERRX   0x0E
.equ PADSERCTRL 0x10
.equ PAD1         0xA10002
  .equ PAD1_DATA    (PAD1 + PADDATA)
  .equ PAD1_CTRL    (PAD1 + PADCTRL)
  .equ PAD1_SERTX   (PAD1 + PADSERTX)
  .equ PAD1_SERRX   (PAD1 + PADSERRX)
  .equ PAD1_SERCTRL (PAD1 + PADSERCTRL)
.equ PAD2         0xA10004
  .equ PAD2_DATA    (PAD2 + PADDATA)
  .equ PAD2_CTRL    (PAD2 + PADCTRL)
  .equ PAD2_SERTX   (PAD2 + PADSERTX)
  .equ PAD2_SERRX   (PAD2 + PADSERRX)
  .equ PAD2_SERCTRL (PAD2 + PADSERCTRL)

.equ EXP         0xA10006
  .equ EXP_DATA    (EXP + 0x00)
  .equ EXP_CTRL    (EXP + 0x06)
  .equ EXP_SERTX   (EXP + 0x14)
  .equ EXP_SERRX   (EXP + 0x16)
  .equ EXP_SERCTRL (EXP + 0x18)

.equ MEMMODE 0xA11000

.equ VDP      0xC00000
  .equ VDP_DATA (VDP + 0x0)
  .equ VDP_CTRL (VDP + 0x4)
    .equ CTRL0      0x8000
      # horizontal blank interrupt enable (1: enable, 0: disable)
      .equ HBLANKEN 4
      # palette selection (1: full 3bit, 0: limited TODO what does "limited" mean?)
      .equ PALETTE  2
      # hv counter mode (1: latch value when interrupt asserted, 0: no latch)
      .equ HVMODE   1
      # vdp enable (1: enable vdp, 0: disable vdp)
      .equ VDPEN    0
    .equ CTRL1      0x8100
      # tms9918 mode enable (1: tms9918 compatibility mode, 0: normal mode)
      .equ TMSEN    7
      # display enable (1: enable all layers, 0: background color only)
      .equ DISPEN   6
      # vertical blank interrupt enable (1: enable, 0: disable)
      .equ VBLANKEN 5
      # dma enable (1: enable, 0: disable)
      .equ DMAEN    4
      # ntsc/pal signal output mode (1: pal, 0: ntsc)
      .equ PALEN    3
      # master system mode toggle TODO what is this? (1: toggle, 0: nothing)
      .equ SMSTGL   2
    .equ BGACTRL    0x8200
      # background A name table start address: 1111 1111  ___0 0000  0000 0000
      .equ BGAADDR      3
      .equ BGAADDR_MASK 0b111
    .equ WINCTRL    0x8300
      # window name table start address:       1111 1111  ____ _000  0000 0000
      .equ WINADDR      1
      .equ WINADDR_MASK 0b11111
    .equ BGBCTRL    0x8400
      # background B name table start address: 1111 1111  ___0 0000  0000 0000
      .equ BGBADDR      0
      .equ BGBADDR_MASK 0b111
    .equ SPRCTRL    0x8500
      # sprite attribute table start address:  1111 1111  ____ ___0  0000 0000
      .equ SPRADDR      0
      .equ SPRADDR_MASK 0b1111111
    .equ BDCTRL     0x8700
      # backdrop color palette
      .equ BDPAL        4
      .equ BDPAL_MASK   0b11
      # backdrop color
      .equ BDCOLOR      0
      .equ BDCOLOR_MASK 0b1111
    .equ HBLANKFREQ 0x8A00
      # number of horizontal blanks to skip before generating an interrupt
      .equ HBFREQ      0
      .equ HBFREQ_MASK 0b11111111
    .equ CTRL2      0x8B00
      # external TODO what does that mean? interrupt enable (1: enable, 0: disable)
      .equ EXTRNEN      3
      # vertical scrolling mode (1: 2 tile, 0: overall TODO what?)
      .equ VSCMODE      2
      # horizontal scrolling mode (3 or 1: per-scanline scrolling, 2: per-tile row scrolling, 0: per-background scrolling)
      .equ HSCMODE      0
      .equ HSCMODE_MASK 0b11
    .equ CTRL3      0x8C00
      # cell mode 40 or 32 columns? TODO what? (
      .equ WIDTH      0
      .equ WIDTH_MASK 0b10000001
      # shadow and highlight enable (1: enable, 0: disable)
      .equ SHADHI     3
      # interlace mode (3: double TODO vertical? resolution, 1: interlace, 0: TODO progressive scan?)
      .equ INLMD      1
      .equ INLMD_MASK 0b11
    .equ HSCTRL     0x8D00  
      # horizontal scroll table start address:  1111 1111  ____ __00  0000 0000
      .equ HSADDR      0
      .equ MSADDR_MASK 0b111111
    .equ CTRL4      0x8F00
      # vdp address auto-increment amount
      .equ VDPINC      0
      .equ VDPINC_MASK 0b11111111
  .equ VDP_HV   (VDP + 0x8)

.equ PSG_OUT 0xC00011

.equ Z80RAM     0xA00000
.equ Z80RAM_LEN 0x010000

.equ Z80_BREQ 0xA11100
.equ Z80_RST  0xA11200
