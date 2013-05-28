/* intutil.c - Integer utility functions.
 *
 * Copyright (C) 2001, 2002, 2003, 2004, 2005  Oskar Liljeblad
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <config.h>
#include <stdint.h>	/* Gnulib, C99 */
#include <stdio.h>	/* C89 */
#include <inttypes.h>	/* ? */
#include "intutil.h"
#include <climits>


#if  0     /* ----- #if 0 : If0Label_1 ----- */

#define INT_STR_FUNC(n, t, m) \
    char * \
    n(t value) \
    { \
	sprintf(intstr, "%" m, value); \
	return intstr; \
    }

/* Why 23 characters? */
/* 2^64-1 in octal is 22 chars + null byte = 23 */
static char intstr[23];

INT_STR_FUNC(uint64_str, uint64_t, PRIu64);
INT_STR_FUNC(uint32_str, uint32_t, PRIu32);
INT_STR_FUNC(uint16_str, uint16_t, PRIu16);
INT_STR_FUNC(uint8_str, uint8_t, PRIu8);
INT_STR_FUNC(int32_str, int32_t, PRIi32);
INT_STR_FUNC(int64_str, int64_t, PRIi64);
INT_STR_FUNC(int16_str, int16_t, PRIi16);
INT_STR_FUNC(int8_str, int8_t, PRIi8);

#endif     /* ----- #if 0 : If0Label_1 ----- */

/* These are probably used very seldom, so they are disabled. */
#if 0
INT_STR_FUNC(uintptr_str, uintptr_t, PRIuPTR);
INT_STR_FUNC(intptr_str, intptr_t, PRIiPTR);
INT_STR_FUNC(uintmax_str, uintmax_t, PRIuMAX);
INT_STR_FUNC(intmax_str, intmax_t, PRIiMAX);
INT_STR_FUNC(uintptr_octstr, uintptr_t, PRIoPTR);
INT_STR_FUNC(uintmax_octstr, uintmax_t, PRIoMAX);
INT_STR_FUNC(uint64_octstr, uint64_t, PRIo64);
INT_STR_FUNC(uint32_octstr, uint32_t, PRIo32);
INT_STR_FUNC(uint16_octstr, uint16_t, PRIo16);
INT_STR_FUNC(uint8_octstr, uint8_t, PRIo8);
INT_STR_FUNC(uintptr_hexstr, uintptr_t, PRIxPTR);
INT_STR_FUNC(uintmax_hexstr, uintmax_t, PRIxMAX);
INT_STR_FUNC(uint64_hexstr, uint64_t, PRIx64);
INT_STR_FUNC(uint32_hexstr, uint32_t, PRIx32);
INT_STR_FUNC(uint16_hexstr, uint16_t, PRIx16);
INT_STR_FUNC(uint8_hexstr, uint8_t, PRIx8);
INT_STR_FUNC(uintptr_hexustr, uintptr_t, PRIXPTR);
INT_STR_FUNC(uintmax_hexustr, uintmax_t, PRIXMAX);
INT_STR_FUNC(uint64_hexustr, uint64_t, PRIX64);
INT_STR_FUNC(uint32_hexustr, uint32_t, PRIX32);
INT_STR_FUNC(uint16_hexustr, uint16_t, PRIX16);
INT_STR_FUNC(uint8_hexustr, uint8_t, PRIX8);
#endif

bool
parse_int8(const char *instr, int8_t *outint)
{
    int8_t value = 0;

    if (*instr == '-') {
        if (instr[1] == '\0')
            return false;
        for (instr++; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value < CHAR_MIN/10 || (value == CHAR_MIN/10 && c > -(CHAR_MIN%10)))
                return false;
            value = value*10 - c;
        }
    } else {
        if (*instr == '\0')
            return false;
        for (; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value > CHAR_MAX/10 || (value == CHAR_MAX/10 && c > CHAR_MAX%10))
                return false;
            value = value*10 + c;
        }
    }
    *outint = value;

    return true;
}

bool
parse_int16(const char *instr, int16_t *outint)
{
    int16_t value = 0;

    if (*instr == '-') {
        if (instr[1] == '\0')
            return false;
        for (instr++; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value < SHRT_MIN/10 || (value == SHRT_MIN/10 && c > -(SHRT_MIN%10)))
                return false;
            value = value*10 - c;
        }
    } else {
        if (*instr == '\0')
            return false;
        for (; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value > INT_MAX/10 || (value == INT_MAX/10 && c > INT_MAX%10))
                return false;
            value = value*10 + c;
        }
    }
    *outint = value;

    return true;
}

bool
parse_int32(const char *instr, int32_t *outint)
{
    int32_t value = 0;

    if (*instr == '-') {
        if (instr[1] == '\0')
            return false;
        for (instr++; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value < INT_MIN/10L || (value == INT_MIN/10L && c > -(INT_MIN%10L)))
                return false;
            value = value*10L - c;
        }
    } else {
        if (*instr == '\0')
            return false;
        for (; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value > INT_MAX/10L || (value == INT_MAX/10L && c > INT_MAX%10L))
                return false;
            value = value*10L + c;
        }
    }
    *outint = value;

    return true;
}

bool
parse_int64(const char *instr, int64_t *outint)
{
    int64_t value = 0;

    if (*instr == '-') {
        if (instr[1] == '\0')
            return false;
        for (instr++; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value < LLONG_MIN/10LL || (value == LLONG_MIN/10LL && c > -(LLONG_MIN%10LL)))
                return false;
            value = value*10LL - c;
        }
    } else {
        if (*instr == '\0')
            return false;
        for (; *instr != '\0'; instr++) {
            int8_t c = *instr - '0';
            if (c < 0 || c > 9)
                return false;
            if (value > LLONG_MAX/10LL || (value == LLONG_MAX/10LL && c > LLONG_MAX%10LL))
                return false;
            value = value*10LL + c;
        }
    }
    *outint = value;

    return true;
}

bool
parse_uint8(const char *instr, uint8_t *outint)
{
    uint8_t value = 0;

    for (; *instr != '\0'; instr++) {
        int8_t c = *instr - '0';
        if (c < 0 || c > 9)
            return false;
        if (value > UCHAR_MAX/10 || (value == UCHAR_MAX/10 && c > UCHAR_MAX%10))
            return false;
        value = value*10 + c;
    }
    *outint = value;

    return true;
}

bool
parse_uint16(const char *instr, uint16_t *outint)
{
    uint16_t value = 0;

    for (; *instr != '\0'; instr++) {
        int8_t c = *instr - '0';
        if (c < 0 || c > 9)
            return false;
        if (value > UINT_MAX/10 || (value == UINT_MAX/10 && c > UINT_MAX%10))
            return false;
        value = value*10 + c;
    }
    *outint = value;

    return true;
}

bool
parse_uint32(const char *instr, uint32_t *outint)
{
    uint32_t value = 0;

    for (; *instr != '\0'; instr++) {
        int8_t c = *instr - '0';
        if (c < 0 || c > 9)
            return false;
        if (value > UINT_MAX/10L || (value == UINT_MAX/10L && c > UINT_MAX%10))
            return false;
        value = value*10L + c;
    }
    *outint = value;

    return true;
}

bool
parse_uint64(const char *instr, uint64_t *outint)
{
    uint64_t value = 0;

    for (; *instr != '\0'; instr++) {
        int8_t c = *instr - '0';
        if (c < 0 || c > 9)
            return false;
        if (value > ULLONG_MAX/10LL || (value == ULLONG_MAX/10LL && c > ULLONG_MAX%10LL))
            return false;
        value = value*10LL + c;
    }
    *outint = value;

    return true;
}
