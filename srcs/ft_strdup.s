global _ft_strdup
extern _malloc
extern _ft_strlen
extern ___error
section .text

_ft_strdup:
    xor rax, rax
    xor rbx, rbx
    .get_len:
        call _ft_strlen
    .copy_str:
        push rdi
        inc rax
        mov rdi,    rax
        call _malloc
        cmp rax, 0
        je .exit_error
        xor rdx,    rdx
        pop rsi
    .loop_str:
        mov bl, byte [rsi + rdx]
        mov byte [rsi + rdx], bl
        cmp bl, 0
        jz  .exit
        inc rdx
        jmp .loop_str
    .exit:
        ret
    .exit_error:
        call ___error
        mov [rax], byte 12
        mov rax, 0
        ret