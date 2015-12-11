		.section    ".text"
		.align      4
		!make -f proj12.makefile
		
		!./proj12
		!gcc -c proj12.support.s
		!gcc proj12.support.o /user/cse320/Projects/project12.driver.o /user/cse320/lib/reglib.o -o proj12

.global		absolute	!make -f proj11.makefile		!(f2-f4)
absolute:
		save	%sp, -128, %sp
		std		%i0, 	[%sp+112]	!64bits also i1
		std		%f2, 	[%sp+96]
		std		%f4, 	[%sp+104]
		ldd		[%sp+112], %f4
		
		set		-1, %l0				!set -1 so we can handle our neg. values
		std		%l0, 	[%sp+120]
		ld		[%sp+120], %f2
		
		fitod	%f2, %f2		!convert to double, need because of driver input int
		
		fcmpd	%f4, %f2
		fbge	branchonpos		
		nop
		
		fmuld	%f4, %f2, %f0
		
		!ldd		[%sp+96], %f2
		!ldd		[%sp+104], %f4
		ba		end
		nop
endabsolute:

branchonpos:
		fmovd	%f4, %f0
		ret
		restore
endbranchonpos:
!!!
!!!
.global		modulo				!(f6-f14)
modulo:
		save	%sp, -128, %sp
		
		std		%i0,	[%sp+112]
		std		%i2,	[%sp+120]
		
		ldd		[%sp+112],	%f14
		ldd		[%sp+120],	%f12
		
		set		zero, %l0
		set		inf, %l2
		set		nan, %l4
		ldd		[%l0],	%f22
		ldd		[%l2],	%f16
		ldd		[%l4],	%f8
		
		!start comparisons
		!fcmpd	%f12, %f6
		!fbe		NaN
		!nop
		
		fcmpd	%f12, %f8		!comparison divisor can't be zero
		fbe		NaN				!branch if equal to NaN
		nop
		
		!fcmpd	%f12, %f10
		!fbe		NaN
		!nop
		
		!fcmpd	%f14, %f6	!don't need?
		!fbe		INF
		!nop
		
		!fcmpd	%f14, %f8
		!fbe		NaN
		!nop
		
		fdivd	%f14, %f12, %f0	!divide x and y
		fdtoi	%f0, %f0		!int	!convert double to integer
		fitod	%f0, %f0		!double!convert to double
		fmuld	%f12, %f0, %f0	!multiply with y
		fsubd	%f14, %f0, %f0	!subtract and store in f0
		
		ldd		[%sp+96],	%f12		!restore old values
		ldd		[%sp+104],	%f14
		ba		end
		nop
endmodulo:
!!!
!!!
.global             factorial		!(f16-f24)
factorial:
		save	%sp, -128, %sp
		
		set		zero, %l0
		set		inf, %l2
		set		nan, %l4
		!std		%f20, [%sp+112]	!counter
		
		ldd		[%l0],	%f22
		ldd		[%l2],	%f16
		ldd		[%l4],	%f18
		
		std		%i0, [%sp+96]
		ldd		[%sp+96],	%f24
		
		fitod	%f24, %f24	!convert to double
		
		fcmpd	%f24, %f22		!if the value is neg
		fbl		zero_end		!branch on less than
		nop
		fcmpd	%f24, %f22		!compare the value we are passed(i0-f24) to zero
		fbe		one_end		!branch on equal to one_end
		nop
		fcmpd	%f24, %f16		!compare value to inf
		fbe		INF				!branch accordingly
		nop
		fcmpd	%f24, %f18		!compare value to NaN
		fbe		NaN				!branch accordingly
		nop
		
		fmovd	%f24, %f20
		set		one, %l0
		ldd		[%l0],	%f22
endfactorial:
		
fact_loop:
		fcmpd	%f20, %f22
		fble	fact_end
		nop
		
		fsubd	%f20, %f22, %f20	!subtract 1 from counter
		fmuld	%f20, %f24, %f24
		ba		fact_loop
		nop
endfact_loop:

zero_end:
		set		zero,%l0
		ldd		[%l0],%f0
		ba		end
		nop
endzero_end:

one_end:
		set		one,%l0
		ldd		[%l0],%f0
		ba		end
		nop
endone_end:
		
fact_end:
		fmovd	%f24,%f0
		ba		end
		nop
endfact_end:
!!!
!!!
.global 		power			!(f26-f30) avail.  !(f10-f12)
power:
		save	%sp, -96, %sp
		
		set		one, %l0
		set		inf, %l2
		set		nan, %l4
		ldd		[%l0],	%f30
		ldd		[%l2],	%f26
		ldd		[%l4],	%f28
		
		std		%i0, [%sp+96]
		ldd		[%sp+96],	%f12
		
		std		%i2, [%sp+96]
		ldd		[%sp+96],	%f10
		fitod	%f10, %f10		!convert to double
		
		!start comparisons
		fcmpd	%f10, %f30		!comparing exponent to one
		fble	pow_end			!branch on less than or equals
		nop
		
		!fcmpd	%f10, %f26		!comparing exponent to inf
		!fbe		INF				!branch on equals inf
		!nop
		
		fcmpd	%f10, %f28		!comparing exponent to NaN
		fbe		NaN				!branch on equals NaN
		nop
		
		fcmpd	%f12, %f30		!comparing base to one
		fbe		pow_end			!branch on equals to pow_end
		nop
		
		!fcmpd	%f12, %f26		!comparing base to inf
		!fbe		INF				!branch on equals inf
		!nop
		
		fcmpd	%f12, %f28		!comparing base to NaN
		fbe		NaN				!branch on equals NaN
		nop
		
		fmovd	%f12,%f0
endpower:
		
pow_loop:
		fsubd	%f10, %f30, %f10
		fcmpd	%f10, %f30		!comparing exponent to one
		fbl		end				!branching on less than
		nop
		
		fmuld	%f12,%f0,%f0	!double multi then branch to pow_loop again
		ba		pow_loop
		nop
endpow_loop:
		
pow_end:		!when the base is one, set appropriate values back
		set		zero, %l0
		ldd		[%l0],	%f30
		
		fcmpd	%f10, %f30
		fbe		one_end
		nop
		
		fmovd	%f12, %f0
		ba		end
		nop
endpow_end:
!!!
!!!
.global 		sine		!didn't get around to sine
sine:
		save	%sp, -96, %sp
		
		set		one, %l0
		set		inf, %l2
		set		nan, %l4
		ldd		[%l0],	%f30
		ldd		[%l2],	%f26
		ldd		[%l4],	%f28
		
		
endsine:

sine_loop:
		
endsine_loop:
!!!
!!!
INF:
		set		inf, %l0
		ldd		[%l0], %f0
		ret
		restore
		
NaN:
		set		nan, %l0
		ldd		[%l0], %f0
		
end:
		ret
		restore
		
.section	".data"	!start data section
.align	8

zero:	.double	0r0
nan:	.double	0rnan
one:	.double	0r1
inf:	.double	0rinf
