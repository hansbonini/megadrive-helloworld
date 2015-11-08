//NOTE: all the .org directives use relative addressing
//      the linker should write this data to the rom starting at 0x000100

//required for tmss
.org 0x000000
.ascii "SEGA"
.org 0x000004, ' '
//console name ("MEGA DRIVE"=normal megadrive, "SSF"=use mega everdrive expansion)
.org 0x000004
.ascii " "  //this is required when using ssf
.ascii "SSF"
.org 0x000010, ' '
//company name
.org 0x000010
.ascii "(C)"
.ascii "BEEF"
.org 0x000017, ' '
//build year
.org 0x000017
.ascii " "
.ascii "9999"
.org 0x00001C, ' '
//build month
.org 0x00001C
.ascii "."
.ascii "JAN"
.org 0x000020, ' '
//domestic software name
.org 0x000020
.ascii "DOMESTIC NAME"
.org 0x000050, ' '
//international software name
.org 0x000050
.ascii "INTERNATIONAL NAME"
.org 0x000080, ' '
//program type (GM=game, AL=educational), serial number, version number
.org 0x000080
.ascii "GM"
.org 0x000082, ' '
//program serial number
.org 0x000082
.ascii " "
.ascii "99999999"
.org 0x00008B, '0'
//program version number
.org 0x00008B
.ascii "-"
.ascii "99"
.org   0x00008E, '0'
//checksum (not checked by console)
.org   0x00008E
.short 0xFFFF
.org   0x000090, 0
//???
.org   0x000090
.ascii "J"
.org   0x0000A0, ' '
//rom start
.org   0x0000A0
.long  0x000000
.org   0x0000A4, 0
//rom end
.org   0x0000A4
.long  ROMEND
.org   0x0000A8, 0
//ram start
.org   0x0000A8
.long  0xFF0000
.org   0x0000AC, 0
//ram end
.org   0x0000AC
.long  0xFFFFFF
.org   0x0000B0, 0
//???
.org   0x0000B0
.org   0x0000F0, ' '
//regions supported (J=japan, U=usa, E=europe)
.org   0x0000F0
.ascii "JUE"
.org   0x000100, ' '
