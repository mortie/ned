#include "rcparser.h"

static void makeKeybind(ned_keybinds* kb, wchar_t key, wchar_t* val)
{
	if (wcscmp(val, L"UP"))
		ned_keybinds_push(kb, ned_keybind_new(key, NED_COMMAND_UP));
	else if (wcscmp(val, L"DOWN"))
		ned_keybinds_push(kb, ned_keybind_new(key, NED_COMMAND_DOWN));
	else if (wcscmp(val, L"LEFT"))
		ned_keybinds_push(kb, ned_keybind_new(key, NED_COMMAND_LEFT));
	else if (wcscmp(val, L"RIGHT"))
		ned_keybinds_push(kb, ned_keybind_new(key, NED_COMMAND_RIGHT));
	else if (wcscmp(val, L"SAVE"))
		ned_keybinds_push(kb, ned_keybind_new(key, NED_COMMAND_SAVE));
}

ned_keybinds* ned_rcparse(wchar_t* rcstr)
{
	ned_keybinds* kb = ned_keybinds_new();

	size_t i = 0;
	wchar_t c = NULL;
	wchar_t prev = NULL;

	wchar_t key = 0;
	wchar_t* val = NULL;
	size_t vallen = 0;

	while (1)
	{
		c = val[i];

		if (c == L'=')
		{
			key = prev;
		}
		else if (key != 0 && c != L'\n')
		{
			++vallen;
			val = realloc(val, vallen);
			val[vallen-1] = c;
		}
		else if (c == L'\n')
		{
			val = realloc(val, vallen+1);
			val[vallen] = 0;

			makeKeybind(kb, key, val);

			key = 0;
			val = NULL;
			vallen = 0;
		}

		prev = c;
		++i;
	}

	return kb;
}
