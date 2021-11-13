;ssize_t		ft_write(int fildes, const void *buf, size_t nbyte)


global _ft_write
extern ___error
section .text

_ft_write:
	mov     rax, 0x02000004
	mov     rbx, rsi
	syscall
	jc      .error
	ret
	.error:
					push    rax
					call    ___error
					pop     rsi
					mov		[rax], rsi
					mov		rax, -1
					ret
					
