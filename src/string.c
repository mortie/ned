#include "string.h"

/*
 * string_new
 */

ned_generic_string ned_generic_string_new(size_t width)
{
	ned_generic_string str;
	str.text = NULL;
	str.length = 0;
	str.width = width;
	str.allocd = 0;

	return str;
}

/*
 * string_set
 */

void ned_generic_string_set(ned_generic_string str, void* chars, size_t count)
{
	str.text = realloc(str.text, count * str.width);
	str.text = memcpy(str.text, chars, count * str.width);
	str.length = count;
	str.allocd = count;
}

/*
 * string_insert
 */

void ned_generic_string_insert(ned_generic_string str, void* c, size_t index)
{
	str.length += 1;

	//realloc if needed
	if (str.length >= str.allocd)
	{
		if (str.allocd == 0)
			str.allocd = 1;
		else
			str.allocd *= 2;
		str.text = realloc(str.text, str.width * str.allocd);
	}

	uintptr_t indexPtr = (uintptr_t)str.text + (str.width * index);
	memmove((void*)(indexPtr + str.width), (void*)indexPtr, (str.length - index + 1) * str.width);
	memcpy((void*)indexPtr, c, str.width);

}

/*
 * string_push
 */

void ned_generic_string_push(ned_generic_string str, void* c)
{
	ned_generic_string_insert(str, c, str.length - 1);
}

/*
 * string_get
 */

void* ned_generic_string_get(ned_generic_string str, size_t index)
{
	uintptr_t indexPtr = (uintptr_t)str.text + (str.width * index);
	void* c = (void*)indexPtr;
	return c;
}

/*
 * string_get_all
 */

void* ned_generic_string_get_all(ned_generic_string str)
{
	return str.text;
}

/*
 * string_free
 */

void ned_generic_string_free(ned_generic_string str)
{
	free(str.text);
	free(str);
}
