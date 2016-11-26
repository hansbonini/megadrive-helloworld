# source files to assemble
ASM = main.S
# name of the rom file
ROM = rom.bin

S_CPP = md/vectors.S md/romheader.S $(ASM) md/romfooter.S
O = $(S_CPP:.S=.o)
ELF = $(ROM:.bin=.elf)

# tool definitions
ARCH := m68k
PREFIX := $(ARCH)-none-elf

MAKE = make
CPP = cpp \
  -Wall -Wcomment -Wundef \
  -x assembler-with-cpp \
  -nostdinc \
  $(CPP_DEBUGFLAGS)
AS = $(PREFIX)-as \
  -m68000 \
  -mno-68881 -mno-68882 -mno-68851 \
  --warn \
  --keep-locals \
  --register-prefix-optional --bitwise-or \
  $(AS_DEBUGFLAGS)
LD = $(PREFIX)-ld \
  -O1 \
  -static -nostdlib
OBJCOPY = $(PREFIX)-objcopy \
  --output-target=binary
DGEN = dgen
OBJDUMP = $(PREFIX)-objdump \
  --disassemble \
  --start-address=0x000200 --adjust-vma=0x000000 \
  --source --line-numbers --debugging --stabs \
  --wide
OBJDUMP-ELF = $(OBJDUMP) \
  --target=elf32-m68k
OBJDUMP-BIN = $(OBJDUMP) \
  --target=binary \
  --architecture=$(ARCH)
OD = od \
  --address-radix=x \
  --format=x1z --output-duplicates
RM = rm -rf

# default target to build the rom
.PHONY: all
all: $(ROM)

# build the default target with debugging options enabled
.PHONY: debug
debug:
	$(MAKE) AS_DEBUGFLAGS="-g" CPP_DEBUGFLAGS="-D DEBUG"

# run the ROM binary in an emulator
.PHONY: run
run: $(ROM)
	$(info press ` to enter debugger)
	$(DGEN) $<

# target for dumping the elf binary
.PHONY: dumpelf
dumpelf: $(ELF)
	$(OBJDUMP-ELF) $<

# target for dumping the flat binary
.PHONY: dumpbin
dumpbin: $(ROM)
	$(OBJDUMP-BIN) $<

# target for hex dumping the flat binary
.PHONY: dumphex
dumphex: $(ROM)
	$(OD) $<

# target for cleaning up intermediate generated files
.PHONY: clean
clean:
	$(RM) $(O) $(ELF)

# target for cleaning up all generated files
.PHONY: realclean
realclean: clean
	$(RM) $(ROM)

# target for building .o files from .S files
%.o: %.S
	$(CPP) $< | $(AS) - -o $@

# target for building .o files from .s files
%.o: %.s
	$(AS) $< -o $@

# target for building the elf binary
$(ELF): $(O) md/romlayout.lds
	$(LD) -T md/romlayout.lds $(O) -o $(ELF)

# target for building the rom binary
$(ROM): $(ELF)
	$(OBJCOPY) $< $@

