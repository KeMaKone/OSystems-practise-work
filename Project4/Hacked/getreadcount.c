#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char * argv[])
{
    if(argc > 1)
    {
        if(strcmp(argv[1],"1"))
        {
            if(strcmp(argv[2],"1"))
            {
                int readcount = getreadcount(1, 1);
                printf(1, "readcount: %d\n", readcount);
            }
            else
            {
                int readcount = getreadcount(1, 0);
                printf(1, "readcount: %d\n", readcount);
            }
        }
        else if(strcmp(argv[1], "2"))
        {
            if(strcmp(argv[2],"1"))
            {
                int readcount = getreadcount(2, 1);
                printf(1, "writecount: %d\n", readcount);
            }
            else
            {
                int readcount = getreadcount(2, 0);
                printf(1, "writecount: %d\n", readcount);
            }
        }
        else
        {
            printf(1, "Usage: getreadcount [1=writecount|2=readcount] [1=track|0=reset counter]\n");
        }
    }
    else
        {
            printf(1, "Usage: getreadcount [1=writecount|2=readcount] [1=track|0=reset counter]\n");
        }
    exit();
}