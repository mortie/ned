#ifndef FCONTENT_H
#define FCONTENT_H

//size_t
#include <stddef.h>

//malloc
#include <stdlib.h>

//memmove
#include <string.h>

//uintptr_t
#include <stdint.h>

typedef struct fcontent
{
	char* text;
	size_t length;
} fcontent;

fcontent* fcontent_new();

void fcontent_insert(fcontent* fc, size_t index, char c);

void fcontent_push(fcontent* fc, char c);

#endif
