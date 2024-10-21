#include<stdio.h>
#include "bubbleSort.h"

void insertData(STUD_Data *stud){
	for(int i = 0; i < SIZE; i++){
		printf("Enter data of student%d (Name roll_no Marks): ", i+1);
		scanf("%s %d %d", stud[i].name, &stud[i].roll_no, &stud[i].marks);
		scanf("%*c");
	}
		
}
