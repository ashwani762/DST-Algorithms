#include "main.h"

//Entry Point of Program

int main(){
	/*	
	|-------------------------------------------------------------------|	
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|	
	|																	|
	|							DST Algorithm							|	
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|	
	|																	|
	|																	|	
	|																	|
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
	//End ncurses
	endwin();

	//Finally, return 0
	return 0;
}
