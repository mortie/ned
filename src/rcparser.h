#ifndef RCPARSER_H
#define RCPARSER_H

#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>

#include "keybinds.h"

/*
 * rcparse(rcstr) - parse configuration string
 */

ned_keybinds* rcparse(wchar_t* rcstr);

#endif
