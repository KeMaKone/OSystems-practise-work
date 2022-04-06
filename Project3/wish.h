#ifndef wish_h
#define wish_h

#define BUFSIZE 256
#define PATHSIZE 256
#define PATHLENGTH 64
#define LOGOUTITME 60
#define PROMPT "wish> "
#define DEFFAULTPATH "/bin"

//Path_t linked list structure
typedef struct path_t {
    char* path;
    struct path_t* next;
} Path_t;

void autoLogout();
void welcomeText();
void helpText();
void errorHandle();
int readInput(char*, FILE*);
int parseInput(char*, char*[]);
int changeDirectory(char*[]);
int setPath(char*[], char*[]);
void exitShell();
int handleShellCommands(char*[], char*[]);
int checkPath(char*[], char*[]);
int handleExternalCommands(char*[], char*[], int*);


#endif // !
