#include "fcontent.h"

fcontent* fcontent_new()
{
	fcontent* fc = malloc(sizeof(fcontent));
	fc->text = 0;
	fc->length = 0;

	return fc;
}

void fcontent_insert(fcontent* fc, size_t index, char c)
{
	size_t s = sizeof(c);

	++fc->length;

	//reallocate
	fc->text = realloc(fc->text, fc->length * s);

	//shift elements after index over one
	void* indexPtr = (void*)(fc->text + (s * index));
	memmove((void*)((uintptr_t)indexPtr + s), indexPtr, (fc->length - index) * s);

	//insert char
	fc->text[index] = c;
}

void fcontent_push(fcontent* fc, char c)
{
	fcontent_insert(fc, fc->length, c);
}
