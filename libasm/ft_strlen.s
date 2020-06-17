		global	_ft_strlen
		section	.text
_ft_strlen:
		mov		rax, 0
		cmp		byte [rdi + rax], 0
		je		over

count:
		inc		rax
		cmp		byte [rdi + rax], 0
		jne		count

over:
		ret
