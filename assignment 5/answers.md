# Assignment 5 Questions & Answers


1\. What is the command to compile the files with extra symbols that are useful for GDB?  
```bash
gcc GDBassign.c blowfish.c -o main.out -g -O0   # -O0 for no optimization
```
2\. What's the address of stuff?
```c
0x7ffeefbfeb70
```

3\. What's the address of stuff[0]?
```c
0x7ffeefbfeb70
```

4\. Do we expect these to be the same? Why? Explain what the [ ] operator does in C.
```
Yes, they were expected to be the same because an array in c is a pointer to the array in the memory. The [] operator is used to access an object in the array with given offset. An offset of 0 is no offset, hence points to the same address as the array pointer: to the first element
```

5\. In Blowfish_Init( ), what is the value of key?
```bash
LAME_KEY
```

6\. What command(s) did you type in order to learn this?
```bash
break blowfish.c:Blowfish_Init
run
print key
```

7\. In Blowfish_Init( ), what are the values of i and j after the nested for loops have finished? i.e., after:

```c
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 256; j++)
        ctx->S[i][j] = ORIG_S[i][j];
    }
```

```c
i = 4
j = 256
```

8\. What command(s) did you type in order to learn this?
```bash
break 722
continue
print i
print j
```

9\. Before the Blowfish_Encrypt function is called, what is the value of stuff[3] (for each, print the value, and the command used to obtain the value):
* in hex?
* in binary?
* as a float?
* as 4 chars?  
---
```c
"hex": 0x20656874
"binary": 100000011001010110100001110100
"float": 1.94316151e-19
"4 chars": 0x74    0x68    0x65    0x20
```
commands:
```c
break 385
run
p/x stuff[3]
p/t stuff[3]
p/f stuff[3]
x/4b &stuff[3]
```
---
10\. Before the Blowfish_Encrypt function is called, what is the value of stuff if we treat it as a string? (You don't have to write the whole string. Just describe what's there.) What was the command typed in order to obtain this value?
```bash
# It's a char array
# value:
"Oh, who are the people in your neighborhood?\nIn your neighborhood? \n In your neighborhood? \n Say, who are the people inyour neighborhood? ..." # (too long)

# command: 
x/s &stuff
```


11\. What is the value of x the first time that the function F() in Blowfish.c is called?
```c
1753098189
```

12\. What is the output if we run GDB's backtrace (abbreviated "bt") command inside the function F() in Blowfish.c the first time F() is called? Briefly explain the output of the command in your own words.
```bash
# output:
#0  F (ctx=0x7ffeefbfcfd8, x=1753098189) at blowfish.c:550
#1  0x0000000100001357 in Blowfish_Encrypt (ctx=0x7ffeefbfcfd8, xl=0x7ffeefbfcf48, xr=0x7ffeefbfcf44) at blowfish.c:602
#2  0x00000001000016bc in Blowfish_Init (ctx=0x7ffeefbfcfd8, key=0x100003f68 "LAME_KEY", keyLen=8) at blowfish.c:754
#3  0x00000001000011bc in main () at GDBassign.c:383
```
```bash
#0  right now we are in file blowfish.c, on the line 550
#1  we arrived this function from a call on line 602
#2  and that function was called from line 754
#3  and that function was called from file GDBAssign, line 383
```