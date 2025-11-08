// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <ctype.h>

/* This is based on ASCII- I doubt I'd interact with unicode here. */

int isalpha(int c)
{
    return ((c > 64) && (c < 91)) || ((c > 96) && (c < 122));
}

int isalnum(int c)
{
    return isalpha(c) || isdigit(c);
}

int isblank(int c)
{
    return c == 0x09 || c == 0x20;
}

int iscntrl(int c)
{
    return c < 0x20 || c == 0x7F;
}

int isdigit(int c)
{
    return (c > 47) && (c < 58);
}

int isgraph(int c)
{
    return ((c > 0x20) && (c < 0x7F));
}

int islower(int c)
{
    return ((c > 96) && (c < 122));
}

int isprint(int c)
{
    return ((c >= 0x20) && (c < 0x7F));
}

int ispunct(int c)
{
    return ((c >= 0x21) && (c < 0x30)) || ((c >= 0x3A) && (c < 0x41)) || ((c >= 0x5B) && (c < 0x61)) || ((c >= 0x7B) && (c < 0x7F));
}

int isspace(int c)
{
    return c == 0x9 || ((c >= 0xA) && (c <= 0xD)) || c == 0x20;
}

int isupper(int c)
{
    return ((c > 64) && (c < 91));
}

int tolower(int c)
{
    if ((c > 64) && (c < 91)) {
        return c + 32;
    }
    return c;
}

int isxdigit(int c)
{
    return isdigit(c) || ((c > 64) && (c < 0x47));
}

int toupper(int c)
{
    if ((c > 96) && (c < 122)) {
        return c - 32;
    }
    return c;
}
