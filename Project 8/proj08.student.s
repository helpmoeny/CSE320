		.global main
		.section ".text"
		.align 4

main:		save	%sp, -96, %sp
		clr	%r16	! total # of characters
		clr	%r17	! # of upper case letters (in the set {A-Z})
		clr	%r18	! # of lower case letters (in the set {a-z})
		clr	%r19	! # of decimal digits (in the set {0-9})
		clr	%r20	! # of hexadecimal digits (in the set {0-9,A-F,a-f})
		clr	%r21	! # of newline characters (0x0A)
		clr	%r22	! # of whitespace characters (0x09, 0x0A and 0x20)
		clr	%r23	! # of control characters (0x00 to 0x1F, 0x7F)

loop:	call	getchar
		nop

		cmp	%r8, -1
		beq	end
		nop

		call	putchar
		nop

		inc	%r16

ifLetterUpper:
		cmp	%r8, 'Z'	! upper case letter
		bgt	endLetterUpper
		nop

		cmp	%r8, 'A'
		blt	endLetterUpper
		nop

		ba	thenLetterUpper
		nop
thenLetterUpper:
		inc	%r17
endLetterUpper:

ifLetterLower:
		cmp	%r8, 'z'	! lower case letter
		bgt	endLetterLower
		nop

		cmp	%r8, 'a'
		blt	endLetterLower
		nop

		ba	thenLetterLower
		nop
thenLetterLower:
		inc	%r18
endLetterLower:

ifDigit:
		cmp	%r8, 0x39	! digit
		bgt	endDigit
		nop

		cmp	%r8, 0x30
		blt	endDigit
		nop

		ba	thenDigit
		nop
thenDigit:
		inc	%r19
		inc	%r20	!also needs to be added to hex digits
endDigit:

ifHexUpper:	
		cmp	%r8, 'F'	! hex digit Uppercase
		bgt	endHexUpper
		nop

		cmp	%r8, 'A'
		blt	endHexUpper
		nop

		ba	thenHexUpper
		nop
thenHexUpper:
		inc	%r20
endHexUpper:

ifHexLower:
		cmp	%r8, 'f'	! hex digit Lowercase
		bgt	endHexLower
		nop

		cmp	%r8, 'a'
		blt	endHexLower
		nop

		ba	thenHexLower
		nop
thenHexLower:
		inc	%r20
endHexLower:

ifNewLine:
		cmp	%r8, 0x0A	! NewLine
		bgt	endNewLine
		nop

		ba	thenNewLine
		nop
thenNewLine:
		inc	%r21
		!inc %r22	!also needs to be added to whitespace
endNewLine:

ifWhiteSpace:		
		cmp	%r8, 0x20	! Tab
		be	thenWhiteSpace
		nop

		cmp	%r8, 0x09	! space
		be	thenWhiteSpace
		nop
		
		ba	thenWhiteSpace
		nop
thenWhiteSpace:
		inc	%r22
endWhiteSpace:

ifControlChar:
		cmp	%r8, 0x00
		blt	endControlChar
		nop

		cmp	%r8, 0x1F	! control char
		bgt	endControlChar
		nop
		
		cmp	%r8, 0x7F	! esc char
		bgt	endControlChar
		nop

		ba	thenControlChar
		nop
thenControlChar:
		inc	%r23
endControlChar:

endif:	cmp	%r8, -1
		beq	end
		nop

		ba	loop
		nop


end:
		set	fmt, %r8
		mov	%r16, %r9
		call	printf
		nop

		set	fmt1, %r8
		mov	%r17, %r9
		call	printf
		nop

		set	fmt2, %r8
		mov	%r18, %r9
		call	printf
		nop

		set	fmt3, %r8
		mov	%r19, %r9
		call	printf
		nop

		set	fmt4, %r8
		mov	%r20, %r9
		call	printf
		nop

		set	fmt5, %r8
		mov	%r21, %r9
		call	printf
		nop
		
		set	fmt6, %r8
		mov	%r22, %r9
		call	printf
		nop
		
		set	fmt7, %r8
		mov	%r23, %r9
		call	printf
		nop

		ret
		restore

fmt:		.asciz	"\nTotal Number of Characters = %d\n"
fmt1:		.asciz	"Number of upper case letters = %d\n"
fmt2:		.asciz	"Number of lower case letters = %d\n"
fmt3:		.asciz	"Number of decimal digits = %d\n"
fmt4:		.asciz	"Number of hexadecimal digits = %d\n"
fmt5:		.asciz	"Number of newline characters = %d\n"
fmt6:		.asciz	"Number of white space characters = %d\n"
fmt7:		.asciz	"Number of control characters = %d\n\n"