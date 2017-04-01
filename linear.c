#include "linear.h"

char *string = "Linear Search";
char *ins = "z -> Theory, x -> Code, c -> Execute, q -> Back to the future";

void linear(){
	int ch;
	clear();
	init();
	instruction();
	
	do{
		ch = getch();
		switch(ch){
			case 'z':theory();
						break;
			case 'x':showfile();
						break;
			case 'c':execute();
						break;
			case 'q':display_search_menu();
		}

	}while(ch!='q');
}

void instruction(){
	move(23,40-(strlen(ins)/2));
	printw("%s",ins);
}

void init(){
	move(0,40-(strlen(string)/2));
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	printw("%s",string);
	attroff(COLOR_PAIR(1));

	move(1,0);
}

void showfile(){
	FILE *file;
	int ch;

	file = fopen("algo/linear.txt", "r");
  	if(file == NULL)
  	{
    	perror("Cannot open file");
    	exit(1);
  	}
	clear();
	init();
	while((ch = fgetc(file)) != EOF){
		printw("%c",ch);

	}
	instruction();
	fclose(file);
}

void execute(){
	clear();
	init();
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

void theory(){
	FILE *file;
	int ch;

	file = fopen("theory/linear.txt", "r");
  	if(file == NULL)
  	{
    	perror("Cannot open file");
    	exit(1);
  	}
	clear();
	init();
	while((ch = fgetc(file)) != EOF){
		printw("%c",ch);
	}
	instruction();
	fclose(file);
}