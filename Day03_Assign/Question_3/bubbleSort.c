#include <stdio.h>
#include "bubbleSort.h"

int is_swapped;

void printfunc(STUD_Data *arr){
	for(int i = 0; i < SIZE; i++)
		printf("%-10s %-7d %-5d\n", arr[i].name, arr[i].roll_no, arr[i].marks);
	printf("\n");
}


void bubbleSort(STUD_Data *arr){
	for(int itr = 0; itr < SIZE-1; itr++){
		for(int pos = 0; pos < SIZE-1-itr; pos++){
			if(arr[pos].marks < arr[pos + 1].marks){
				SWAP(arr[pos], arr[pos + 1])
				
				is_swapped = 1;
			}
		}
		if(is_swapped == 0)
			break;
	}
}
