#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>


int main(void){
 int arr[10]; //Initializing everything
 time_t t;
 int* gaps;
 int i, j, k = 1;
 int temp, q;
 printf("Unsorted Array: ");
srand((unsigned)time(&t));
 for(i = 0; i < 10; i++){
    arr[i] = rand() % 100;
    printf("%d, ", arr[i]);
 }
 printf("\n");
while((pow((double)2, (double)k) - 1) < (sizeof(arr)/sizeof(int))){ //Looking for largest gap
    k++;
    }
    gaps = (int*)calloc(k, sizeof(int)); //Dynamically determine number of gaps
    if(gaps == NULL){
        printf("Calloc Failed.\n");
        exit(0);
    }
    for(i=1;i<k;i++){
        gaps[i-1] = (pow((double)2, (double)i) - 1);
    }

    printf("Gaps: "); //Fills array with gaps
    for(i=1; i<k;i++){
        printf("%d, ", gaps[i-1]);
    }
    printf("\n");
    for(i = k-1; i>= 0;i--){ //Starting with the largest gap, sorts the array, ex gap of 7, checks arr[0] and arr[7], then moves on to next smallest gap, until last gap
        for(j=0; j< 10; j++){
            for(q= j + gaps[i]; q < 11; q+= gaps[i]){
                temp = arr[j];
                if(temp > arr[q]){
                    arr[j] = arr[q];
                    arr[q] = temp;
                }
            }
               }
    }

    printf("1-Sorted Array Pre Insertion: "); //Print array after 1 sorted
    for(i = 0; i<10;i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");

 /*   for(i = 0; i<10; i++){ //Insertion sort to move the last 1 sorted elements
        for(j = i+1; j < 11; j++){
                temp = arr[i];
            if(temp > arr[j]){
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }*/

    printf("Final Sorted List: ");
    for(i=0; i<10; i++){
        printf("%d, ", arr[i]);

    }
    printf("\n");
}
