.text
.globl main


.globl zip1
.globl zip2
zip1: .long 3
zip2: .long 5

swap:
    pushq   %rbp
    movq    %rsp, %rbp
    pushq   %rbx
    

    movq    24(%rbp),   %rcx
    movq    16(%rbp),   %rdx

    movq    (%rcx),     %rax
    movq    (%rdx),     %rbx
    movq    %rax,       (%rdx)
    movq    %rbx,       (%rcx)
    
    movq    -8(%rbp),   %rbx
    movq    %rbp,       %rsp
    popq    %rbp
    ret

main:
    movq    %rsp, %rbp #for correct debugging
    xorq    %rax, %rax
    pushq   $zip1
    pushq   $zip2
    call    swap
    movq    zip1,   %rax
    movq    zip2,   %rbx
    ret
