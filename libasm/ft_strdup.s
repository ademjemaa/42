		global	_ft_strdup
		section	.text
		extern	_malloc
		extern	_ft_strlen
		extern	_ft_strcpy
_ft_strdup:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 0x010
	mov		r12, rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	call	_malloc
	mov		rdi, rax
	mov		rsi, r12
	call	_ft_strcpy
	mov		rdi, r12
	leave
	ret
