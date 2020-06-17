		global	_ft_strcpy
		section	.text
_ft_strcpy:
		mov 	rdx, 0
		mov		rax, rdi
		cmp		byte [rsi + rdx], 0
		je		over
count:
		mov		cl, [rsi + rdx]
		mov		[rax + rdx], cl
		inc		rdx
		cmp		byte [rsi + rdx], 0
		jne		count
over:
		mov		cl, [rsi + rdx]
		mov		[rax + rdx], cl
		ret
		
