#include "binary.h"

char *source_binary = "algo/linear.txt";
char *theory_binary = "theory/linear.txt";
char *string_binary = "Binary Search";


void binary(){
	int ch;
	clear();
	init(string_binary);
	instruction();
	
	do{
		ch = getch();
		switch(ch){
			case 'z':theory(theory_binary, string_binary);
						break;
			case 'x':showfile(source_binary, string_binary);
						break;
			case 'c':binary_execute();
						break;
			case 'q':display_search_menu();
		}

	}while(ch!='q');
}

void binary_execute(){
	clear();
	init(string_binary);
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

