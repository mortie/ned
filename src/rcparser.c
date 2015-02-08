#include "rcparser.h"

static void makeKeybind(keybinds* kb, wchar_t key, wchar_t* val)
{
	if (wcscmp(val, L"UP"))
		keybinds_push(kb, keybind_new(key, COMMAND_UP));
	else if (wcscmp(val, L"DOWN"))
		keybinds_push(kb, keybind_new(key, COMMAND_DOWN));
	else if (wcscmp(val, L"LEFT"))
		keybinds_push(kb, keybind_new(key, COMMAND_LEFT));
	else if (wcscmp(val, L"RIGHT"))
		keybinds_push(kb, keybind_new(key, COMMAND_RIGHT));
	else if (wcscmp(val, L"SAVE"))
		keybinds_push(kb, keybind_new(key, COMMAND_SAVE));
}

keybinds* rcparse(wchar_t* rcstr)
{
	keybinds* kb = keybinds_new();

	size_t i = 0;
	wchar_t c = NULL;
	wchar_t prev = NULL;

	wchar_t key = NULL;
	wchar_t* val = NULL;
	size_t vallen = 0;

	while (1)
	{
		c = val[i];

		if (c == L'=')
		{
			key = prev;
		}
		else if (key != NULL && c != L'\n')
		{
			++vallen;
			val = realloc(val, vallen);
			val[vallen-1] = c;
		}
		else if (c == L'\n')
		{
			val = realloc(val, vallen+1);
			val[vallen] = NULL;

			makeKeybind(kb, val, key);

			key = NULL;
			val = NULL;
			vallen = 0;
		}

		prev = c;
		++i;
	}

	return kb;
}
