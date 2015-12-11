		!after some bad circumstances I didn't start till hours before it was due and gave up. 15pts worth
		.section    ".text"
		.align      4

.global     view	!useful example #25-26 on course website, http://ieng9.ucsd.edu/~cs30x/sparcstack.html
view:
		save	%sp, -96, %sp
		mov		%i0, %r16	!pointer to table of players
		mov		%i1, %r17	!jersey number of player to be displayed
		
		!I think there is a way to call search and have it find the player you are looking for, then in view
		!you can simply print out the player when found, however I have not found a way to do that just yet
		call	search
		nop
		
		set		fmt0, %o0	!print column headers
		call	printf
		nop

		set fmt2, %o0 	! print a blank line
		call printf
		nop
		
		set fmt1, %o0		! print out one player ! need to use local registers because
		mov %l0, %l2		! jersey number
		add %l0, 0, %r19	! player name
		lduh [%l0+12], %r20	! games played
		lduh [%l0+14], %r21	! goals scored
		lduh [%l0+16], %r22	! assists scored
		call printf
		nop
		
fmt0: 	.ascii "\n"
		.ascii "Current-Jersey Student-name games-played goals-scored assists-scored points(goals+assists) points-per-game \n"
fmt1: 	.asciz "%6d %-12s %6d %6d %6d %08x\n"
fmt2: 	.asciz "\n"
		.align 4

		
.global     search
search:
		save	%sp, -96, %sp
		mov		%i0, %r16	!pointer to table of players
		mov		%i1, %r17	!jersey number of player to be displayed
		mov 	%i2, %r18	!pointer to pointer to player?
		clr		%l2			!intialize index to zero
		
search_loop:
		lduh [%l2+0], %l7	!go to index and store jersey #
		
		cmp		%l7, 0		!compare jersey # at index with 0=Null, won't work when jersey number is 0!
		be		not_found	!could not find player !bge?
		nop
		
		cmp		%l7, %r17	!compare jersey # at index with jersey number we are looking for
		be		found	
		nop
		
		smul %l2, 16, %l3 ! offset <== index * element size
		add %l0, %l3, %l4 ! record address <== base + offset

		inc	%l2	!increment index by one
		ba search_loop
		nop
		clr %l7
		
not_found:
		set		0, %o0	!return 0(false) player not found
		nop!?
		
		ret
		restore
		
found:
		set		1, %o0	!return 1(true) player found
		nop!?
		
		ret
		restore
