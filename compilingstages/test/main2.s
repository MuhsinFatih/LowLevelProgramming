	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_swap1                  ## -- Begin function swap1
	.p2align	4, 0x90
_swap1:                                 ## @swap1
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movl	(%rsi), %eax
	movl	%eax, -20(%rbp)
	movq	-16(%rbp), %rsi
	movl	(%rsi), %eax
	movq	-8(%rbp), %rsi
	movl	%eax, (%rsi)
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rsi
	movl	%eax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_swap2                  ## -- Begin function swap2
	.p2align	4, 0x90
_swap2:                                 ## @swap2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movl	(%rsi), %eax
	movq	-8(%rbp), %rsi
	xorl	(%rsi), %eax
	movl	%eax, (%rsi)
	movq	-8(%rbp), %rsi
	movl	(%rsi), %eax
	movq	-16(%rbp), %rsi
	xorl	(%rsi), %eax
	movl	%eax, (%rsi)
	movq	-16(%rbp), %rsi
	movl	(%rsi), %eax
	movq	-8(%rbp), %rsi
	xorl	(%rsi), %eax
	movl	%eax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_is_odd                 ## -- Begin function is_odd
	.p2align	4, 0x90
_is_odd:                                ## @is_odd
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	movl	$2, %eax
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%edi, %eax
	cltd
	movl	-8(%rbp), %edi          ## 4-byte Reload
	idivl	%edi
	cmpl	$1, %edx
	sete	%cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movl	%edx, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_is_odd2                ## -- Begin function is_odd2
	.p2align	4, 0x90
_is_odd2:                               ## @is_odd2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	andl	$1, %edi
	movl	%edi, -8(%rbp)
	cmpl	$1, -8(%rbp)
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_is_even2               ## -- Begin function is_even2
	.p2align	4, 0x90
_is_even2:                              ## @is_even2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	xorl	$-1, %edi
	andl	$1, %edi
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_div_by_8               ## -- Begin function div_by_8
	.p2align	4, 0x90
_div_by_8:                              ## @div_by_8
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi15:
	.cfi_def_cfa_offset 16
Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi17:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	andl	$7, %edi
	cmpl	$0, %edi
	setne	%al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_div_by_4               ## -- Begin function div_by_4
	.p2align	4, 0x90
_div_by_4:                              ## @div_by_4
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi18:
	.cfi_def_cfa_offset 16
Lcfi19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi20:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	andl	$3, %edi
	cmpl	$0, %edi
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_reverseSign            ## -- Begin function reverseSign
	.p2align	4, 0x90
_reverseSign:                           ## @reverseSign
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi21:
	.cfi_def_cfa_offset 16
Lcfi22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi23:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	xorl	$-1, %edi
	addl	$1, %edi
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_multBy4                ## -- Begin function multBy4
	.p2align	4, 0x90
_multBy4:                               ## @multBy4
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi24:
	.cfi_def_cfa_offset 16
Lcfi25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi26:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	shll	$2, %edi
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_multBy5                ## -- Begin function multBy5
	.p2align	4, 0x90
_multBy5:                               ## @multBy5
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi27:
	.cfi_def_cfa_offset 16
Lcfi28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi29:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	shll	$2, %edi
	addl	-4(%rbp), %edi
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_show_bytes             ## -- Begin function show_bytes
	.p2align	4, 0x90
_show_bytes:                            ## @show_bytes
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi30:
	.cfi_def_cfa_offset 16
Lcfi31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi32:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %esi
	subl	$1, %esi
	movl	%esi, -16(%rbp)
LBB10_1:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -16(%rbp)
	jl	LBB10_4
## BB#2:                                ##   in Loop: Header=BB10_1 Depth=1
	leaq	L_.str(%rip), %rdi
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movzbl	(%rax,%rcx), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB10_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB10_1
LBB10_4:
	leaq	L_.str.1(%rip), %rdi
	movq	-8(%rbp), %rax
	movl	(%rax), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_twos_complement        ## -- Begin function twos_complement
	.p2align	4, 0x90
_twos_complement:                       ## @twos_complement
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi33:
	.cfi_def_cfa_offset 16
Lcfi34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi35:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	xorl	$-1, %edi
	addl	$1, %edi
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi36:
	.cfi_def_cfa_offset 16
Lcfi37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi38:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	L_.str.2(%rip), %rdi
	movq	L_main.pt1(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	L_main.pt2(%rip), %rax
	movq	%rax, -16(%rbp)
	movl	-16(%rbp), %esi
	movl	-12(%rbp), %edx
	movb	$0, %al
	callq	_printf
	xorl	%edx, %edx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%edx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%.2x\n"

L_.str.1:                               ## @.str.1
	.asciz	"%10i\n"

	.section	__TEXT,__literal8,8byte_literals
	.p2align	2               ## @main.pt1
L_main.pt1:
	.long	1                       ## 0x1
	.long	2                       ## 0x2

	.p2align	2               ## @main.pt2
L_main.pt2:
	.long	2                       ## 0x2
	.long	3                       ## 0x3

	.section	__TEXT,__cstring,cstring_literals
L_.str.2:                               ## @.str.2
	.asciz	"pt1: %i %i"

	.comm	_x,80,4                 ## @x

.subsections_via_symbols
