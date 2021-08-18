/**
 * 
 * Utils
 * Author: github.com/Albuquerque-David
 * Under Apache License Version 2.0, January 2004
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{   
    FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;

    if(fp == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while( fscanf(fp, "%d", & number ) == 1 ){
    }
}