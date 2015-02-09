#ifndef NED_STRING_H
#define NED_STRING_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ned_generic_string
{
	void* text;
	size_t length;
	size_t width;
	size_t allocd;
} ned_generic_string;

typedef ned_generic_string ned_string;
typedef ned_generic_string ned_wstring;

ned_generic_string ned_generic_string_new(size_t width);
ned_string ned_string_new();
ned_string ned_wstring_new();
void ned_generic_string_set(ned_generic_string str, void* chars, size_t count);
void ned_generic_string_insert(ned_generic_string str, void* c, size_t index);
void ned_generic_string_push(ned_generic_string str, void* c);
void ned_generic_string_push(ned_generic_string str, void* c);
void ned_string_push(ned_string str, char c);
void ned_wstring_push(ned_wstring str, wchar_t c);
void* ned_generic_string_get(ned_generic_string str, size_t index);
char ned_string_get(ned_string str, size_t index);
void* ned_generic_string_get_all(ned_generic_string str);
void ned_generic_string_free(ned_generic_string str);



#endif
