#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    if (argc > 2) {
        printf("Incorrect number of arguments");
        return 1;
    }
    FILE* f = fopen(argv[1], "r"); //open file to read

    if (f == NULL) {
        printf("Invalid file");
        return 1;
    }

    char* prev_line = NULL;
    char* curr_line = NULL;

    size_t curr_len = 0;
    ssize_t curr_read;

    while((curr_read = getline(&curr_line, &curr_len, f)) != NULL){
        if (prev_line == NULL || strcmp(prev_line, curr_line) != 0) { //either this is the first line or they are not the same - both cases print curr_line 
            printf("%s", curr_line);
        }
        if(prev_line != NULL) {
            free(prev_line);
        }
        prev_line = strdup(curr_line); //set prev line to current for next iteration
    }
    if (prev_line != NULL) { //IN CASE prev_line wasn't freed before
        free(prev_line);
    }
    if (curr_line != NULL) {
        free(curr_line);
    }
    return 0;
}
