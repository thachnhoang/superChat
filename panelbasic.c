#include <panel.h>

int main()
{	
	WINDOW *my_wins[2];
	PANEL  *my_panels[2];
	int lines = 25, cols = 110, y = 2, x = 4, i;
	char str[80];
	

	initscr();
	cbreak();
	echo();
	start_color();

	/* Initialize all the colors */
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);


	/* Create windows for the panels */
	//              (lines, cols, y, x);
	my_wins[0] = newwin(30, 110, y, x);
	my_wins[1] = newwin(3, 20, 14, 49);
	//my_wins[1] = newwin(lines, cols, y + 1, x + 5);
	//my_wins[2] = newwin(lines, cols, y + 2, x + 10);

	/* 
	 * Create borders around the windows so that you can see the effect
	 * of panels
	 */
	for(i = 0; i < 2; ++i)
		box(my_wins[i], 0, 0);

	/* Attach a panel to each window */ 	/* Order is bottom up */
	my_panels[0] = new_panel(my_wins[0]); 	/* Push 0, order: stdscr-0 */
	my_panels[1] = new_panel(my_wins[1]); 	/* Push 1, order: stdscr-0-1 */
	//my_panels[2] = new_panel(my_wins[2]); 	/* Push 2, order: stdscr-0-1-2 */

	/* Update the stacking order. 2nd panel will be on top */
	update_panels();
-
	/* Show it on the screen */
	doupdate();

	// turn on color
	attron(COLOR_PAIR(1));
	mvprintw(5, 55, "SuperChat");
	attroff(COLOR_PAIR(1)); // turn off color
	attron(COLOR_PAIR(2));
	mvprintw(13, 55, "Username");
	attroff(COLOR_PAIR(2));

	// Enter username here at this location
	//mvprintw(15,55 ,"Enter the text here:");
	mvgetstr(15,50, str);
	
	refresh();
	getch();
	endwin();

	return 0;
}