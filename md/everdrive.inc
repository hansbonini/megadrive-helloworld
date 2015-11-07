# 16bit and 32bit math coprocessor registers
# use this procedure:
#   1. write value to MATH_ARG
#   2. write value to MATH_MUL or MATH_DIV
#   3. read result from MATH_ARG
.equ MATH 0xA130D0
  # first value when multiplying, numerator when dividing (TODO confirm)
  .equ MATH_ARG_HI (MATH + 0x0)
  .equ MATH_ARG_LO (MATH + 0x2)
  # second value when multiplying, writes to _LO trigger computation (TODO confirm)
  # write only
  .equ MATH_MUL_HI (MATH + 0x4)
  .equ MATH_MUL_LO (MATH + 0x6)
  # denominator when dividing, writes to _LO trigger computation (TODO confirm)
  # write only
  .equ MATH_DIV_HI (MATH + 0x8)
  .equ MATH_DIV_LO (MATH + 0xA)

# sd card access registers
.equ SD 0xA130E0
  .equ SD_DATA    (SD + 0x0)
  # sd card status
  # read only
  # shared with usb uart status
  .equ SD_STATUS  0xA130E4
  # sd card control
  # write only
  .equ SD_CONTROL 0xA130E6

# usb uart access registers
.equ USB 0xA130E2
  # read a value from this address to pull a value off the read fifo
  # write a value to this address to push a value into the write fifo
  .equ USB_DATA   (USB + 0x0)
    .equ USB_DATA_MASK 0b11111111
  # usb uart status
  # read only
  # shared with sd card status
  .equ USB_STATUS 0xA130E4

# ssf mapper registers
# in order for this to be enabled, the console name in the rom header must be "SEGA SSF"
# the first 32KiB of bank 28 will be written to the sd card as save data (TODO only of written to?)
# WARNING: banks 30 and 31 are where the firmware is loaded when the console's power switch is turned on
#          overwriting these will break:
#            - in-game menu
#            - pressing the console's reset button to get back to the main menu
#          if these banks are accidentally overwritten, just switch the console off and back on again
.equ MAPPER 0xA130F0
  .equ MAPPER_CONTROL (MAPPER + 0x0)
  .equ MAPPER_BANK0   (MAPPER + 0x2)
  .equ MAPPER_BANK1   (MAPPER + 0x4)
  .equ MAPPER_BANK2   (MAPPER + 0x6)
  .equ MAPPER_BANK3   (MAPPER + 0x8)
  .equ MAPPER_BANK4   (MAPPER + 0xA)
  .equ MAPPER_BANK5   (MAPPER + 0xC)
  .equ MAPPER_BANK6   (MAPPER + 0xE)
    .equ MAPPER_BANK_MASK 0b11111


