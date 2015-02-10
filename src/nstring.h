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

ned_generic_string* ned_generic_string_new(size_t width);

static inline ned_string* ned_string_new()
{
	ned_string* str = (ned_string*)ned_generic_string_new(sizeof(char));
	return str;
}

static inline ned_wstring* ned_wstring_new()
{
	ned_wstring* str = (ned_wstring*)ned_generic_string_new(sizeof(wchar_t));
	return str;
}

/*
 * ned_(w)string_set(str, chars, count) - set a string's content
 */

void ned_generic_string_set(ned_generic_string* str, void* chars, size_t count);

static inline void ned_string_set(ned_string* str, char* chars, size_t count)
{
	ned_generic_string_set((ned_generic_string*)str, chars, count);
}

static inline void ned_wstring_set(ned_wstring* str, wchar_t* chars, size_t count)
{
	ned_generic_string_set((ned_generic_string*)str, chars, count);
}

/*
 * ned_(w)string_insert(str, c, index) - insert a character at an index
 */

void ned_generic_string_insert(ned_generic_string* str, void* c, size_t index);

static inline void ned_string_insert(ned_string* str, char c, size_t index)
{
	ned_generic_string_insert((ned_generic_string*)str, &c, index);
}

static inline void ned_wstring_insert(ned_wstring* str, wchar_t c, size_t index)
{
	ned_generic_string_insert((ned_generic_string*)str, &c, index);
}

/*
 * ned_(w)string_push(str, c) - push a character to the end of the string
 */

void ned_generic_string_push(ned_generic_string* str, void* c);

static inline void ned_string_push(ned_string* str, char c)
{
	ned_generic_string_push((ned_generic_string*)str, &c);
}

static inline void ned_wstring_push(ned_wstring* str, wchar_t c)
{
	ned_generic_string_push((ned_generic_string*)str, &c);
}

/*
 * ned_(w)string_get(str, index) - get the character at an index
 */

void* ned_generic_string_get(ned_generic_string* str, size_t index);

static inline char ned_string_get(ned_string* str, size_t index)
{
	char c = *(char*)ned_generic_string_get((ned_generic_string*)str, index);
	return c;
}

static inline wchar_t ned_wstring_get(ned_wstring* str, size_t index)
{
	wchar_t c = *(wchar_t*)ned_generic_string_get((ned_generic_string*)str, index);
	return c;
}

/*
 * ned_(w)string_get_all(str) - get all the characters in the string
 */

void* ned_generic_string_get_all(ned_generic_string* str);

static inline char* ned_string_get_all(ned_string* str)
{
	char* chars = (char*)ned_generic_string_get_all((ned_generic_string*)str);
	return chars;
}

static inline wchar_t* ned_wstring_get_all(ned_wstring* str)
{
	wchar_t* chars = (wchar_t*)ned_generic_string_get_all((ned_generic_string*)str);
	return chars;
}

/*
 * ned_(w)string_free(str) - free the memory allocated by the string
 */

void ned_generic_string_free(ned_generic_string* str);

static inline void ned_string_free(ned_string* str)
{
	ned_generic_string_free((ned_generic_string*)str);
}

static inline void ned_wstring_free(ned_wstring* str)
{
	ned_generic_string_free((ned_generic_string*)str);
}

#endif
