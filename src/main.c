#define _GNU_SOURCE

#include <ncurses.h>
#include <locale.h>
#include <fcntl.h>
#include <wchar.h>

#include "rcparser.h"
#include "nstring.h"

//convert utf 8 to ned_wstring
static ned_wstring utf8towstring(ned_string utf8str)
{
	ned_wstring wstr = ned_wstring_new();
	size_t i = 0;
	char c;
	while ((c = ned_string_get(utf8str, i)) != 0);
	{
		
	}

	return wstr;
}

int main(int argc, char** argv)
{
	//initiate ncurses
	setlocale(LC_ALL, "");
	initscr();

	//read input from stdin
	ned_string str = ned_string_new();
	char c;
	while ((c = getchar()) != EOF)
	{
		ned_string_push(str, c);
	}

	ned_wstring input = utf8towstring(str);

	//print
	addwstr(ned_wstring_get_all(input));
	refresh();

	//read user input
	while ((c = getchar()))
	{
		
	}

	return 0;
}
