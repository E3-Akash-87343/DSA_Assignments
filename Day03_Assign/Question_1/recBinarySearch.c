#include<stdio.h>
#define SIZE 9
int comp_count;
int recBinarySearch(int arr[SIZE], int, int, int);

int main(){
	int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
	int result,key;

	printf("Enter a key: ");
	scanf("%d", &key);

	result = recBinarySearch(arr, key, 0, SIZE-1);
	if(result == -1)
		printf("Invalid key!\n");
	else
		printf("Key found at index: %d\n", result);
	printf("Compare count: %d\n", comp_count);

	return 0;
}


int recBinarySearch(int arr[SIZE], int key, int left, int right){
	int mid, res;

	mid = (left + right)/2;
	comp_count++;
	if(left > right)
		return -1;
	
	if(key == arr[mid])
		return mid;

	if(key < arr[mid])
		res = recBinarySearch(arr, key, left, mid-1);
	else
		res = recBinarySearch(arr, key, mid+1, right);
	
	return res;
}


