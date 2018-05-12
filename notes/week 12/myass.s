# start the code section
.text

# define myFunc as a global (exported) function
.global myFunc
.type myFunc, @function
myFunc:
    push %ebp       # save the old base pointer value
    mov %esp, %ebp  # set the new base pointer value