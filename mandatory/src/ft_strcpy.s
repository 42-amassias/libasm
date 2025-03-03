bits 64

global ft_strcpy

ft_strcpy:
	xor rax, rax
ft_strcpy_loop:
	mov cl, BYTE [rsi+rax]
	mov BYTE [rdi+rax], cl
	cmp cl, 0
	jz ft_strcpy_ret
	inc rax
	jmp ft_strcpy_loop
ft_strcpy_ret:
	mov rax, rdi
	ret
