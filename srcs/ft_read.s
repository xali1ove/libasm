;ssize_t		ft_read(int fildes, void *buf, size_t nbyte)

global _ft_read
extern ___error
section .text

_ft_read:
	mov     rax, 0x02000003
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
					