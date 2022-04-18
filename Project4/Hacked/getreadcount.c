#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char * argv[])
{
    int readcount = getreadcount();
    printf(1, "readcount: %d\n", readcount);
    
    exit();
}