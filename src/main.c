#include <ncurses.h>
#include <fcntl.h>
#include "fcontent.h"

enum command
{
	COMMAND_UP,
	COMMAND_DOWN,
	COMMAND_LEFT,
	COMMAND_RIGHT
} command;

int main(int argc, char** argv)
{
	initscr();

	fcontent* fc = fcontent_new();

	char c;
	while ((c = getchar()) != EOF)
	{
		fcontent_push(fc, c);
	}

	printw(fc->text);
	refresh();

	while (c = getchar())
	{
		
	}

	return 0;
}
