## Lore
Sivu jokaisesta valitusta osiosta. 

## Valitut projektit:
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

