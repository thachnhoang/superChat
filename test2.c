#include <panel.h>

int main()
{	
	WINDOW *my_wins[5];
	PANEL  *my_panels[5];
	int lines = 25, cols = 110, y = 1, x = 4, i;
	char str[100];
	

	initscr();
	cbreak();
	echo();
	start_color();

	/* Initialize all the colors */

	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);

	/* Create windows for the panels */
	//              (lines, cols, y, x);
	my_wins[0] = newwin(34, 109, y, x); // layout window
	my_wins[1] = newwin(13, 105, 3, 6); // public chat window
	my_wins[2] = newwin(3, 105, 16, 6); // enter text window
	my_wins[3] = newwin(14, 74, 20, 6); // chat room window
	my_wins[4] = newwin(14, 25, 20, 86); // user window
	//my_wins[5] = newwin(15, 24, 18, 87);
	//my_wins[1] = newwin(lines, cols, y + 1, x + 5);
	//my_wins[2] = newwin(lines, cols, y + 2, x + 10);

	/* 
	 * Create borders around the windows so that you can see the effect
	 * of panels
	 */
	for(i = 0; i < 5; ++i)
		box(my_wins[i], 0, 0);

	/* Attach a panel to each window */

	my_panels[0] = new_panel(my_wins[0]); // layout window		
	my_panels[1] = new_panel(my_wins[1]); // public chat window
	my_panels[2] = new_panel(my_wins[2]); // enter text window
	my_panels[3] = new_panel(my_wins[3]); // chat room window
	my_panels[4] = new_panel(my_wins[4]); // user window
	//my_panels[5] = new_panel(my_wins[5]);	/* Push 1, order: stdscr-0-1 */
	//my_panels[2] = new_panel(my_wins[2]); 	/* Push 2, order: stdscr-0-1-2 */

	/* Update the stacking order. 2nd panel will be on top */
	update_panels();
-
	/* Show it on the screen */
	doupdate();

	
	mvprintw(2, 7, "Public Chat"); // print text "Public Chat" at this location
	mvprintw(19, 8, "Chat Room"); // print text "Chat Room" at this location
	mvprintw(19, 96, "Users"); // print text "Users" at this location

	// Enter puclic chat text here at this location inside panel[2]
	mvgetstr(17,7, str);

	
	refresh();
	getch();
	endwin();

	return 0;
}