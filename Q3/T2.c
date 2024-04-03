#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Task 2:
*
* Looking at the list of all candidates from candidates.txt file,
* some candidates appear more than once hence there is a need remove
* all duplicates and only keep unique candidates.
* Write a program that will take candidates and remove all duplicate names
* Use redirection or pipe to save the output of the executed program into
* answer file named unique_candidate.txt
*/


/**
* Compile:
*      gcc -Wall -Werror -Wextra -pedantic task2.c -o unique_candidates
*
* Usage with pipes and redirection:
*      cat summative/candidates | ./unique_candidates > unique_candidate.txt
*
* will save the output of the program into unique_candidate.txt
*/

#define MAX_NAME_LENGTH 256
#define MAX_CANDIDATES 1000 // Assuming a realistic maximum number of unique candidates

int main(void) {
    char tempName[MAX_NAME_LENGTH];
    char *uniqueNames[MAX_CANDIDATES];
    int totalUnique = 0;

    while (fgets(tempName, MAX_NAME_LENGTH, stdin) != NULL) {
        tempName[strcspn(tempName, "\n")] = 0; // More robust newline removal

        int isDuplicate = 0;
        for (int i = 0; i < totalUnique && !isDuplicate; i++) {
            if (strcmp(tempName, uniqueNames[i]) == 0) {
                isDuplicate = 1;
            }
        }

        if (!isDuplicate) {
            if (totalUnique < MAX_CANDIDATES) {
                uniqueNames[totalUnique++] = strdup(tempName);
                if (uniqueNames[totalUnique - 1] == NULL) {
                    fprintf(stderr, "Memory allocation failed\n");
                    return EXIT_FAILURE;
                }
            } else {
                fprintf(stderr, "Maximum number of unique candidates exceeded\n");
                break;
            }
        }
    }

    for (int i = 0; i < totalUnique; i++) {
        printf("%s\n", uniqueNames[i]);
        free(uniqueNames[i]);
    }

    return EXIT_SUCCESS;
}
