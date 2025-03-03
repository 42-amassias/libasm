bits 64

section .text

global ft_strlen

	ft_strlen:
		xor rax, rax
	ft_strlen_loop:
		cmp BYTE [rdi+rax], 0x0
		jz ft_strlen_ret
		inc rax
		jmp ft_strlen_loop
	ft_strlen_ret:
		ret
