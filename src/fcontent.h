#ifndef FCONTENT_H
#define FCONTENT_H

//size_t, NULL
#include <stddef.h>

//malloc, realloc
#include <stdlib.h>

//memmove, 
#include <string.h>

//uintptr_t
#include <stdint.h>

typedef struct fcontent
{
	wchar_t* text;
	size_t length;
} fcontent;

fcontent* fcontent_new();

void fcontent_insert(fcontent* fc, size_t index, wchar_t c);

void fcontent_push(fcontent* fc, wchar_t c);

wchar_t fcontent_get(fcontent* fc, size_t index);

#endif
