#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <time.h>

#define BUFSIZE 256
#define LOGOUTITME 60
#define PROMPT "wish> "

void autoLogout(){
    printf("You have been logged out due to inactivity.\n");
    exit(0);
}

void welcomeText(){
    printf("Welcome to the wish shell.\n");
    printf("Autologout has bee set to %d seconds.\n", LOGOUTITME);
    printf("Type 'help' for a list of commands.\n");
    return;
}

void helpText(){
    printf("Available commands:\n");
    printf("'help' - Prints this help text.\n");
    printf("'cd' - Changes the current working directory.\n");
    printf("'path' - Sets a new path.\n");
    printf("'exit' - Exits the shell.\n");
    return;
}

void errorHandle(){
    char* errMsg = "An error has occurred\n";
    write(STDERR_FILENO, errMsg, strlen(errMsg));
    exit(1);
}

int readInput(char* buffer, FILE* fp){
    size_t bufsize = BUFSIZE*sizeof(char);
    return getline(&buffer, &bufsize, fp);
}

//parses the input with strsep returns the amount of tokens
int parseInput(char* buffer, char* tokens[]){
    int i;
    char* token;
    //remove the newline character
    buffer[strlen(buffer)-1] = '\0';
    for(i = 0; (token = strsep(&buffer, " ")) != NULL; i++){
        tokens[i] = token;
    }

    return i;
}

int changeDirectory(char* tokens[]){
    if(tokens[1] == NULL){
        printf("No directory specified.\n");
        return 1;
    }

    if(chdir(tokens[1]) == -1){
        printf("Directory not found.\n");
        return 1;
    }

    return 0;
}

int setPath(char* tokens[]){
    if(tokens[1] == NULL){
        printf("No path specified.\n");
        return 1;
    }

    if(setenv("PATH", tokens[1], 1) == -1) errorHandle();

    return 0;
}

int exitShell(){
    printf("Exiting shell...\n");
    exit(0);
}


//TODO Nice to have: handle uppers and lowers
int handleShellCommands(char* tokens[]){
    if(strcmp(tokens[0], "exit") == 0){
        exitShell();
    } else if(strcmp(tokens[0], "help") == 0){
        helpText();
        return(0);
    } else if(strcmp(tokens[0], "cd") == 0){
        changeDirectory(tokens);
        return(0);
    } else if(strcmp(tokens[0], "path") == 0){
        setPath(tokens);
        return(0);
    }
    return -1;
}

//shell 
int main(){
    char inputBuffer[BUFSIZE];
    char* tokens[BUFSIZE]; //TODO CHANGE TOKENS TO LINKED LIST
    int iaFlag = 1;
    int bgFlag = 0;
    int pid;

    signal(SIGALRM, autoLogout);

    welcomeText();

    //shell loop
    while(1){
        alarm(LOGOUTITME); //autologout
        
        if(iaFlag != 0) printf(PROMPT);

        readInput(inputBuffer, stdin);
        parseInput(inputBuffer, tokens);

        if(handleShellCommands(tokens) == 0) continue;
        
        //fork
        switch(pid = fork()){
            case -1:
                perror("fork");
            case 0:
                if(execvp(tokens[0], tokens) == -1) errorHandle();
                break;
            default:
                if(bgFlag == 0) if(wait(&pid) == -1) errorHandle();
                break;
        }
    }
}