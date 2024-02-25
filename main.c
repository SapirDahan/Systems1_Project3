#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

void parse_line_into_words(char*, int, char***);


#define True 1

int main() {

    struct _StrList *StrList; // Create the list
    StrList = StrList_alloc(); // Allocate a memory to the list


   int number; // The number of the menu
   size_t bufsize = 0;  // The buffer size
   int index; // Index in the list
   int times; //For option 1
   size_t size; // The size of the list
   int sorted; // Is the list sorted
   char **words_array; //Array with words from sentence


    // Get numbers from the user until he is asking to stop
    while(True){

        // Scan a number
        scanf("%d", &number);

        // Checking witch number we got
        switch (number) {

            // Add a line to the list
            case 1:
                // Scan a number the numbers of times to inserts strings
                scanf("\n%d\n", &times);

                char *inputLine = NULL;
                bufsize = 0;

                getline(&inputLine, &bufsize, stdin);

                parse_line_into_words(inputLine, times, &words_array);

                for(int i = 0; i < times; i++){
                    StrList_insertLast(StrList, words_array[i]);
                    free(words_array[i]);
                }

                free(words_array);
                free(inputLine);

                break;

            // Insert string in a given index
            case 2:
                scanf("\n%d\n", &index);

                char *inputWord2 = NULL;
                bufsize = 0;

                getline(&inputWord2, &bufsize, stdin);

                parse_line_into_words(inputWord2, 1, &words_array);

                StrList_insertAt(StrList, words_array[0], index);
                free(words_array[0]);
                free(words_array);
                free(inputWord2);


                break;

            // Printing the list
            case 3:
                StrList_print(StrList);
                break;

            // Printing the size of the list
            case 4:
                printf("%zu\n", StrList_size(StrList));
                break;

            // Printing string at a given index
            case 5:
                scanf("\n%d\n", &index);
                StrList_printAt(StrList, index);
                break;

            // Printing the number of char in the list
            case 6:
                printf("%d\n", StrList_printLen(StrList));
                break;

            // Printing how many times a string is at a string is in the list
            case 7:
                bufsize = 0;
                char *inputWord7 = NULL;
                scanf("\n");
                getline(&inputWord7, &bufsize, stdin);
                parse_line_into_words(inputWord7, 1, &words_array);

                int count = StrList_count(StrList, words_array[0]);
                free(words_array[0]);
                free(words_array);
                free(inputWord7);


                printf("%d\n", count);
                scanf("\n");
                break;

            // Delete all the instances of a string in the list
            case 8:
                bufsize = 0;
                char *inputWord8 = NULL;
                scanf("\n");

                getline(&inputWord8, &bufsize, stdin);
                parse_line_into_words(inputWord8, 1, &words_array);

                StrList_remove(StrList, words_array[0]);
                free(words_array[0]);
                free(words_array);
                free(inputWord8);

                scanf("\n");

                break;

            // Delete string at an index in the list
            case 9:
                scanf("\n%d\n", &index);
                StrList_removeAt(StrList, index);
                break;

            // Reverse the list
            case 10:
                StrList_reverse(StrList);
                break;

            // Delete the list
            case 11:
                size = StrList_size(StrList);
                for(int i = 0; i < size; i++){
                    StrList_removeAt(StrList, 0);
                }

                break;

            // Sort the list in lexicographic order
            case 12:
                StrList_sort(StrList);
                break;

            // Checking if the list is sorted lexicographic
            case 13:

                sorted = StrList_isSorted(StrList);
                if(sorted == True){
                    printf("true\n");
                }
                else{
                    printf("false\n");
                }
                break;

            // Exit
            case 0:
                StrList_free(StrList);
                return 0;
        }

        scanf("\n");
    }
}

// Getting a line and breaking it to words
void parse_line_into_words(char *line, int num_words, char ***words_array) {

    // Allocate memory for the array of word pointers
    *words_array = malloc(num_words * sizeof(char *));
    if (*words_array == NULL) {
        return;
    }

    int word_index = 0;

    //Break the line according to this token
    char *token = strtok(line, " ");

    while (token != NULL) {

        // Remove the newline character from the token
        token[strcspn(token, "\n")] = '\0';

        // Allocate memory for the word plus '/0'
        (*words_array)[word_index] = malloc((strlen(token) + 1) * sizeof(char));
        if ((*words_array)[word_index] == NULL) {

            // Free previously allocated memory
            for (int i = 0; i < word_index; i++) {
                free((*words_array)[i]);
            }
            free(*words_array);
            *words_array = NULL;
            return;
        }

        // Copy the token into the words array
        strcpy((*words_array)[word_index], token);

        // Get next token
        token = strtok(NULL, " ");
        word_index++;
    }

}


