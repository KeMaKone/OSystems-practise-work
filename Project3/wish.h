#include <stdio.h>

#ifndef wish_h
#define wish_h

#define BUFSIZE 256
#define PATHSIZE 256
#define PATHLENGTH 64
#define LOGOUTITME 60

#define PROMPT "wish> "
#define DEFFAULTPATH "/bin"

//Path_t linked list structure
typedef struct node_t {
    char* value;
    struct node_t* next;
} Node_t;

//wishPrints
void autoLogout();
void welcomeText();
void helpText();
void errorHandle();
void exitShell();

//wishLinked
Node_t* addToList(Node_t* head, char* value);
char* getValue(Node_t* head, int index);
void removeFromList(Node_t* head, char* value);
void getArray(Node_t* head, char* argv[], int);
Node_t* freeList(Node_t* head);


//wish
int readInput(char*, FILE*);
Node_t* parseInput(char*, Node_t*);
int changeDirectory(Node_t*);
int setPath(Node_t*, Node_t*);
int handleShellCommands(Node_t*, Node_t*);
int checkPath(Node_t*, Node_t*);
int handleExternalCommands(Node_t*, Node_t*, int, int);
int handleTokenInput(Node_t*, Node_t*);

#endif // !
