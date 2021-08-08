/**
 * 
 * Merge Sort
 * Author: github.com/Albuquerque-David
 * Under Apache License Version 2.0, January 2004
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define TAM 8
#define OVERFLOW_MULTIPLIER 2

void overflow(int **array,int *array_size);
void merge_sort(int *array, begin, end);
void merge(int *array, begin, middle, end);

int main(void)
{
    
    int array_size = TAM;
    int quant = 0;
    int i = 0;
    int *array = (int *)malloc(sizeof(int) * array_size);

    while(i < 20){
        scanf("%d", &array[i]);-
        quant++;
        i++;
        if( quant >= array_size )
            overflow(&array, &array_size);
    }

    for(i = 0 ; i < quant; i++){
        printf("%d\n",array[i]);
    }

    return 0;

}

void overflow(int **array,int *array_size)
{
    int i;
    int *new_array = (int *)malloc(sizeof(int) * (*array_size) * OVERFLOW_MULTIPLIER);


    for(i = 0; i < *array_size; i++){
        new_array[i] = (*array)[i];
    }

    *array_size *= OVERFLOW_MULTIPLIER;
    free(*array);
    *array = new_array;
}

void merge_sort(int *array, begin, end)
{
    if (begin >= end)
        return;

    int middle = begin + (end - begin) / 2;
    merge_sort(array, begin, middle);
    merge_sort(array, middle + 1, end);
    merge(array, begin, middle, end);
}

void merge(int *array, begin, middle, end)
{

    int left, right, k;

}