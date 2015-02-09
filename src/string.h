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

/*
 * ned_(w)string_new() - initiate a new string
 */
ned_generic_string ned_generic_string_new(size_t width);
ned_string ned_string_new();
ned_wstring ned_wstring_new();

/*
 * ned_(w)string_set(str, chars, count) - set a string's content
 */
void ned_generic_string_set(ned_generic_string str, void* chars, size_t count);
void ned_string_set(ned_string str, char* chars, size_t count);
void ned_wstring_set(ned_wstring str, wchar_t* chars, size_t count);

/*
 * ned_(w)string_insert(str, c, index) - insert a character at an index
 */
void ned_generic_string_insert(ned_generic_string str, void* c, size_t index);
void ned_string_insert(ned_string str, char c, size_t index);
void ned_wstring_insert(ned_wstring str, wchar_t c, size_t index);

/*
 * ned_(w)string_push(str, c) - push a character to the end of the string
 */
void ned_generic_string_push(ned_generic_string str, void* c);
void ned_string_push(ned_string str, char c);
void ned_wstring_push(ned_wstring str, wchar_t c);

/*
 * ned_(w)string_get(str, index) - get the character at an index
 */
void* ned_generic_string_get(ned_generic_string str, size_t index);
char ned_string_get(ned_string str, size_t index);
wchar_t ned_wstring_get(ned_wstring str, size_t index);

/*
 * ned_(w)string_get_all(str) - get all the characters in the string
 */
void* ned_generic_string_get_all(ned_generic_string str);
char* ned_string_get_all(ned_string str);
wchar_t* ned_wstring_get_all(ned_wstring str);

#endif
