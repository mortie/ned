#include "string.h"


inline ned_string ned_string_new()
{
    ned_string str = (ned_string)ned_generic_string_new(sizeof(char));
    return str;
}

inline ned_wstring ned_wstring_new()
{
    ned_wstring str = (ned_wstring)ned_generic_string_new(sizeof(wchar_t));
    return str;
}

/*
 * ned_(w)string_set(str, chars, count) - set a string's content
 */

inline void ned_string_set(ned_string str, char* chars, size_t count)
{
    ned_generic_string_set((ned_generic_string)str, chars, count);
}

inline void ned_wstring_set(ned_wstring str, wchar_t* chars, size_t count)
{
    ned_generic_string_set((ned_generic_string)str, chars, count);
}

/*
 * ned_(w)string_insert(str, c, index) - insert a character at an index
 */


inline void ned_string_insert(ned_string str, char c, size_t index)
{
    ned_generic_string_insert((ned_generic_string)str, &c, index);
}

inline void ned_wstring_insert(ned_wstring str, wchar_t c, size_t index)
{
    ned_generic_string_insert((ned_generic_string)str, &c, index);
}


inline void ned_string_push(ned_string str, char c)
{
    ned_generic_string_push((ned_generic_string)str, &c);
}

inline void ned_wstring_push(ned_wstring str, wchar_t c)
{
    ned_generic_string_push((ned_generic_string)str, &c);
}

inline char ned_string_get(ned_string str, size_t index)
{
    char c = *(char*)ned_generic_string_get((ned_generic_string)str, index);
    return c;
}

inline wchar_t ned_wstring_get(ned_wstring str, size_t index)
{
    wchar_t c = *(wchar_t*)ned_generic_string_get((ned_generic_string)str, index);
    return c;
}

inline char* ned_string_get_all(ned_string str)
{
    char* chars = (char*)ned_generic_string_get_all((ned_generic_string)str);
    return chars;
}

inline wchar_t* ned_wstring_get_all(ned_wstring str)
{
    wchar_t* chars = (wchar_t*)ned_generic_string_get_all((ned_generic_string)str);
    return chars;
}

inline void ned_string_free(ned_string str)
{
    ned_generic_string_free((ned_generic_string)str);
}

inline void ned_wstring_free(ned_wstring str)
{
    ned_generic_string_free((ned_generic_string)str);
}

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
}
