global _ft_strlen

section .text

_ft_strlen:
    xor rax, rax
    .check_for_null:
        cmp rdi, 0x00
        je .exit
    .begin:
        cmp [rdi + rax], byte 0
        je .exit
        inc rax
        jmp .begin
.exit:
        ret
