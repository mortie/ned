#include "keybinds.h"

keybind* bind_new(wchar_t key, COMMAND command)
{
	keybind* bind = malloc(sizeof(keybind));
	bind->key = key;
	bind->command = command;

	return bind;
}

keybinds* keybinds_new()
{
	keybinds* kb = malloc(sizeof(keybinds));
	kb->binds = NULL;
	kb->length = 0;

	return kb;
}

void keybinds_push(keybinds* kb, keybind bind)
{
	kb->length += 1;
	size_t l = kb->length;
	kb->binds = realloc(kb->binds, sizeof(keybind) * l);

	kb->binds[l+1] = bind;
}

keybind keybinds_get(keybinds* kb, size_t index)
{
	return kb->binds[index];
}
