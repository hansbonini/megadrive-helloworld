#ifndef __IO_H
#define __IO_H

//rom memory locations
.equ ROM,     0x000000
.equ ROM_LEN, 0x400000



//68k ram memory locations
.equ RAM,     0xFF0000
.equ RAM_LEN, 0x010000



//vdp security register locations
.equ MODEL, 0xA10000
.equ TMSS,  0xA14000
  //key that unlocks the vdp (ascii for "SEGA")
  .equ TMSS_UNLOCK, 0x53454741



//gamepad register locations
.equ PADDATA,    0x00
.equ PADCTRL,    0x06
.equ PADSERTX,   0x0C
.equ PADSERRX,   0x0E
.equ PADSERCTRL, 0x10
.equ PAD1, 0xA10002
  .equ PAD1_DATA,    (PAD1 + PADDATA)
  .equ PAD1_CTRL,    (PAD1 + PADCTRL)
  .equ PAD1_SERTX,   (PAD1 + PADSERTX)
  .equ PAD1_SERRX,   (PAD1 + PADSERRX)
  .equ PAD1_SERCTRL, (PAD1 + PADSERCTRL)
.equ PAD2, 0xA10004
  .equ PAD2_DATA,    (PAD2 + PADDATA)
  .equ PAD2_CTRL,    (PAD2 + PADCTRL)
  .equ PAD2_SERTX,   (PAD2 + PADSERTX)
  .equ PAD2_SERRX,   (PAD2 + PADSERRX)
  .equ PAD2_SERCTRL, (PAD2 + PADSERCTRL)



//expansion port register locations
.equ EXP, 0xA10006
  .equ EXP_DATA,    (EXP + 0x00)
  .equ EXP_CTRL,    (EXP + 0x06)
  .equ EXP_SERTX,   (EXP + 0x14)
  .equ EXP_SERRX,   (EXP + 0x16)
  .equ EXP_SERCTRL, (EXP + 0x18)



.equ MEMMODE, 0xA11000



