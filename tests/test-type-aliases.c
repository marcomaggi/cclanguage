/*
  Part of: CCLanguage
  Contents: tests for type aliases
  Date: Jul  1, 2020

  Abstract



  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>

  The author  hereby grant permission to  use, copy, modify, distribute,  and license
  this  software  and its  documentation  for  any  purpose, provided  that  existing
  copyright  notices are  retained in  all copies  and that  this notice  is included
  verbatim in  any distributions. No  written agreement,  license, or royalty  fee is
  required for  any of the  authorized uses.  Modifications  to this software  may be
  copyrighted by  their authors  and need  not follow  the licensing  terms described
  here, provided that the  new terms are clearly indicated on the  first page of each
  file where they apply.

  IN NO  EVENT SHALL THE AUTHOR  OR DISTRIBUTORS BE  LIABLE TO ANY PARTY  FOR DIRECT,
  INDIRECT, SPECIAL, INCIDENTAL,  OR CONSEQUENTIAL DAMAGES ARISING OUT OF  THE USE OF
  THIS SOFTWARE,  ITS DOCUMENTATION, OR ANY  DERIVATIVES THEREOF, EVEN IF  THE AUTHOR
  HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  THE AUTHOR  AND DISTRIBUTORS SPECIFICALLY  DISCLAIM ANY WARRANTIES,  INCLUDING, BUT
  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
  PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS  PROVIDED ON AN "AS IS" BASIS, AND
  THE AUTHOR  AND DISTRIBUTORS  HAVE NO OBLIGATION  TO PROVIDE  MAINTENANCE, SUPPORT,
  UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <cclanguage.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/** --------------------------------------------------------------------
 ** Sint8 an uint8 types.
 ** ----------------------------------------------------------------- */

static void
test_sint8 (void)
{
  cclib_sint8_t		X = cclib_sint8(1);
  cclib_sint8_t		Y = cclib_sint8(2);
  cclib_sint8_t		max = CCLIB_MAX_SINT8;
  cclib_sint8_t		min = CCLIB_MIN_SINT8;

  assert(X != Y);
  assert(CCLIB_MAX_SINT8 == max);
  assert(CCLIB_MIN_SINT8 == min);
  assert(CCLIB_SIZEOF_SINT8 == sizeof(cclib_sint8_t));
  assert(cclib_type_max(sint8) == max);
  assert(cclib_type_min(sint8) == min);
  assert(cclib_type_sizeof(sint8) == sizeof(cclib_sint8_t));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint8), cclib_type_max(sint8));
    sscanf(buffer, "%" cclib_type_pri(sint8), &out);
    assert(cclib_type_max(sint8) == cclib_sint8(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint8), cclib_type_min(sint8));
    sscanf(buffer, "%" cclib_type_pri(sint8), &out);
    assert(cclib_type_min(sint8) == cclib_sint8(out));
  }
}

static void
test_uint8 (void)
{
  cclib_uint8_t		X = cclib_uint8(1);
  cclib_uint8_t		Y = cclib_uint8(2);
  cclib_uint8_t		max = CCLIB_MAX_UINT8;
  cclib_uint8_t		min = CCLIB_MIN_UINT8;

  assert(X != Y);
  assert(CCLIB_MAX_UINT8 == max);
  assert(CCLIB_MIN_UINT8 == min);
  assert(CCLIB_SIZEOF_UINT8 == sizeof(cclib_uint8_t));
  assert(cclib_type_max(uint8) == max);
  assert(cclib_type_min(uint8) == min);
  assert(cclib_type_sizeof(uint8) == sizeof(cclib_uint8_t));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint8), cclib_type_max(uint8));
    sscanf(buffer, "%" cclib_type_pri(uint8), &out);
    assert(cclib_type_max(uint8) == cclib_uint8(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint8), cclib_type_min(uint8));
    sscanf(buffer, "%" cclib_type_pri(uint8), &out);
    assert(cclib_type_min(uint8) == cclib_uint8(out));
  }
}


/** --------------------------------------------------------------------
 ** Sint16 an uint16 types.
 ** ----------------------------------------------------------------- */

