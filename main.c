#include "main.h"

int main(){
	/*	
	|-------------------------------------------------------------------|	
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|	
	|									|								|
	|									|								|	
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|
	|									|								|	
	|									|								|
	|-------------------------------------------------------------------|	
	|Enter The Command:					|								|
	|-------------------------------------------------------------------|

	*/	

	//ncurses initialisation
	initscr();
	//Start color functionality
	start_color();
	
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	print_in_middle(stdscr, LINES / 2, 0, 0, "DST Algorithms");
	getch();
	
	//Start Displaying Algorithms Menu
	show_windows();
	
	refresh();
	
	//get input before closing ncurses window
	getch();
	//End ncurses
	endwin();

	//Finally, return 0
	return 0;
}



/*#include <stdio.h>
int main() {
    FILE *fp;
    char c;
    fp = fopen(__FILE__,"r");
    do {
         c = getc(fp);
         putchar(c);
    }
    while(c != EOF);
    fclose(fp);
    return 0;
}*/