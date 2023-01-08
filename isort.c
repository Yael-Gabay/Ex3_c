#include <stdio.h>
#define SIZE 50

/**
 * The function shift the elements of an array arr by one position to the right, starting from a specified index i. 
 * It does this by using a loop to iterate through the array starting from index i, 
 * and for each iteration it assigns the value of the element at the previous index to the current index.
*/
void shift_element(int *arr, int i)
{   
    for(int j = i; j > 0 ; j--) 
    {
        *(arr + j) = *(arr + (j - 1));  
    }
   
}

/**
 * The function sorts an array of integers in ascending order using the insertion sort algorithm. 
 * It iterates through the array, compares the value of each element to the values of the previous elements, 
 * and shifts elements to the right as needed. 
 * The function modifies the original array in place.
*/
void insertion_sort(int *arr, int len)
{

    for (int i = 1; i < len; i++)
    {
        int key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && *(arr + j) > key)
        --j;

        shift_element((arr + j), (i - j));
        *(arr + j + 1) = key;
    }
}

/**
 * The function reads in a series of integers from the user, 
 * sorts them in ascending order using the insertion_sort() function, 
 * and then prints the sorted array with each element separated by a ',' 
*/
int main()
{
    int arr [SIZE];

    for (int i = 0; i < SIZE; i++)
    {   
        scanf("%d,", arr + i);
    }

    insertion_sort(arr, SIZE);

    for(int i = 0; i < SIZE - 1; i++)
    {
        printf("%d,", *(arr + i));
    }
    printf("%d", *(arr + SIZE - 1));
    printf("\n");

    return 0;
}