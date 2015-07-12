SECTIONS {
	/* code needs to be loaded starting at 0x000000 */
	.text : {
		/* 68000 vector entries */
		. = 0x000000;
		md/vectors.o (.text);

		/* mega drive rom header */
		. = 0x000100;
		md/romheader.o (.text);

		/* any other code */
		. = 0x000200;
		* (.text);
	}

	/* initialized data can be loaded wherever */
	.data : {
		* (.data);
	}

	/* uninitilized data can be loaded wherever */
	.bss : {
		* (.bss);
	}
}
