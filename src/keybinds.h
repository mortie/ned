#ifndef BINDS_H
#define BINDS_H

//size_t, NULL
#include <stddef.h>

//malloc, realloc
#include <stdlib.h>

typedef enum COMMAND
{
	COMMAND_UP,
	COMMAND_DOWN,
	COMMAND_LEFT,
	COMMAND_RIGHT,
	COMMAND_SAVE
} COMMAND;

typedef struct keybind
{
	wchar_t key;
	COMMAND command;
} keybind;

typedef struct keybinds
{
	keybind* binds;
	size_t length;
} keybinds;

keybind keybind_new(wchar_t key, COMMAND command);

keybinds* keybinds_new();

void keybinds_push(keybinds* kb, keybind bind);

keybind keybinds_get(keybinds* kb, size_t index);

#endif
