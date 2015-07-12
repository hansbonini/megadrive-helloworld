# header start
.org   0x000000, 0
# console name
.ascii "SEGA MEGA DRIVE"
.org   0x000010, ' '
# company name and build date
.ascii "(C)BEEF 9999.JAN"
.org   0x000020, ' '
# domestic software name
.ascii "DOMESTIC NAME"
.org   0x000050, ' '
# international software name
.ascii "INTERNATIONAL NAME"
.org   0x000080, ' '
# software type (GM=game, AL=educational), serial number, version number
.ascii "GM 99999999-99"
.org   0x00008E, ' '
# checksum (not checked by console)
.short 0xFFFF
.org   0x000090, 0
# ???
.ascii "J"
.org   0x0000A0, ' '
# rom start
.long  0x000000
.org   0x0000A4, 0
# rom end
.long  ROMEND
.org   0x0000A8, 0
# ram start
.long  0xFF0000
.org   0x0000AC, 0
# ram end
.long  0xFFFFFF
.org   0x0000B0, 0
# ???
.org   0x0000F0, ' '
# regions supported (J=japan, U=usa, E=europe)
.ascii "JUE"
.org   0x000100, ' '
