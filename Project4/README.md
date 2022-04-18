# xv6 kernel hacking rundown:
Adding the system call getreadcount to xv6 requires modyfing these files: usys.S, user.h, syscall.h, syscall.c, sysfile.c.

## usys.S
In usys.S are all the system calls in xv6. There SYSCALL() is defined which follows it's assembly instructions.
At the end of the file I added `SYSCALL(getreadcount)`.

## user.h
In user.h I defined syscall and what it takes in and what it returns. There I added `int getreadcount(void);`.

## syscall.h
The syscall is added to syscall.h file where the syscalls are listed and numbered.
So I added to the bottom `#define SYS_getreadcount 22`.

## syscall.c
Then ofcourse we need to add the syscall to the syscall.c file. 
In the file there is a list of all syscalls and before that syscall functions are declared.
In the list of syscalls we will add `[SYS_getreadcount] sys_getreadcount` 
and at the declarations we will add `extern int getreadcount(void);`.

Then we need to find the read() system call. 
This can be done using the command `grep sys_read ./*.c`. 
This will return two results from syscall.c and one from sysfile.c.

## sysfile.c
First I added a static integer readcount above the sys_read function to keep count. 
Then I added a incrementation command for the variable inside sys_read. 
After that I added the function sys_getreadcount below the sys_read which returns the variable readcount.

To test this I created a simple file called getreadcount.c that makes this system call and prints the results. 
Then I added the program to the Makefile so it works in the xv6-OS.
