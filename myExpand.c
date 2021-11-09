/* Program to simulate simplified version of Unix utility "expand". Reads input from stdin, and provided text file expands tabs
 * to appropriate number of spaces.Outputs to stdout. Default case (no arguments provided) expands tab to 8 characters(spaces). Provided -t as a
 * first and an integer as a second argument, outputs expanded version with  number of characters for expansion is specified by
 * user
 * Author: Aleksandra Milinovic
 * Written 2/17/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void expand(int);

int main (int ac, char *av[]) {

    int tabSpace = 8;


             if ((ac ==1) ||(ac==3)){

              //default case
              if (ac == 1) {
                      expand(tabSpace);
              }
              //args provided(check validity of args)
              else if ((ac==3) && (strcmp(av[1],"-t") == 0) && ((tabSpace = atoi(av[2]))!= 0)) {
                      expand (tabSpace);
              }else { //everything else is unnacceptable
                fprintf(stderr,"Invalid arguments provided.\n");
              }
                exit(1);

              } else {
                fprintf(stderr, "Please provide valid arguments.\n");
              }//end if else


return 0;
} //end main

/*
 * Takes an integer representing user's specified number of characters, reads file character by character until the end of file
 * is reached. Checks if character is not a Tab an displays it in that case. If character is a Tab, it displays appropriate
 * number of spaces instead.
 */
void expand (int spaces) {

int ch;             //character to read
int characters = spaces; //count for read chars

while ((ch = getchar()) != EOF) { //while not end of file


                if (ch == 9) {                          //if char is a tab
                        ch = 32;                        //turn it into space
                        for(int i=0; i < characters; i++){
                        putchar(ch);                    //display it
                        }
                        characters = spaces;
                }else {                                 //if char is not a tab
                        if(ch != '\n'){
                        characters --;
                        }
                        putchar(ch);                    //display it
                }

                if (characters == 0 || ch == '\n') {
                characters = spaces; // restart count
                }
} //while
} //end expand


