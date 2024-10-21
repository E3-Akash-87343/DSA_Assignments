#define SIZE 10
typedef struct{
	char name[10];
	int roll_no;
	int marks;

}STUD_Data;

#define SWAP(a,b); STUD_Data temp=a; a=b; b=temp;
void bubbleSort(STUD_Data *);
void printfunc(STUD_Data *);
extern int is_swapped;

void insertData(STUD_Data *stud);


