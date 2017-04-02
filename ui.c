#include "ui.h"

char *choices[]={
	"Search",
	"Sort",
	"Array",
	"Linked List",
	"Exit"
};

char *search[]={
	"Linear",
	"Binary",
	"Go Back"
};

char *sort[]={
	"Bubble Sort",

};

int n_choices = sizeof(choices) / sizeof(char *);
int n_search_choices = sizeof(search) / sizeof(char *);

// Driving Function
void show_windows(){
	int choice;
	choice = show_menu(choices,n_choices,"DST Algorithms");
	if(choice == 1){
		display_search_menu();
	}
}

void display_search_menu(){
	int choice;
	choice = show_menu(search, n_search_choices,"Search");
	switch(choice){
		case 1:linear();
				break;
		case 2:binary();
				break;
		case 3:show_windows();
				break;
		default:printw("Will not come to default ever!!!");
	}
}