static void
test_sint16 (void)
{
  cclib_sint16_t		X = cclib_sint16(1);
  cclib_sint16_t		Y = cclib_sint16(2);
  cclib_sint16_t		max = CCLIB_MAX_SINT16;
  cclib_sint16_t		min = CCLIB_MIN_SINT16;

  assert(X != Y);
  assert(CCLIB_MAX_SINT16 == max);
  assert(CCLIB_MIN_SINT16 == min);
  assert(CCLIB_SIZEOF_SINT16 == sizeof(cclib_sint16_t));
  assert(cclib_type_max(sint16) == max);
  assert(cclib_type_min(sint16) == min);
  assert(cclib_type_sizeof(sint16) == sizeof(cclib_sint16_t));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint16), cclib_type_max(sint16));
    sscanf(buffer, "%" cclib_type_pri(sint16), &out);
    assert(cclib_type_max(sint16) == cclib_sint16(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint16), cclib_type_min(sint16));
    sscanf(buffer, "%" cclib_type_pri(sint16), &out);
    assert(cclib_type_min(sint16) == cclib_sint16(out));
  }
}

static void
test_uint16 (void)
{
  cclib_uint16_t		X = cclib_uint16(1);
  cclib_uint16_t		Y = cclib_uint16(2);
  cclib_uint16_t		max = CCLIB_MAX_UINT16;
  cclib_uint16_t		min = CCLIB_MIN_UINT16;

  assert(X != Y);
  assert(CCLIB_MAX_UINT16 == max);
  assert(CCLIB_MIN_UINT16 == min);
  assert(CCLIB_SIZEOF_UINT16 == sizeof(cclib_uint16_t));
  assert(cclib_type_max(uint16) == max);
  assert(cclib_type_min(uint16) == min);
  assert(cclib_type_sizeof(uint16) == sizeof(cclib_uint16_t));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint16), cclib_type_max(uint16));
    sscanf(buffer, "%" cclib_type_pri(uint16), &out);
    assert(cclib_type_max(uint16) == cclib_uint16(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint16), cclib_type_min(uint16));
    sscanf(buffer, "%" cclib_type_pri(uint16), &out);
    assert(cclib_type_min(uint16) == cclib_uint16(out));
  }
}


/** --------------------------------------------------------------------
 ** Sint32 an uint32 types.
 ** ----------------------------------------------------------------- */

static void
test_sint32 (void)
{
  cclib_sint32_t		X = cclib_sint32(1);
  cclib_sint32_t		Y = cclib_sint32(2);
  cclib_sint32_t		max = CCLIB_MAX_SINT32;
  cclib_sint32_t		min = CCLIB_MIN_SINT32;

  assert(X != Y);
  assert(CCLIB_MAX_SINT32 == max);
  assert(CCLIB_MIN_SINT32 == min);
  assert(CCLIB_SIZEOF_SINT32 == sizeof(cclib_sint32_t));
  assert(cclib_type_max(sint32) == max);
  assert(cclib_type_min(sint32) == min);
  assert(cclib_type_sizeof(sint32) == sizeof(cclib_sint32_t));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint32), cclib_type_max(sint32));
    sscanf(buffer, "%" cclib_type_pri(sint32), &out);
    assert(cclib_type_max(sint32) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint32), cclib_type_min(sint32));
    sscanf(buffer, "%" cclib_type_pri(sint32), &out);
    assert(cclib_type_min(sint32) == out);
  }
}

static void
test_uint32 (void)
{
  cclib_uint32_t		X = cclib_uint32(1);
  cclib_uint32_t		Y = cclib_uint32(2);
  cclib_uint32_t		max = CCLIB_MAX_UINT32;
  cclib_uint32_t		min = CCLIB_MIN_UINT32;

  assert(X != Y);
  assert(CCLIB_MAX_UINT32 == max);
  assert(CCLIB_MIN_UINT32 == min);
  assert(CCLIB_SIZEOF_UINT32 == sizeof(cclib_uint32_t));
  assert(cclib_type_max(uint32) == max);
  assert(cclib_type_min(uint32) == min);
  assert(cclib_type_sizeof(uint32) == sizeof(cclib_uint32_t));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint32), cclib_type_max(uint32));
    sscanf(buffer, "%" cclib_type_pri(uint32), &out);
    assert(cclib_type_max(uint32) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint32), cclib_type_min(uint32));
    sscanf(buffer, "%" cclib_type_pri(uint32), &out);
    assert(cclib_type_min(uint32) == out);
  }
}


