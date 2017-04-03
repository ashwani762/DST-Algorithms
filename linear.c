#include "linear.h"


char *source_linear = "algo/linear.txt";
char *theory_linear = "theory/linear.txt";
char *string_linear = "Linear Search";
extern void display_search_menu();

void linear(){
	call(string_linear,theory_linear,source_linear,linear_execute,display_search_menu);
}

void linear_execute(){
	clear();
	init(string_linear);
	echo();

	//Logic of Linear Search
	int n;
	printw("Enter the size of array: ");
	scanw("%d",&n);


	int a[n],item,i,flag = 0;

	printw("Enter the elements of the array:\n");
	for(i=0;i<n;i++){
		scanw("%d",&a[i]);
		echo();

	}

	printw("Enter the elemnt to search for: ");
	scanw("%d",&item);
	echo();

	for(i=0;i<n;i++){
		if(a[i] == item){
			printw("Element found at location %d", i+1);
			flag = 1;
		}
	}

	if(flag == 0){
		printw("Element Not found");
	}

	//Logic End

	instruction();

}

