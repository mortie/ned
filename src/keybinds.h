#ifndef BINDS_H
#define BINDS_H

#include <stddef.h>
#include <stdlib.h>

typedef enum NED_COMMAND
{
	NED_COMMAND_UP,
	NED_COMMAND_DOWN,
	NED_COMMAND_LEFT,
	NED_COMMAND_RIGHT,
	NED_COMMAND_SAVE
} NED_COMMAND;

typedef struct ned_keybind
{
	wchar_t key;
	NED_COMMAND command;
} ned_keybind;

typedef struct ned_keybinds
{
	ned_keybind* binds;
	size_t length;
} ned_keybinds;

/*
 * ned_keybind_new(key, command) - create a new keybind
 */

ned_keybind ned_keybind_new(wchar_t key, NED_COMMAND command);

/*
 * ned_keybinds_new() - create a new keybind collection
 */

ned_keybinds* ned_keybinds_new();

/*
 * ned_keybinds_push(kb, bind) - add a new keybind to keybind collection
 */

void ned_keybinds_push(ned_keybinds* kb, ned_keybind bind);

/*
 * ned_keybinds_get(kb, index) - get the keybind at an index from a collection
 */

ned_keybind ned_keybinds_get(ned_keybinds* kb, size_t index);

#endif
