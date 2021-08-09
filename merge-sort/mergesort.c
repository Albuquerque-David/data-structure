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
void merge_sort(int *array, int array_size);
void merge_sort_rec(int *array,int *aux, int begin, int end);
void merge(int *array, int *aux, int begin, int middle, int end);

int main(int argc, char** argv)
{   
    
    int array_size = TAM;
    int quant = 0;
    int i = 0;
    int number;
    int *array = (int *)malloc(sizeof(int) * array_size);

    while(scanf("%d",&number) == 1)
    { 
        array[i] = number;
        i++;
        quant++;
        if( quant >= array_size )
            overflow(&array, &array_size);
    } 

    merge_sort(array, quant);

    for(i = 0 ; i < quant; i++){
        printf("%d\n",array[i]);
    }

    return 0;

}

void overflow(int **array,int *array_size)
{
    *array = (int *)realloc(*array, sizeof(int) * (*array_size) * OVERFLOW_MULTIPLIER);
    *array_size *= OVERFLOW_MULTIPLIER;
}

void merge_sort(int *array, int array_size)
{
    int *aux = (int *)malloc(sizeof(int) * array_size);
    merge_sort_rec(array, aux, 0, array_size-1);
}

void merge_sort_rec(int *array,int *aux, int begin, int end)
{
    int middle = begin + (end - begin) / 2;

    if (begin >= end)
        return;

    merge_sort_rec(array, aux, begin, middle);
    merge_sort_rec(array, aux, middle + 1, end);
    merge(array, aux, begin, middle, end);
}

void merge(int *array, int *aux, int begin, int middle, int end)
{

    int left, right, i;

   for(left = begin, right = middle + 1, i = begin; left <= middle && right <= end; i++) {
      if(array[left] <= array[right])
         aux[i] = array[left++];
      else
         aux[i] = array[right++];
   }
   
   while(left <= middle)    
      aux[i++] = array[left++];

   while(right <= end)   
      aux[i++] = array[right++];

   for(i = begin; i <= end; i++)
      array[i] = aux[i];
    
}