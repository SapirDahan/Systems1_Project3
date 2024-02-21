#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

void parse_line_into_words(char*, int, char***);


#define True 1

int main() {

    struct _StrList *StrList;
    StrList = StrList_alloc();


   int number;
   char *data = "";
   size_t bufsize = 0;  // getline will allocate the buffer
   int index;
   int times;
   size_t size;


    // Get chars from the user until he is asking to stop
    while(True){

        // Scan a number
        scanf("%d", &number);

        // Checking witch char we got
        switch (number) {

            case 1:
                // Scan a number the numbers of times to inserts strings;
                scanf("\n%d\n", &times);

                char *inputLine = NULL;
                bufsize = 0;

                getline(&inputLine, &bufsize, stdin);
                char **words_array;

                parse_line_into_words(inputLine, times, &words_array);

                for(int i = 0; i < times; i++){
                    data = words_array[i];
//                    printf("%s data\n", data);
                    StrList_insertLast(StrList, data);
                    free(words_array[i]);
                }
                free(words_array);


                break;

            case 2:
                scanf(" %d  %s", &index, data);
                StrList_insertAt(StrList, data, index);
                break;

            case 3:
                StrList_print(StrList);
                break;

            case 4:
                printf(" %zu", StrList_size(StrList));
                break;

            case 5:
                scanf(" %d", &index);
                StrList_printAt(StrList, index);
                break;

            case 6:
                printf(" %d", StrList_printLen(StrList));
                break;

            case 7:
                scanf(" %s", data);
                StrList_count(StrList, data);
                break;

            case 8:
                scanf(" %s", data);
                StrList_remove(StrList, data);
                break;

            case 9:
                scanf(" %d", &index);
                StrList_removeAt(StrList, index);
                break;

            case 10:
                StrList_reverse(StrList);
                break;

            case 11:
                size = StrList_size(StrList);
                for(int i = 0; i < size; i++){
                    StrList_removeAt(StrList, 0);
                }

                break;

            case 12:
                StrList_sort(StrList);
                break;

            case 13:
                StrList_isSorted(StrList);
                break;

            case 0:
                printf("\n");
                //StrList_free(StrList);
                return 0;
        }

        scanf("\n");
    }
}

void parse_line_into_words(char *line, int num_words, char ***words_array) {
    // Allocate memory for the array of word pointers
    *words_array = malloc(num_words * sizeof(char *));
    if (*words_array == NULL) {
        return;
    }

    int word_index = 0;
    char *token = strtok(line, " ");

    while (token != NULL) {

        // Remove the newline character from the token, if present
        token[strcspn(token, "\n")] = '\0';

        // Allocate memory for the word plus a null terminator
        (*words_array)[word_index] = malloc((strlen(token) + 1) * sizeof(char));
        if ((*words_array)[word_index] == NULL) {
            // Handle memory allocation failure
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


