#ifndef RCPARSER_H
#define RCPARSER_H

//size_t, NULL
#include <stddef.h>

//realloc
#include <stdlib.h>

//wcscmp
#include <wchar.h>

#include "keybinds.h"

keybinds* rcparse(wchar_t* rcstr);

#endif
