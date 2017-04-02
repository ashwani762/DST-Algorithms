#include "functions.h"

int startx = 0;
int starty = 0;
char *ins = "z -> Theory, x -> Code, c -> Execute, q -> Back to the future";

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
}

void print_menu(WINDOW *menu_win,int highlight, char *choice[],int choices){
	int x, y, i;
	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i=0;i<choices;++i){
		if(highlight == i+1){
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choice[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else{
			mvwprintw(menu_win, y, x, "%s", choice[i]);			
		}
		++y;
	}
	wrefresh(menu_win);
}


int show_menu(char *menu[],int no_of_choices){
	clear();
	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	noecho();
	cbreak();

	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);

	refresh();

	print_menu(menu_win, highlight, menu, no_of_choices);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = no_of_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == no_of_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_menu(menu_win, highlight, menu, no_of_choices);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}	
	clrtoeol();
	refresh();
	return choice;
}

void theory(char *fp,char *string){
	FILE *file;
	int ch;

	file = fopen(fp, "r");
  	if(file == NULL)
  	{
    	perror("Cannot open file");
    	exit(1);
  	}
	clear();
	init(string);
	while((ch = fgetc(file)) != EOF){
		printw("%c",ch);
	}
	instruction();
	fclose(file);
}

void instruction(){
	move(23,40-(strlen(ins)/2));
	printw("%s",ins);
}

void init(char *string){
	move(0,40-(strlen(string)/2));
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	printw("%s",string);
	attroff(COLOR_PAIR(1));

	move(1,0);
}

void showfile(char *source,char *string){
	FILE *file;
	int ch;

	file = fopen(source, "r");
  	if(file == NULL)
  	{
    	perror("Cannot open file");
    	exit(1);
  	}
	clear();
	init(string);
	while((ch = fgetc(file)) != EOF){
		printw("%c",ch);

	}
	instruction();
	fclose(file);
}