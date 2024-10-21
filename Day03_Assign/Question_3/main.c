#include<stdio.h>
#include "bubbleSort.h"


int main(){
	STUD_Data student[SIZE];
	
	insertData(student);
	printf("Student data:\n%-10s %-7s %-5s\n", "Name", "Roll_no", "Marks");
	printfunc(student);

	bubbleSort(student);

	printf("Student data sorted by marks:\n%-10s %-7s %-5s\n", "Name", "Roll_no", "Marks");
	printfunc(student);
	return 0;
}