/** --------------------------------------------------------------------
 ** Sint64 an uint64 types.
 ** ----------------------------------------------------------------- */

static void
test_sint64 (void)
{
  cclib_sint64_t		X = cclib_sint64(1);
  cclib_sint64_t		Y = cclib_sint64(2);
  cclib_sint64_t		max = CCLIB_MAX_SINT64;
  cclib_sint64_t		min = CCLIB_MIN_SINT64;

  assert(X != Y);
  assert(CCLIB_MAX_SINT64 == max);
  assert(CCLIB_MIN_SINT64 == min);
  assert(CCLIB_SIZEOF_SINT64 == sizeof(cclib_sint64_t));
  assert(cclib_type_max(sint64) == max);
  assert(cclib_type_min(sint64) == min);
  assert(cclib_type_sizeof(sint64) == sizeof(cclib_sint64_t));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint64), cclib_type_max(sint64));
    sscanf(buffer, "%" cclib_type_pri(sint64), &out);
    assert(cclib_type_max(sint64) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint64), cclib_type_min(sint64));
    sscanf(buffer, "%" cclib_type_pri(sint64), &out);
    assert(cclib_type_min(sint64) == out);
  }
}

static void
test_uint64 (void)
{
  cclib_uint64_t		X = cclib_uint64(1);
  cclib_uint64_t		Y = cclib_uint64(2);
  cclib_uint64_t		max = CCLIB_MAX_UINT64;
  cclib_uint64_t		min = CCLIB_MIN_UINT64;

  assert(X != Y);
  assert(CCLIB_MAX_UINT64 == max);
  assert(CCLIB_MIN_UINT64 == min);
  assert(CCLIB_SIZEOF_UINT64 == sizeof(cclib_uint64_t));
  assert(cclib_type_max(uint64) == max);
  assert(cclib_type_min(uint64) == min);
  assert(cclib_type_sizeof(uint64) == sizeof(cclib_uint64_t));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint64), cclib_type_max(uint64));
    sscanf(buffer, "%" cclib_type_pri(uint64), &out);
    assert(cclib_type_max(uint64) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint64), cclib_type_min(uint64));
    sscanf(buffer, "%" cclib_type_pri(uint64), &out);
    assert(cclib_type_min(uint64) == out);
  }
}


/** --------------------------------------------------------------------
 ** Byte an octet types.
 ** ----------------------------------------------------------------- */

static void
test_byte (void)
{
  cclib_byte_t		X = cclib_byte(1);
  cclib_byte_t		Y = cclib_byte(2);
  cclib_byte_t		max = CCLIB_MAX_BYTE;
  cclib_byte_t		min = CCLIB_MIN_BYTE;

  assert(X != Y);
  assert(CCLIB_MAX_BYTE == max);
  assert(CCLIB_MIN_BYTE == min);
  assert(CCLIB_SIZEOF_BYTE == sizeof(cclib_byte_t));
  assert(cclib_type_max(byte) == max);
  assert(cclib_type_min(byte) == min);
  assert(cclib_type_sizeof(byte) == sizeof(cclib_byte_t));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(byte), cclib_type_max(byte));
    sscanf(buffer, "%" cclib_type_pri(byte), &out);
    assert(cclib_type_max(byte) == cclib_byte(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(byte), cclib_type_min(byte));
    sscanf(buffer, "%" cclib_type_pri(byte), &out);
    assert(cclib_type_min(byte) == cclib_byte(out));
  }
}

static void
test_octet (void)
{
  cclib_octet_t		X = cclib_octet(1);
  cclib_octet_t		Y = cclib_octet(2);
  cclib_octet_t		max = CCLIB_MAX_OCTET;
  cclib_octet_t		min = CCLIB_MIN_OCTET;

  assert(X != Y);
  assert(CCLIB_MAX_OCTET == max);
  assert(CCLIB_MIN_OCTET == min);
  assert(CCLIB_SIZEOF_OCTET == sizeof(cclib_octet_t));
  assert(cclib_type_max(octet) == max);
  assert(cclib_type_min(octet) == min);
  assert(cclib_type_sizeof(octet) == sizeof(cclib_octet_t));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(octet), cclib_type_max(octet));
    sscanf(buffer, "%" cclib_type_pri(octet), &out);
    assert(cclib_type_max(octet) == cclib_octet(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(octet), cclib_type_min(octet));
    sscanf(buffer, "%" cclib_type_pri(octet), &out);
    assert(cclib_type_min(octet) == cclib_octet(out));
  }
}


