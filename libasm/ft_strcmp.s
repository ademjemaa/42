		global	_ft_strcmp
		section	.text
_ft_strcmp:
	mov		rcx, 0
	movzx	rax, byte [rdi + rcx]
	movzx	rdx, byte [rsi + rcx]
	cmp		rax, rdx
	jne		over
	cmp		byte [rdi + rcx], 0
	je		over
	cmp		byte [rsi + rcx], 0
	je		over
count:
	inc		rcx
	movzx	rax, byte [rdi + rcx]
	movzx	rdx, byte [rsi + rcx]
	cmp		byte [rsi + rcx], 0
	je 		over
	cmp		byte [rdi + rcx], 0
	je		over
	cmp		rax, rdx
	je		count
over:
	movzx	rax, byte [rdi + rcx]
	movzx	rdx, byte [rsi + rcx]
	sub		rax, rdx
	cmp		rax, 0
	jg		greater
	jl		lesser
	ret

greater :
	mov		rax, 1
	ret

lesser :
	mov		rax, -1
	ret
