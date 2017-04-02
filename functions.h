#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 10

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
void print_menu(WINDOW *menu_win,int highlight, char *choice[],int choices);
int show_menu(char *menu[],int no_of_choices, char *string);
void theory(char *fp,char *string);
void instruction();
void init(char *string);
void showfile(char *source, char *string);