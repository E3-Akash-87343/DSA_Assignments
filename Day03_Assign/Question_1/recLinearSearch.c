#include <stdio.h>

#define SIZE 9

int recLinearSearch(int arr[], int, int);
int comp_count;

int main(){
	int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
	int result, key;
	int index = 0;
	printf("Enter the key: ");
	scanf("%d", &key);
	 
	result = recLinearSearch(arr, key, index);

	if(result ==  -1){
		printf("Invalid key\n");
	}
	else
		printf("Key found at index: %d\n", result);
	printf("Number of comparisons: %d\n", comp_count);

	return 0;
}


int recLinearSearch(int arr[SIZE], int key, int i){
		int res;

		comp_count++;
		if(arr[i] == key)
			return i;
		else if(i > SIZE-1)
			return -1;
		else 
			res = recLinearSearch(arr, key, ++i);
	
//	return res;

}




