global _ft_strcmp

section .text

_ft_strcmp:
    xor rax, rax
    xor rcx, rcx
.loop:
    mov dl, byte [rdi + rcx]
    cmp dl, byte [rsi + rcx]
    jne .end
    inc rcx
    cmp byte [rdi + rcx], 0
    jne .loop
    je  .end
.end:
    mov al, byte [rdi + rcx]
    sub al, byte [rsi + rcx]
    jnc .exit
    neg al
    neg eax
.exit:
    ret