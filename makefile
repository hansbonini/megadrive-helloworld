# source files to assemble
ASM := main.S
# name of the rom file
ROM := rom.bin

# tool definitions
PREFIX := m68k-none-elf
ASFLAGS := -m68000 \
           -mno-68881 -mno-68882 -mno-68851 \
	   --warn \
	   --keep-locals \
	   --register-prefix-optional --bitwise-or
AS := $(PREFIX)-as $(ASFLAGS)
LDFLAGS := -O1 \
           -static -nostdlib
LD := $(PREFIX)-ld $(LDFLAGS)
OBJCOPY := $(PREFIX)-objcopy --output-target=binary
OBJDUMP-ELF := $(PREFIX)-objdump -D
OBJDUMP-BIN := $(PREFIX)-objdump -m m68k -b binary --adjust-vma=0x000000 --start-address=0x000200 -D
OD := od -A x -t x1z -v
RM := rm -rf

S := md/vectors.S md/romheader.S $(ASM) md/romfooter.S
O := $(S:.S=.o)
ELF := $(ROM:.bin=.elf)

# default target to build the rom
.PHONY: all
all: $(ROM)

# target for building .o files from .S files
%.o: %.S
	$(AS) $< -o $@

# target for building the elf binary
$(ELF): $(O) md/romlayout.lds
	$(LD) -T md/romlayout.lds $(O) -o $(ELF)

# target for building the rom binary
$(ROM): $(ELF)
	$(OBJCOPY) $(ELF) $(ROM)

# target for dumping the elf binary
.PHONY: dump
dump: $(ELF)
	$(OBJDUMP-ELF) $(ELF)

# target for dumping the flat binary
.PHONY: mddump
mddump: $(ROM)
	$(OBJDUMP-BIN) $(ROM)

# target for hex dumping the flat binary
.PHONY: hexdump
hexdump: $(ROM)
	$(OD) $(ROM)

# target for cleaning up intermediate generated files
.PHONY: clean
clean:
	$(RM) $(O) $(ELF)

# target for cleaning up all generated files
.PHONY: realclean
realclean: clean
	$(RM) $(ROM)
