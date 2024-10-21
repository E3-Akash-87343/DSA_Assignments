#include <stdio.h>
#define SIZE 6
#define SWAP(a,b); int temp=a; a=b; b=temp;
void bubbleSort(int arr[SIZE], int *, int *);
void printfunc(int arr[SIZE]);
int is_swapped;

int main(){
	int arr[SIZE] = {30, 20,60, 50, 10, 40};
	int iterations = 0, comparisons = 0;

	//int arr[SIZE] = {10,20,30,40,50,60};
	printfunc(arr);
	
	bubbleSort(arr, &iterations, &comparisons);

	printfunc(arr);

	printf("Iteration: %d\n", iterations);
	printf("Comparisons: %d\n",comparisons);

	return 0;
}

void printfunc(int arr[SIZE]){
	for(int i = 0; i < SIZE; i++)
		printf("%4d", arr[i]);
	printf("\n");
}


void bubbleSort(int arr[SIZE], int *iteration, int *comparison){
	for(int itr = 0; itr < SIZE-1; itr++){
		*iteration = *iteration + 1;
		for(int pos = 0; pos < SIZE-1-itr; pos++){
			*comparison = *comparison + 1;
			if(arr[pos] > arr[pos + 1]){
				SWAP(arr[pos], arr[pos + 1])
				is_swapped = 1;
			}
		}
		if(is_swapped == 0)
			break;
	}
}
