bits 64

section .text

global ft_strcmp

ft_strcmp:
	xor rax, rax

ft_strcmp_loop:
	movzx ecx, BYTE [rsi+rax]
	movzx ebx, BYTE [rdi+rax]
	sub ebx, ecx

	cmp BYTE [rsi+rax], 0
	jz ft_strcmp_ret
	cmp BYTE [rdi+rax], 0
	jz ft_strcmp_ret

	cmp ebx, 0
	jnz ft_strcmp_ret

	inc rax
	jmp ft_strcmp_loop

ft_strcmp_ret:
	mov eax, ebx
	ret
