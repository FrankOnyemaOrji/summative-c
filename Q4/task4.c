#include <stdio.h>
#include <stdlib.h>

/*Q4
Given an array of students's grades
grades = {23, 45, 31, 36, 32, 26, 29, 30, 33, 35, 28,37,19,20}.
You are required to write a program that completes the ascending order
and the descending order of the grades. To complete the task you are
required to use function pointers. Upon running the program, the user is
expected to enter order choice (asc for ascending and desc for descending).

Note that, as you are handling ordering functions, function pointer(s)
are used.
*/

#define SIZE 14

void sort(int *grades, int size, int ascending);


int main(void) 
{
    int grades[SIZE] = {23, 45, 31, 36, 32, 26, 29, 30, 33, 35, 28, 37, 19, 20};

    char order[4];

    printf("Enter order choice (asc for ascending and desc for descending):\n");

    scanf("%3s", order);

    if (order[0] == 'a') 
    { 
	    // If the first character is 'a', sort in ascending order

        sort(grades, SIZE, 1);

    } else if (order[0] == 'd') { 
	    // If the first character is 'd', sort in descending order
        
	    sort(grades, SIZE, 0);
    } else 
    {

        printf("Invalid choice\n");

        return 1; // Return with error
    }

    for (int i = 0; i < SIZE; i++) 
    {
        printf("%d ", grades[i]);
    }

    printf("\n");

    return 0;
}

void sort(int *grades, int size, int ascending) 
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
	{
            if ((ascending && grades[j] > grades[j + 1]) || (!ascending && grades[j] < grades[j + 1])) 
	    {
                temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }
}

