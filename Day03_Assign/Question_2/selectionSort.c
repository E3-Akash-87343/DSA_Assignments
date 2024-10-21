#include<stdio.h>

#define swap(a,b); int temp=a; a=b; b=temp;
#define SIZE 6
void printfunc(int arr[]);
void selectionSort(int arr[], int *, int *);


int main(){
	int arr[SIZE] = {30, 20, 60, 50, 10, 40};
 	int iterations = 0, comparisons = 0;
	printf("Before sort:\n");
	printfunc(arr);
	
	selectionSort(arr, &iterations, &comparisons);	

	printf("After sort:\n");
	printfunc(arr);

	printf("Iterations= %d\nComparions=%d\n", iterations, comparisons);
	return 0;
}


void printfunc(int arr[SIZE]){
	for(int i=0; i<SIZE; i++)
		printf("%4d",arr[i]);
	printf("\n");
}

void selectionSort(int arr[SIZE], int *iter, int *comp){	
	for(int sel_pos = 0; sel_pos < SIZE - 1; sel_pos++){
		*iter = *iter + 1;
		for(int pos = sel_pos + 1; pos < SIZE; pos++){
			*comp = *comp + 1;
			if(arr[sel_pos] > arr[pos]){
				swap(arr[sel_pos], arr[pos])
			}
		}
	}
}


