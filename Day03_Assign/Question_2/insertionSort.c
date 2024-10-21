#include<stdio.h>
#define SIZE 6

void printfunc(int arr[]);
void insertionSort(int arr[], int *, int *);	

int main(){
	int arr[SIZE] = {55, 44, 22, 66, 11, 33};
	int iterations = 0, comparisons = 0;
	printfunc(arr);

	insertionSort(arr, &iterations, &comparisons);	
	
	printfunc(arr);
	printf("Iterations = %d\nComparisons = %d\n", iterations, comparisons);

	return 0;
}


void printfunc(int arr[SIZE]){
	printf("array : ");
	for(int i=0; i<SIZE; i++)
		printf("%4d", arr[i]);
	printf("\n");
}

void insertionSort(int arr[SIZE], int *iter, int *comp){	
	int i, j, temp;	
	for(i=1; i<SIZE; i++){
		*iter = *iter + 1;
		temp = arr[i];
		for(j=i-1; j>=0 && temp< arr[j]; j--){
				*comp = *comp + 1;
				arr[j+1]=arr[j];
			}
		arr[j+1] = temp;
		}
}