//vdp register locations
.equ VDP, 0xC00000
  .equ VDP_DATA, (VDP + 0x0)
  .equ VDP_CTRL, (VDP + 0x4)
    //vdp command generator
    #define VDP_CMD(cmd, data) ((0x8000+((cmd)<<8)) | (data))

    //horizontal blank interrupt enable (1: enable, 0: disable)
    #define VDP_CMD0_HBLANK_ENABLE(hblank_enable) VDP_CMD(0x00, (((hblank_enable)&0b1)<<4))

    //palette selection (1: full 3bit, 0: limited TODO what does "limited" mean?)
    #define VDP_CMD0_PALETTE_SELECT(palette_select) VDP_CMD(0x00, (((palette_select)&0b1)<<2))

    //hv counter mode (1: latch value when interrupt asserted, 0: no latch)
    #define VDP_CMD0_HVCOUNTER_MODE(hvcounter_mode) VDP_CMD(0x00, (((hvcounter_mode)&0b1)<<1))

    //vdp enable (1: enable vdp, 0: disable vdp)
    #define VDP_CMD0_VDP_ENABLE(vdp_enable) VDP_CMD(0x00, (((vdp_enable)&0b1)<<0))

    //all CMD0 commands
    #define VDP_CMD0(hblank_enable, palette_select, hvcounter_mode, vdp_enable) \
            ( VDP_CMD0_HBLANK_ENABLE(hblank_enable) \
            | VDP_CMD0_PALETTE_SELECT(palette_select) \
            | VDP_CMD0_HVCOUNTER_MODE(hvcounter_mode) \
            | VDP_CMD0_VDP_ENABLE(vdp_enable) )

    //tms9918 mode (1: tms9918 compatibility mode, 0: normal mode)
    #define VDP_CMD1_TMS9918_MODE(tms9918_mode) VDP_CMD(0x01, (((tms9918_mode)&0b1)<<7))

    //display enable (1: enable all layers, 0: background color only)
    #define VDP_CMD1_DISPLAY_ENABLE(display_enable) VDP_CMD(0x01, (((display_enable)&0b1)<<6))

    //vertical blank interrupt enable (1: enable, 0: disable)
    #define VDP_CMD1_VBLANK_ENABLE(vblank_enable) VDP_CMD(0x01, (((vblank_enable)&0b1)<<5))

    //dma enable (1: enable, 0: disable)
    #define VDP_CMD1_DMA_ENABLE(dma_enable) VDP_CMD(0x01, (((dma_enable)&0b1)<<4))

    //ntsc/pal signal output mode (1: pal, 0: ntsc)
    #define VDP_CMD1_PAL_MODE(pal_mode) VDP_CMD(0x01, (((pal_mode)&0b1)<<3))

    //master system mode toggle TODO what is this? (1: toggle, 0: nothing)
    #define VDP_CMD1_SMS_MODE(sms_mode) VDP_CMD(0x01, (((sms_toggle)&0b1)<<2))

    //all CMD1 commands
    #define VDP_CMD1(tms9918_mode, display_enable, vblank_enable, dma_enable, pal_mode, sms_mode) \
            ( VDP_CMD1_TMS9918_MODE(tms9918_mode) \
            | VDP_CMD1_DISPLAY_ENABLE(display_enable) \
            | VDP_CMD1_VBLANK_ENABLE(vblank_enable) \
            | VDP_CMD1_DMA_ENABLE(dma_enable) \
            | VDP_CMD1_PAL_MODE(pal_mode) \
            | VDP_CMD1_SMS_MODE(sms_mode) )

    //background A name table vram start address: ___0 0000  0000 0000
    #define VDP_CMD2(background_a_table_address) \
            ( (VDP_CMD(0x02)) | ((((background_a_table_address)>>13)&0b111)<<3) )

    //window name table vram start address: ____ _000  0000 0000
    #define VDP_CMD3(window_table_address) \
            ( (VDP_CMD(0x03)) | ((((window_table_address)>>11)&0b11111)<<1) )

    //background B name table vram start address: ___0 0000  0000 0000
    #define VDP_CMD4(background_b_table_address) \
            ( (VDP_CMD(0x04)) | ((((background_b_table_address)>>13)&0b111)<<0) )

    //sprite attribute table vram start address:  ____ ___0  0000 0000
    #define VDP_CMD5(sprite_attribute_table_address) \
            ( (VDP_CMD(0x05)) | ((((sprite_attribute_table_address)>>9)&0b1111111)<<0) )

    //backdrop color palette
    //backdrop color
    #define VDP_CMD7(backdrop_color_palette, backdrop_color) \
            ( (VDP_CMD(0x07)) | (((backdrop_color_palette)&0b11)<<4) \
                              | (((backdrop_color)&0b1111)<<0) )

    //number of horizontal blanks to skip before generating an interrupt
    #define VDP_CMD10(hblanks_skipped) \
            ( (VDP_CMD(0x0A)) | (((hblanks_skipped)&0b11111111)<<0) )

    //external TODO what does that mean? interrupt enable (1: enable, 0: disable)
    //vertical scrolling mode (1: 2 tile, 0: overall TODO what?)
    //horizontal scrolling mode (3 or 1: per-scanline scrolling, 2: per-tile row scrolling, 0: per-background scrolling)
    #define VDP_CMD11(external_interrupt_enable, vertical_scroll_mode, horizontal_scroll_mode) \
            ( (VDP_CMD(0x0B)) | (((external_interrupt_enable)&0b1)<<3) \
                              | (((vertical_scroll_mode)&0b1)<<2) \
                              | (((horizontal_scroll_mode)&0b11)<<0) )

    //cell mode (1: 40 columns, 0: 32 columns)
    //shadow and highlight enable (1: enable, 0: disable)
    //interlace mode (3: double TODO vertical? resolution, 1: interlace, 0: TODO progressive scan?)
    #define VDP_CMD12(cell_mode, shadow_highlight_enable, interlace_mode) \
            ( (VDP_CMD(0x0C)) | (((cell_mode)&0b1)<<7) | (((cell_mode)&0b1)<<0) \
                              | (((shadow_highlight_enable)&0b1)<<3) \
                              | (((interlace_mode)&0b11)<<1) )

    //horizontal scroll table start address: ____ __00  0000 0000
    #define VDP_CMD13(horizontal_scroll_table) \
            ( (VDP_CMD(0x0D)) | ((((horizontal_scroll_table)>>10)&0b111111)<<0) )

    //vdp address auto increment amount
    #define VDP_CMD15(vdp_address_increment) \
            ( (VDP_CMD(0x0F)) | (((vdp_address_increment)&0b11111111)<<0) )

  .equ VDP_HV,   (VDP + 0x8)

  //color ram
  #define RGB(r, g, b) ((((r)&0b111)<<9) | (((g)&0b111)<<5) | (((b)&0b111)<<1))



.equ PSG_OUT, 0xC00011



.equ Z80RAM,     0xA00000
.equ Z80RAM_LEN, 0x010000

.equ Z80_BREQ, 0xA11100
.equ Z80_RST,  0xA11200

#endif
