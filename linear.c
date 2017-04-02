#include "linear.h"

char *source_string = "algo/linear.txt";
char *theory_string = "theory/linear.txt";
char *string = "Linear Search";


void linear(){
	int ch;
	clear();
	init(string);
	instruction();
	
	do{
		ch = getch();
		switch(ch){
			case 'z':theory(theory_string,string);
						break;
			case 'x':showfile(source_string,string);
						break;
			case 'c':execute();
						break;
			case 'q':display_search_menu();
		}

	}while(ch!='q');
}

void execute(){
	clear();
	init(string);
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

