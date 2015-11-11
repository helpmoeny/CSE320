		.section    ".text"
		.align      4

.global     negate	!make -f proj09.makefile
negate:
		save     %sp, -96, %sp

		cmp      %r24, '0x80000000'
		be       error
		nop

		smulcc   %r24, -1, %r24      !signed multiply by -1
		bvs      error               !branch always to error (overflowcase)
		nop

		ba       end
		nop
endnegate:


.global     absolute
absolute:
		save        %sp, -96, %sp

		cmp         %i0, 0
		blt         negative
		nop

		ba          end
		nop

negative:
		smulcc      %i0, -1, %i0
		bvs         error
		nop

		ba          end
		nop
endnegative:
endabsolute:

		
.global     add
add:
		save        %sp, -96, %sp
		addcc       %i0, %i1, %i0
		bvs         error
		nop

		ba          end
		nop
endadd:


.global     sub
sub:
		save        %sp, -96, %sp
		subcc       %i0, %i1, %i0
		bvs         error
		nop

		ba          end
		nop
endsub:


.global     mul		!need overflow case
mul:
		save        %sp, -96, %sp
		
		
		smulcc      %i0, %i1, %i0
		bvs         error
		nop
		
		sra     %i0, 31, %l0	!right shift product by 31 bits, sign extend
		mov		%y, %l1
		cmp		%l0, %l1
		bne		error
		nop

		ba          end
		nop
endmul:


.global     divide		! error conditions (return 0x80000000)
divide:
		save        %sp, -96, %sp
		
		sra         %i0, 31, %l0	!right shift product by 31 bits
		mov			%l0, %y
		nop

		cmp         %i1, 0		!Dividing by zero is not allowed
		be          error
		nop

		sdivcc      %i0, %i1, %i0
		bvs         error
		nop

		ba          end
		nop
enddivide:


.global     remain
remain:
		save        %sp,-96,%sp

		cmp         %i0, 0		!zero divided by anything is zero
		be         	zero
		nop
		
		cmp         %i1, 0		!Dividing by zero is not allowed
		be          error
		nop
		
		cmp         %i0, 0		!negative first value
		blt         first_neg_remain
		nop

		cmp         %i1, 0		!negative second value
		blt         second_neg_remain
		nop

		!start actual process of getting the remainder, divide
		sdivcc      %i0,%i1,%l7
		bvs         error
		nop

		!multiply the quotient
		smulcc      %l7,%i1,%l7
		bvs         error
		nop

		!subtract the quotient from the dividend
		subcc       %i0,%l7,%i0
		bvs         error
		nop

		ba          end
		nop

first_neg_remain:		! first value is negative, second value is positive
		cmp         %i1, 0
		be          error
		nop

		cmp         %i1, 0
		blt         both_neg_remain	!both values are negative
		nop

		!signed multiply the first value with negative one
		smulcc      %i0, -1, %i0

		!start actual process of getting the remainder, divide
		sdivcc      %i0,%i1,%l7
		bvs         error
		nop

		!multiply the quotient
		smulcc      %l7,%i1,%l7
		bvs         error
		nop

		!subtract the quotient from the dividend
		subcc       %i0,%l7,%i0
		bvs         error
		nop

		!multiply the answer by negative 1 to get the correct value
		smulcc      %i0, -1, %i0

		ba          end
		nop
endfirst_neg_remain:

both_neg_remain:		! both values are negative

		smulcc      %i0, -1, %i0
		smulcc      %i1, -1, %i1

		!start actual process of getting the remainder, divide
		sdivcc      %i0,%i1,%l7
		bvs         error
		nop

		!multiply the quotient
		smulcc      %l7,%i1,%l7
		bvs         error
		nop

		!subtract the quotient from the dividend
		subcc       %i0,%l7,%i0
		bvs         error
		nop

		!multiply the answer by negative 1 to get the correct value
		smulcc      %i0, -1, %i0

		ba          end
		nop
endboth_neg_remain:

second_neg_remain:		! first value is positive, second value is negative
		smulcc      %i1, -1, %i1

		!start actual process of getting the remainder, divide
		sdivcc      %i0,%i1,%l7
		bvs         error
		nop

		!multiply the quotient
		smulcc      %l7,%i1,%l7
		bvs         error
		nop

		!subtract the quotient from the dividend
		subcc       %i0,%l7,%i0
		bvs         error
		nop

		ba          end
		nop
endsecond_neg_remain:
endremain:


.global     power		
power:      save        %sp, -96, %sp

		cmp         %i0,0
		be          zero
		nop

		cmp         %i0,1
		be          end
		nop

		cmp         %i1,1
		be          end
		nop

		cmp         %i1, 0		!no negative powers allowed
		blt         error
		nop

		mov         %i1,%l0
		mov         %i0,%l1

power_loop:
		sub         %l0,1,%l0
		cmp         %l0,0
		be          end
		nop

		smulcc      %i0,%l1,%i0
		bvs         error

		ba          power_loop
		nop
endpower_loop:

zero:
		set         0x0000000, %i0
		ba          end
		nop
endzero:
endpower:


.global     factorial
factorial:
		save        %sp,-96,%sp

		cmp         %i0,0
		blt         error
		!nop

		mov         %i0, %r16

fact_loop:
		cmp         %l0,1
		ble         end
		nop

		sub         %r16, 1, %r16
		smulcc      %i0, %r16, %i0
		bvs         error
		nop

		ba          fact_loop
		nop
endfact_loop:
endfactorial:

error:
		set     0x80000000, %i0
enderror:

end:       
		ret
		restore