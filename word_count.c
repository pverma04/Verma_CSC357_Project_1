#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
Write a program (with main in a file named word_count.c) 
that takes a single (optional) command-line argument 
specifying a file name. The program must read the contents 
of the file (read from stdin if no file is specified) 
and print (only) the number of lines, number of words, 
and number of characters read 
(the format of the output is up to you).
*/
/*
word: whitespace delimited sequence of characters (use isspace() to check for such characters)
line: sequence of characters terminated by a newline character
*/

int main (int argc, char* argv[]) {
    const char* fname;

    int curr_ch = 0;

    int num_lines = 0;
    int num_words = 0 ;
    int num_chars = 0;

    FILE* fp = NULL;

    if (argv[1] == NULL){
        //make file to stdin - dont know how yet
    } else {
        fname = argv[1];
        fp = fopen(fname, "r");
        if (fp == NULL) {
            perror("File DNE");    
            return -1;
        }
    }

    while(!feof(fp)){ //while NOT end of file on fp...
        curr_ch = fgetc(fp); //get current char from file

        if (curr_ch == '\n'){ //if new line, then add to lines regardless of line length
            num_lines++;
            num_words++; // a line endning means a word also ended
        }
        if (isspace(curr_ch)) {
            num_words++; //each white space means a word has ended - possibly needs edge case checking?
        }
        else {
            num_chars++;
        }
    }
    fclose(fp);
    printf("Number of Characters: %d\n", num_chars);
    printf("Number of Words: %d\n", num_words);
    printf("Number of Lines: %d\n", num_lines);
    return 0;
}
