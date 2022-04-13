UT Editorial note:

This programming case is from the course book project repository; all files and additions are available via repository page https://github.com/remzi-arpacidusseau/ostep-projects.


To turn in your work, include a short summary of what you did and screenshots of functional versions of your utility programs to the document file, with the addition of public address to the repository, which contains your solution source code. No source code availability, or source code that does not compile equals failure.


Otherwise the scoring is as follows:

-Everything submitted compiles and works at least on some level. (Required, 2 points)
-The documentation is appropriate, correct and the repository is available (Required, 0 points)
-The documentation is detailed, and the provided source code is reasonably well commented. (1 point)
-You can reset the counter with an argument (1 point)
-You can select between the number of different system call which to follow (1 point)

-------------------------------------


Intro To Kernel Hacking

To develop a better sense of how an operating system works, you will also do a few projects inside a real OS kernel. The kernel we'll be using is a port of the original Unix (version 6), and is runnable on modern x86 processors. It was developed at MIT and is a small and relatively understandable OS and thus an excellent focus for simple projects.

This first project is just a warmup, and thus relatively light on work. The goal of the project is simple: to add a system call to xv6. Your system call, getreadcount(), simply returns how many times that the read() system call has been called by user processes since the time that the kernel was booted.

Background

If you haven't watched the
https://youtu.be/vR6z2QGcoo8

Video contains a detailed walk-through of all the things you need to know to unpack xv6, build it, and modify it to make this project successful.
One good way to start hacking inside a large code base is to find something similar to what you want to do and to carefully copy/modify that. Here, you should find some other system call, like getpid() (or any other simple call). Copy it in all the ways you think are needed, and then modify it to do what you need.

More information about xv6, including a very useful book written by the MIT folks who built xv6, is available here. Do note, however, that we use a slightly older version of xv6 (for various pedagogical reasons), and thus the book may not match our code base exactly.

Your System Call

Your new system call should look have the following return codes and parameters:

int getreadcount(void)

Your system call returns the value of a counter (perhaps called readcount or something like that) which is incremented every time any process calls the read() system call. That's it!

Tips

Most of the time will be spent on understanding the code. There shouldn't be a whole lot of code added.

Using gdb (the debugger) may be helpful in understanding code, doing code traces, and is helpful for later projects too. Get familiar with this fine tool!