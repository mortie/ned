#include "fcontent.h"

fcontent* fcontent_new()
{
	fcontent* fc = malloc(sizeof(fcontent));
	fc->text = NULL;
	fc->length = 0;

	return fc;
}

void fcontent_insert(fcontent* fc, size_t index, wchar_t c)
{
	size_t s = sizeof(c);

	fc->length += 1;

	//reallocate
	fc->text = realloc(fc->text, fc->length * s);

	//shift elements after index over one
	wchar_t* indexPtr = fc->text + index;
	memmove(indexPtr + 1, indexPtr, (fc->length - 1 - index) * s);

	//insert char
	fc->text[index] = c;
}

void fcontent_push(fcontent* fc, wchar_t c)
{
	fcontent_insert(fc, fc->length, c);
}

wchar_t fcontent_get(fcontent* fc, size_t index)
{
	return fc->text[index];
}
