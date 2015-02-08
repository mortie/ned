#define _GNU_SOURCE

#include <ncursesw/ncurses.h>
#include <locale.h>
#include <fcntl.h>
#include <wchar.h>

#include "fcontent.h"
//include "rcparser.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	initscr();

	fcontent* fc = fcontent_new();

	wchar_t c;
	while ((c = getchar()) != EOF)
	{
		fcontent_push(fc, c);
	}

	addwstr(fc->text);
	refresh();

	while ((c = getchar()))
	{
		
	}

	return 0;
}
