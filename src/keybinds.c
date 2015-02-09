#include "keybinds.h"

ned_keybind ned_keybind_new(wchar_t key, NED_COMMAND command)
{
	ned_keybind* bind = malloc(sizeof(ned_keybind));
	bind->key = key;
	bind->command = command;

	return *bind;
}

ned_keybinds* ned_keybinds_new()
{
	ned_keybinds* kb = malloc(sizeof(ned_keybinds));
	kb->binds = NULL;
	kb->length = 0;

	return kb;
}

void ned_keybinds_push(ned_keybinds* kb, ned_keybind bind)
{
	kb->length += 1;
	size_t l = kb->length;
	kb->binds = realloc(kb->binds, sizeof(ned_keybind) * l);

	kb->binds[l+1] = bind;
}

ned_keybind ned_keybinds_get(ned_keybinds* kb, size_t index)
{
	return kb->binds[index];
}
