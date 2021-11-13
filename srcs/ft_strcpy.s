global _ft_strcpy

section .text

_ft_strcpy:
    xor rax,    rax
    xor rbx,    rbx
    .check_for_null:
        cmp rdi,    0x00
        je .exit
        cmp rsi,    0x00
        je      .exit
    .begin:
    mov         bl, [rsi+rax]
    mov         byte [rdi + rax], bl
    cmp         bl, 0
    je          .exit
    inc         rax
    jmp         .begin
.exit:
    mov     rax, rdi
    ret
