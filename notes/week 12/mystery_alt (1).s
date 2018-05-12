	.text
	.globl	mystery
	.type	mystery, @function
mystery:
	pushl 	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	addl	%edx, (%ecx)
	movl	%ebp, %esp
	popl	%ebp
	ret