/** --------------------------------------------------------------------
 ** Char types.
 ** ----------------------------------------------------------------- */

static void
test_char (void)
{
  cclib_char_t		X = cclib_char(1);
  cclib_char_t		Y = cclib_char(2);
  cclib_char_t		max = CCLIB_MAX_CHAR;
  cclib_char_t		min = CCLIB_MIN_CHAR;

  assert(X != Y);
  assert(CCLIB_MAX_CHAR == max);
  assert(CCLIB_MIN_CHAR == min);
  assert(CCLIB_SIZEOF_CHAR == sizeof(cclib_char_t));
  assert(cclib_type_max(char) == max);
  assert(cclib_type_min(char) == min);
  assert(cclib_type_sizeof(char) == sizeof(cclib_char_t));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(char), cclib_type_max(char));
    sscanf(buffer, "%" cclib_type_pri(char), &out);
    assert(cclib_type_max(char) == cclib_char(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(char), cclib_type_min(char));
    sscanf(buffer, "%" cclib_type_pri(char), &out);
    assert(cclib_type_min(char) == cclib_char(out));
  }
}

static void
test_schar (void)
{
  cclib_schar_t		X = cclib_schar(1);
  cclib_schar_t		Y = cclib_schar(2);
  cclib_schar_t		max = CCLIB_MAX_SCHAR;
  cclib_schar_t		min = CCLIB_MIN_SCHAR;

  assert(X != Y);
  assert(CCLIB_MAX_SCHAR == max);
  assert(CCLIB_MIN_SCHAR == min);
  assert(CCLIB_SIZEOF_SCHAR == sizeof(cclib_schar_t));
  assert(cclib_type_max(schar) == max);
  assert(cclib_type_min(schar) == min);
  assert(cclib_type_sizeof(schar) == sizeof(cclib_schar_t));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(schar), cclib_type_max(schar));
    sscanf(buffer, "%" cclib_type_pri(schar), &out);
    assert(cclib_type_max(schar) == cclib_schar(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(schar), cclib_type_min(schar));
    sscanf(buffer, "%" cclib_type_pri(schar), &out);
    assert(cclib_type_min(schar) == cclib_schar(out));
  }
}

static void
test_uchar (void)
{
  cclib_uchar_t		X = cclib_uchar(1);
  cclib_uchar_t		Y = cclib_uchar(2);
  cclib_uchar_t		max = CCLIB_MAX_UCHAR;
  cclib_uchar_t		min = CCLIB_MIN_UCHAR;

  assert(X != Y);
  assert(CCLIB_MAX_UCHAR == max);
  assert(CCLIB_MIN_UCHAR == min);
  assert(CCLIB_SIZEOF_UCHAR == sizeof(cclib_uchar_t));
  assert(cclib_type_max(uchar) == max);
  assert(cclib_type_min(uchar) == min);
  assert(cclib_type_sizeof(uchar) == sizeof(cclib_uchar_t));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uchar), cclib_type_max(uchar));
    sscanf(buffer, "%" cclib_type_pri(uchar), &out);
    assert(cclib_type_max(uchar) == cclib_uchar(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uchar), cclib_type_min(uchar));
    sscanf(buffer, "%" cclib_type_pri(uchar), &out);
    assert(cclib_type_min(uchar) == cclib_uchar(out));
  }
}


/** --------------------------------------------------------------------
 ** Let's go.
 ** ----------------------------------------------------------------- */

int
main (void)
{
  test_byte();
  test_octet();

  test_sint8();
  test_uint8();

  test_sint16();
  test_uint16();

  test_sint32();
  test_uint32();

  test_sint64();
  test_uint64();

  test_char();
  test_schar();
  test_uchar();

  exit(EXIT_SUCCESS);
}

/* end of file */
