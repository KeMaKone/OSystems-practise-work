## Lore

## Chosen projects:
# Project 2: Unix Utilities

Time spent:
Total time spent on all of the utilites was about 7 hours.

Thoughts about the project instruction:
The instructions were clear on how diffirent utilities should work and they specified what the output of each program should look like.

Thoughts about the code:
I tried keeping the code as clean as possible with comments and spacing. Maybe some comments could be left out as they are a bit trivial but at least all functionality is explained.

Sources:
I mostly sticked to prior knowledge and the documentation that was recommended on the instructions. Some of the code is completed using Github Copilot but it proved to be a bit questionable in some of it's recommendations as they needed some filling in. Also converting 4-byte integer back to normal ASCII-format was from a Cpgrogramming messageboard [https://cboard.cprogramming.com/c-programming/87461-how-read-4-consecutive-bytes-integer.html].

# Project 3: Unix Shell

Time spent:
Total time spent on the code would be about 8 hours.

Thoughts about the project instruction:
The introduction of a path into this task was unnecessary as it promotes a bad coding habit of rewriting a perfectly fine system as path is already implemented in environment variables. 

Thoughts about the code:
The goal for this project for me would be keep the code readable and easy to understand. To do this I used abstraction and tried to keep indendation low.

The usage of linked lists for handling tokens and path was a late change in the development cycle. Due to this there are few unnecessary mallocs as I could have implemented a value change for already allocated nodes but freeing the list and allocating new nodes was easier change from an array.

Sources:
For this project I didn't use external sources other than the depatable GitHub Copilot, and documentation. This is due to the fact that from my experience the examples given are not the best and I would rather learn from my own experience. 

Github Copilot:
GitHub Copilot wasn't very helpful when doing this project as it thinks strings are their own datatype, and not an array of chars. Some suggestions when writing code dealing with linked lists were clearly snippets and not truely fitted for the project at hand, which lead to lot of null pointer errors or reading random memory data. Most useful it was when refractoring the code as it had some data to go on and when implementing the headerfile. 


# Project 4: Kernel Hacking

Konsta:
For me I had trouble getting the xv6-OS to run. For to get the codebase to compile I had to edit (uncomment) a line 1461 in usertests.c as it would lead to an error of string overflow.

After making the necessary changes, I got the code to compile and to the next hurdle of the project would be running the code in QEMU as the operating system got immediadly stuck on "Booting from Hard Disk.." line. Next trick I would try to do is downgrading binutils to version 35.1 due to a suggestion in forums regarding this problem. The suggestion did not work and I was still stuck on getting the kernel to run. 

As I had spent many hours debugging and getting the Operating System to work not even starting on the ask at hand I decided to hand over installation to Tuomas.

Tuomas:

Installation xv6-OS:
Copying the code xv6-OS from github and compiling it didn't cause any errors with me using `make` command. After that I tried running the os in the qemu emulator using `make qemu` command but it didn't work notifying the error: `Couldn't find a working QEMU executable.` eventhough I had just installed qemu. So I did some chages on the Makefile in line 54 by uncommenting the part `QEMU = qemu-system-x86_64`. Trying the command the system notified to install qemu-system-x86_64 so I did. After this the os worked as it should on the emulator.

A rundown of the kernel hacking can be found in the Project 4 folder.

Time spent:
Total time spent on installing and coding was about 5 hours.

Thoughts about the project instruction:
The instructions were quite short compared to the other projects but with the background video I think they were sufficient. Maybe the installation could have been explained in more detail.

Thoughts about the code:
This project didn't need that much coding mainly just exploring the original code and adding in to it. So I think the coding part was quite easy.

Sources:
Biggest source was the background video provided in the project instructions. Other sources I used for this project were a GeeksforGeeks article about the subject and a youtube video about adding a system call. Links for them are listed below:

https://www.geeksforgeeks.org/xv6-operating-system-adding-a-new-system-call/
https://www.youtube.com/watch?v=21SVYiKhcwM&ab_channel=TongYu
