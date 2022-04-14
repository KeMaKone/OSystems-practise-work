#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *file;
    char *line = NULL;
    size_t len = 0;

    //Not enough arguments
    if(argc <= 1){
        printf("my-grep: searchterm [file...]\n");
        exit(1);
    }

    //File is specified
    if(argv[2]){

        //Open file. If there is an error print error msg and exits w/ code 1
        if((file = fopen(argv[2], "r"))==NULL){
            printf("my-grep: cannot open file\n");
            exit(1);
        }

    //File is not specified
    }else{
        file = stdin;
    }

    //Go through each line of the file and find the search term
    while(getline(&line, &len, file) != -1){
        if(strstr(line, argv[1])){
            printf("%s", line);
        }
    }

    //Close file and free line
    fclose(file);
    free(line);

    return 0;
}