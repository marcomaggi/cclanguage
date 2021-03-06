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
  cclib_sint8_t		X = cclib_sint8_const(1);
  cclib_sint8_t		Y = cclib_sint8_const(2);
  cclib_sint8_t		max = cclib_max_sint8();
  cclib_sint8_t		min = cclib_min_sint8();

  assert(X != Y);
  assert(cclib_max_sint8() == max);
  assert(cclib_min_sint8() == min);
  assert(cclib_sizeof_sint8() == sizeof(cclib_sint8_t));
  assert(cclib_type_max(sint8) == max);
  assert(cclib_type_min(sint8) == min);
  assert(cclib_type_sizeof(sint8) == sizeof(cclib_type_t(sint8)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint8), cclib_type_printf_cast(sint8, cclib_type_max(sint8)));
    sscanf(buffer, "%" cclib_type_pri(sint8), &out);
    assert(cclib_type_max(sint8) == cclib_sint8(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint8), cclib_type_printf_cast(sint8, cclib_type_min(sint8)));
    sscanf(buffer, "%" cclib_type_pri(sint8), &out);
    assert(cclib_type_min(sint8) == cclib_sint8(out));
  }
}

static void
test_uint8 (void)
{
  cclib_uint8_t		X = cclib_uint8_const(1);
  cclib_uint8_t		Y = cclib_uint8_const(2);
  cclib_uint8_t		max = cclib_max_uint8();
  cclib_uint8_t		min = cclib_min_uint8();

  assert(X != Y);
  assert(cclib_max_uint8() == max);
  assert(cclib_min_uint8() == min);
  assert(cclib_sizeof_uint8() == sizeof(cclib_uint8_t));
  assert(cclib_type_max(uint8) == max);
  assert(cclib_type_min(uint8) == min);
  assert(cclib_type_sizeof(uint8) == sizeof(cclib_type_t(uint8)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint8), cclib_type_printf_cast(uint8, cclib_type_max(uint8)));
    sscanf(buffer, "%" cclib_type_pri(uint8), &out);
    assert(cclib_type_max(uint8) == cclib_uint8(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint8), cclib_type_printf_cast(uint8, cclib_type_min(uint8)));
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
  cclib_sint16_t		X = cclib_sint16_const(1);
  cclib_sint16_t		Y = cclib_sint16_const(2);
  cclib_sint16_t		max = cclib_max_sint16();
  cclib_sint16_t		min = cclib_min_sint16();

  assert(X != Y);
  assert(cclib_max_sint16() == max);
  assert(cclib_min_sint16() == min);
  assert(cclib_sizeof_sint16() == sizeof(cclib_sint16_t));
  assert(cclib_type_max(sint16) == max);
  assert(cclib_type_min(sint16) == min);
  assert(cclib_type_sizeof(sint16) == sizeof(cclib_type_t(sint16)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint16), cclib_type_printf_cast(sint16, cclib_type_max(sint16)));
    sscanf(buffer, "%" cclib_type_pri(sint16), &out);
    assert(cclib_type_max(sint16) == cclib_sint16(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint16), cclib_type_printf_cast(sint16, cclib_type_min(sint16)));
    sscanf(buffer, "%" cclib_type_pri(sint16), &out);
    assert(cclib_type_min(sint16) == cclib_sint16(out));
  }
}

static void
test_uint16 (void)
{
  cclib_uint16_t		X = cclib_uint16_const(1);
  cclib_uint16_t		Y = cclib_uint16_const(2);
  cclib_uint16_t		max = cclib_max_uint16();
  cclib_uint16_t		min = cclib_min_uint16();

  assert(X != Y);
  assert(cclib_max_uint16() == max);
  assert(cclib_min_uint16() == min);
  assert(cclib_sizeof_uint16() == sizeof(cclib_uint16_t));
  assert(cclib_type_max(uint16) == max);
  assert(cclib_type_min(uint16) == min);
  assert(cclib_type_sizeof(uint16) == sizeof(cclib_type_t(uint16)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint16), cclib_type_printf_cast(uint16, cclib_type_max(uint16)));
    sscanf(buffer, "%" cclib_type_pri(uint16), &out);
    assert(cclib_type_max(uint16) == cclib_uint16(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint16), cclib_type_printf_cast(uint16, cclib_type_min(uint16)));
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
  cclib_sint32_t		X = cclib_sint32_const(1);
  cclib_sint32_t		Y = cclib_sint32_const(2);
  cclib_sint32_t		max = cclib_max_sint32();
  cclib_sint32_t		min = cclib_min_sint32();

  assert(X != Y);
  assert(cclib_max_sint32() == max);
  assert(cclib_min_sint32() == min);
  assert(cclib_sizeof_sint32() == sizeof(cclib_sint32_t));
  assert(cclib_type_max(sint32) == max);
  assert(cclib_type_min(sint32) == min);
  assert(cclib_type_sizeof(sint32) == sizeof(cclib_type_t(sint32)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint32), cclib_type_printf_cast(sint32, cclib_type_max(sint32)));
    sscanf(buffer, "%" cclib_type_pri(sint32), &out);
    assert(cclib_type_max(sint32) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint32), cclib_type_printf_cast(sint32, cclib_type_min(sint32)));
    sscanf(buffer, "%" cclib_type_pri(sint32), &out);
    assert(cclib_type_min(sint32) == out);
  }
}

static void
test_uint32 (void)
{
  cclib_uint32_t		X = cclib_uint32_const(1);
  cclib_uint32_t		Y = cclib_uint32_const(2);
  cclib_uint32_t		max = cclib_max_uint32();
  cclib_uint32_t		min = cclib_min_uint32();

  assert(X != Y);
  assert(cclib_max_uint32() == max);
  assert(cclib_min_uint32() == min);
  assert(cclib_sizeof_uint32() == sizeof(cclib_uint32_t));
  assert(cclib_type_max(uint32) == max);
  assert(cclib_type_min(uint32) == min);
  assert(cclib_type_sizeof(uint32) == sizeof(cclib_type_t(uint32)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint32), cclib_type_printf_cast(uint32, cclib_type_max(uint32)));
    sscanf(buffer, "%" cclib_type_pri(uint32), &out);
    assert(cclib_type_max(uint32) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint32_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint32), cclib_type_printf_cast(uint32, cclib_type_min(uint32)));
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
  cclib_sint64_t		X = cclib_sint64_const(1);
  cclib_sint64_t		Y = cclib_sint64_const(2);
  cclib_sint64_t		max = cclib_max_sint64();
  cclib_sint64_t		min = cclib_min_sint64();

  assert(X != Y);
  assert(cclib_max_sint64() == max);
  assert(cclib_min_sint64() == min);
  assert(cclib_sizeof_sint64() == sizeof(cclib_sint64_t));
  assert(cclib_type_max(sint64) == max);
  assert(cclib_type_min(sint64) == min);
  assert(cclib_type_sizeof(sint64) == sizeof(cclib_type_t(sint64)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint64), cclib_type_printf_cast(sint64, cclib_type_max(sint64)));
    sscanf(buffer, "%" cclib_type_pri(sint64), &out);
    assert(cclib_type_max(sint64) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint64), cclib_type_printf_cast(sint64, cclib_type_min(sint64)));
    sscanf(buffer, "%" cclib_type_pri(sint64), &out);
    assert(cclib_type_min(sint64) == out);
  }
}

static void
test_uint64 (void)
{
  cclib_uint64_t		X = cclib_uint64_const(1);
  cclib_uint64_t		Y = cclib_uint64_const(2);
  cclib_uint64_t		max = cclib_max_uint64();
  cclib_uint64_t		min = cclib_min_uint64();

  assert(X != Y);
  assert(cclib_max_uint64() == max);
  assert(cclib_min_uint64() == min);
  assert(cclib_sizeof_uint64() == sizeof(cclib_uint64_t));
  assert(cclib_type_max(uint64) == max);
  assert(cclib_type_min(uint64) == min);
  assert(cclib_type_sizeof(uint64) == sizeof(cclib_type_t(uint64)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint64), cclib_type_printf_cast(uint64, cclib_type_max(uint64)));
    sscanf(buffer, "%" cclib_type_pri(uint64), &out);
    assert(cclib_type_max(uint64) == out);
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint64_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint64), cclib_type_printf_cast(uint64, cclib_type_min(uint64)));
    sscanf(buffer, "%" cclib_type_pri(uint64), &out);
    assert(cclib_type_min(uint64) == out);
  }
}


/** --------------------------------------------------------------------
 ** Byte, octet, word types.
 ** ----------------------------------------------------------------- */

static void
test_byte (void)
{
  cclib_byte_t		X = cclib_byte_const(1);
  cclib_byte_t		Y = cclib_byte_const(2);
  cclib_byte_t		max = cclib_max_byte();
  cclib_byte_t		min = cclib_min_byte();

  assert(X != Y);
  assert(cclib_max_byte() == max);
  assert(cclib_min_byte() == min);
  assert(cclib_sizeof_byte() == sizeof(cclib_byte_t));
  assert(cclib_type_max(byte) == max);
  assert(cclib_type_min(byte) == min);
  assert(cclib_type_sizeof(byte) == sizeof(cclib_type_t(byte)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(byte), cclib_type_printf_cast(byte, cclib_type_max(byte)));
    sscanf(buffer, "%" cclib_type_pri(byte), &out);
    assert(cclib_type_max(byte) == cclib_byte(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(byte), cclib_type_printf_cast(byte, cclib_type_min(byte)));
    sscanf(buffer, "%" cclib_type_pri(byte), &out);
    assert(cclib_type_min(byte) == cclib_byte(out));
  }
}

static void
test_octet (void)
{
  cclib_octet_t		X = cclib_octet_const(1);
  cclib_octet_t		Y = cclib_octet_const(2);
  cclib_octet_t		max = cclib_max_octet();
  cclib_octet_t		min = cclib_min_octet();

  assert(X != Y);
  assert(cclib_max_octet() == max);
  assert(cclib_min_octet() == min);
  assert(cclib_sizeof_octet() == sizeof(cclib_octet_t));
  assert(cclib_type_max(octet) == max);
  assert(cclib_type_min(octet) == min);
  assert(cclib_type_sizeof(octet) == sizeof(cclib_type_t(octet)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(octet), cclib_type_printf_cast(octet, cclib_type_max(octet)));
    sscanf(buffer, "%" cclib_type_pri(octet), &out);
    assert(cclib_type_max(octet) == cclib_octet(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(octet), cclib_type_printf_cast(octet, cclib_type_min(octet)));
    sscanf(buffer, "%" cclib_type_pri(octet), &out);
    assert(cclib_type_min(octet) == cclib_octet(out));
  }
}

static void
test_word (void)
{
  cclib_word_t		X = cclib_word_const(1);
  cclib_word_t		Y = cclib_word_const(2);
  cclib_word_t		max = cclib_max_word();
  cclib_word_t		min = cclib_min_word();

  assert(X != Y);
  assert(cclib_max_word() == max);
  assert(cclib_min_word() == min);
  assert(cclib_sizeof_word() == sizeof(cclib_word_t));
  assert(cclib_type_max(word) == max);
  assert(cclib_type_min(word) == min);
  assert(cclib_type_sizeof(word) == sizeof(cclib_type_t(word)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_word_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(word), cclib_type_printf_cast(word, cclib_type_max(word)));
    sscanf(buffer, "%" cclib_type_pri(word), &out);
    assert(cclib_type_max(word) == cclib_word(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_type_t(word)	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(word), cclib_type_printf_cast(word, cclib_type_min(word)));
    sscanf(buffer, "%" cclib_type_pri(word), &out);
    assert(cclib_type_min(word) == cclib_word(out));
  }
}


/** --------------------------------------------------------------------
 ** Char types.
 ** ----------------------------------------------------------------- */

static void
test_char (void)
{
  cclib_char_t		X = cclib_char_const(1);
  cclib_char_t		Y = cclib_char_const(2);
  cclib_char_t		max = cclib_max_char();
  cclib_char_t		min = cclib_min_char();

  assert(X != Y);
  assert(cclib_max_char() == max);
  assert(cclib_min_char() == min);
  assert(cclib_sizeof_char() == sizeof(cclib_char_t));
  assert(cclib_type_max(char) == max);
  assert(cclib_type_min(char) == min);
  assert(cclib_type_sizeof(char) == sizeof(cclib_type_t(char)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(char), cclib_type_printf_cast(char, cclib_type_max(char)));
    sscanf(buffer, "%" cclib_type_pri(char), &out);
    assert(cclib_type_max(char) == cclib_char(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(char), cclib_type_printf_cast(char, cclib_type_min(char)));
    sscanf(buffer, "%" cclib_type_pri(char), &out);
    assert(cclib_type_min(char) == cclib_char(out));
  }
}

static void
test_schar (void)
{
  cclib_schar_t		X = cclib_schar_const(1);
  cclib_schar_t		Y = cclib_schar_const(2);
  cclib_schar_t		max = cclib_max_schar();
  cclib_schar_t		min = cclib_min_schar();

  assert(X != Y);
  assert(cclib_max_schar() == max);
  assert(cclib_min_schar() == min);
  assert(cclib_sizeof_schar() == sizeof(cclib_schar_t));
  assert(cclib_type_max(schar) == max);
  assert(cclib_type_min(schar) == min);
  assert(cclib_type_sizeof(schar) == sizeof(cclib_type_t(schar)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(schar), cclib_type_printf_cast(schar, cclib_type_max(schar)));
    sscanf(buffer, "%" cclib_type_pri(schar), &out);
    assert(cclib_type_max(schar) == cclib_schar(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(schar), cclib_type_printf_cast(schar, cclib_type_min(schar)));
    sscanf(buffer, "%" cclib_type_pri(schar), &out);
    assert(cclib_type_min(schar) == cclib_schar(out));
  }
}

static void
test_uchar (void)
{
  cclib_uchar_t		X = cclib_uchar_const(1);
  cclib_uchar_t		Y = cclib_uchar_const(2);
  cclib_uchar_t		max = cclib_max_uchar();
  cclib_uchar_t		min = cclib_min_uchar();

  assert(X != Y);
  assert(cclib_max_uchar() == max);
  assert(cclib_min_uchar() == min);
  assert(cclib_sizeof_uchar() == sizeof(cclib_uchar_t));
  assert(cclib_type_max(uchar) == max);
  assert(cclib_type_min(uchar) == min);
  assert(cclib_type_sizeof(uchar) == sizeof(cclib_type_t(uchar)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uchar), cclib_type_printf_cast(uchar, cclib_type_max(uchar)));
    sscanf(buffer, "%" cclib_type_pri(uchar), &out);
    assert(cclib_type_max(uchar) == cclib_uchar(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uchar), cclib_type_printf_cast(uchar, cclib_type_min(uchar)));
    sscanf(buffer, "%" cclib_type_pri(uchar), &out);
    assert(cclib_type_min(uchar) == cclib_uchar(out));
  }
}


/** --------------------------------------------------------------------
 ** Integer types.
 ** ----------------------------------------------------------------- */

static void
test_sint (void)
{
  cclib_sint_t		X = cclib_sint_const(1);
  cclib_sint_t		Y = cclib_sint_const(2);
  cclib_sint_t		max = cclib_max_sint();
  cclib_sint_t		min = cclib_min_sint();

  assert(X != Y);
  assert(cclib_max_sint() == max);
  assert(cclib_min_sint() == min);
  assert(cclib_sizeof_sint() == sizeof(cclib_sint_t));
  assert(cclib_type_max(sint) == max);
  assert(cclib_type_min(sint) == min);
  assert(cclib_type_sizeof(sint) == sizeof(cclib_type_t(sint)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint), cclib_type_printf_cast(sint, cclib_type_max(sint)));
    sscanf(buffer, "%" cclib_type_pri(sint), &out);
    assert(cclib_type_max(sint) == cclib_sint(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sint), cclib_type_printf_cast(sint, cclib_type_min(sint)));
    sscanf(buffer, "%" cclib_type_pri(sint), &out);
    assert(cclib_type_min(sint) == cclib_sint(out));
  }
}

static void
test_uint (void)
{
  cclib_uint_t		X = cclib_uint_const(1);
  cclib_uint_t		Y = cclib_uint_const(2);
  cclib_uint_t		max = cclib_max_uint();
  cclib_uint_t		min = cclib_min_uint();

  assert(X != Y);
  assert(cclib_max_uint() == max);
  assert(cclib_min_uint() == min);
  assert(cclib_sizeof_uint() == sizeof(cclib_uint_t));
  assert(cclib_type_max(uint) == max);
  assert(cclib_type_min(uint) == min);
  assert(cclib_type_sizeof(uint) == sizeof(cclib_type_t(uint)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint), cclib_type_printf_cast(uint, cclib_type_max(uint)));
    sscanf(buffer, "%" cclib_type_pri(uint), &out);
    assert(cclib_type_max(uint) == cclib_uint(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uint), cclib_type_printf_cast(uint, cclib_type_min(uint)));
    sscanf(buffer, "%" cclib_type_pri(uint), &out);
    assert(cclib_type_min(uint) == cclib_uint(out));
  }
}


/** --------------------------------------------------------------------
 ** Long integer types.
 ** ----------------------------------------------------------------- */

static void
test_slong (void)
{
  cclib_slong_t		X = cclib_slong_const(1);
  cclib_slong_t		Y = cclib_slong_const(2);
  cclib_slong_t		max = cclib_max_slong();
  cclib_slong_t		min = cclib_min_slong();

  assert(X != Y);
  assert(cclib_max_slong() == max);
  assert(cclib_min_slong() == min);
  assert(cclib_sizeof_slong() == sizeof(cclib_slong_t));
  assert(cclib_type_max(slong) == max);
  assert(cclib_type_min(slong) == min);
  assert(cclib_type_sizeof(slong) == sizeof(cclib_type_t(slong)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_slong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(slong), cclib_type_printf_cast(slong, cclib_type_max(slong)));
    sscanf(buffer, "%" cclib_type_pri(slong), &out);
    assert(cclib_type_max(slong) == cclib_slong(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_slong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(slong), cclib_type_printf_cast(slong, cclib_type_min(slong)));
    sscanf(buffer, "%" cclib_type_pri(slong), &out);
    assert(cclib_type_min(slong) == cclib_slong(out));
  }
}

static void
test_ulong (void)
{
  cclib_ulong_t		X = cclib_ulong_const(1);
  cclib_ulong_t		Y = cclib_ulong_const(2);
  cclib_ulong_t		max = cclib_max_ulong();
  cclib_ulong_t		min = cclib_min_ulong();

  assert(X != Y);
  assert(cclib_max_ulong() == max);
  assert(cclib_min_ulong() == min);
  assert(cclib_sizeof_ulong() == sizeof(cclib_ulong_t));
  assert(cclib_type_max(ulong) == max);
  assert(cclib_type_min(ulong) == min);
  assert(cclib_type_sizeof(ulong) == sizeof(cclib_type_t(ulong)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ulong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ulong), cclib_type_printf_cast(ulong, cclib_type_max(ulong)));
    sscanf(buffer, "%" cclib_type_pri(ulong), &out);
    assert(cclib_type_max(ulong) == cclib_ulong(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ulong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ulong), cclib_type_printf_cast(ulong, cclib_type_min(ulong)));
    sscanf(buffer, "%" cclib_type_pri(ulong), &out);
    assert(cclib_type_min(ulong) == cclib_ulong(out));
  }
}


/** --------------------------------------------------------------------
 ** Long Long integer types.
 ** ----------------------------------------------------------------- */

static void
test_sllong (void)
{
  cclib_sllong_t		X = cclib_sllong_const(1);
  cclib_sllong_t		Y = cclib_sllong_const(2);
  cclib_sllong_t		max = cclib_max_sllong();
  cclib_sllong_t		min = cclib_min_sllong();

  assert(X != Y);
  assert(cclib_max_sllong() == max);
  assert(cclib_min_sllong() == min);
  assert(cclib_sizeof_sllong() == sizeof(cclib_sllong_t));
  assert(cclib_type_max(sllong) == max);
  assert(cclib_type_min(sllong) == min);
  assert(cclib_type_sizeof(sllong) == sizeof(cclib_type_t(sllong)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sllong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sllong), cclib_type_printf_cast(sllong, cclib_type_max(sllong)));
    sscanf(buffer, "%" cclib_type_pri(sllong), &out);
    assert(cclib_type_max(sllong) == cclib_sllong(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sllong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sllong), cclib_type_printf_cast(sllong, cclib_type_min(sllong)));
    sscanf(buffer, "%" cclib_type_pri(sllong), &out);
    assert(cclib_type_min(sllong) == cclib_sllong(out));
  }
}

static void
test_ullong (void)
{
  cclib_ullong_t		X = cclib_ullong_const(1);
  cclib_ullong_t		Y = cclib_ullong_const(2);
  cclib_ullong_t		max = cclib_max_ullong();
  cclib_ullong_t		min = cclib_min_ullong();

  assert(X != Y);
  assert(cclib_max_ullong() == max);
  assert(cclib_min_ullong() == min);
  assert(cclib_sizeof_ullong() == sizeof(cclib_ullong_t));
  assert(cclib_type_max(ullong) == max);
  assert(cclib_type_min(ullong) == min);
  assert(cclib_type_sizeof(ullong) == sizeof(cclib_type_t(ullong)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ullong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ullong), cclib_type_printf_cast(ullong, cclib_type_max(ullong)));
    sscanf(buffer, "%" cclib_type_pri(ullong), &out);
    assert(cclib_type_max(ullong) == cclib_ullong(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ullong_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ullong), cclib_type_printf_cast(ullong, cclib_type_min(ullong)));
    sscanf(buffer, "%" cclib_type_pri(ullong), &out);
    assert(cclib_type_min(ullong) == cclib_ullong(out));
  }
}


/** --------------------------------------------------------------------
 ** Maximum-width integer types.
 ** ----------------------------------------------------------------- */

static void
test_sintmax (void)
{
  cclib_sintmax_t		X = cclib_sintmax_const(1);
  cclib_sintmax_t		Y = cclib_sintmax_const(2);
  cclib_sintmax_t		max = cclib_max_sintmax();
  cclib_sintmax_t		min = cclib_min_sintmax();

  assert(X != Y);
  assert(cclib_max_sintmax() == max);
  assert(cclib_min_sintmax() == min);
  assert(cclib_sizeof_sintmax() == sizeof(cclib_sintmax_t));
  assert(cclib_type_max(sintmax) == max);
  assert(cclib_type_min(sintmax) == min);
  assert(cclib_type_sizeof(sintmax) == sizeof(cclib_type_t(sintmax)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sintmax_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sintmax), cclib_type_printf_cast(sintmax, cclib_type_max(sintmax)));
    sscanf(buffer, "%" cclib_type_pri(sintmax), &out);
    assert(cclib_type_max(sintmax) == cclib_sintmax(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sintmax_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sintmax), cclib_type_printf_cast(sintmax, cclib_type_min(sintmax)));
    sscanf(buffer, "%" cclib_type_pri(sintmax), &out);
    assert(cclib_type_min(sintmax) == cclib_sintmax(out));
  }
}

static void
test_uintmax (void)
{
  cclib_uintmax_t		X = cclib_uintmax_const(1);
  cclib_uintmax_t		Y = cclib_uintmax_const(2);
  cclib_uintmax_t		max = cclib_max_uintmax();
  cclib_uintmax_t		min = cclib_min_uintmax();

  assert(X != Y);
  assert(cclib_max_uintmax() == max);
  assert(cclib_min_uintmax() == min);
  assert(cclib_sizeof_uintmax() == sizeof(cclib_uintmax_t));
  assert(cclib_type_max(uintmax) == max);
  assert(cclib_type_min(uintmax) == min);
  assert(cclib_type_sizeof(uintmax) == sizeof(cclib_type_t(uintmax)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uintmax_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uintmax), cclib_type_printf_cast(uintmax, cclib_type_max(uintmax)));
    sscanf(buffer, "%" cclib_type_pri(uintmax), &out);
    assert(cclib_type_max(uintmax) == cclib_uintmax(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uintmax_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uintmax), cclib_type_printf_cast(uintmax, cclib_type_min(uintmax)));
    sscanf(buffer, "%" cclib_type_pri(uintmax), &out);
    assert(cclib_type_min(uintmax) == cclib_uintmax(out));
  }
}


/** --------------------------------------------------------------------
 ** Pointer-width integer types.
 ** ----------------------------------------------------------------- */

static void
test_sintptr (void)
{
  cclib_sintptr_t		X = cclib_sintptr_const(1);
  cclib_sintptr_t		Y = cclib_sintptr_const(2);
  cclib_sintptr_t		max = cclib_max_sintptr();
  cclib_sintptr_t		min = cclib_min_sintptr();

  assert(X != Y);
  assert(cclib_max_sintptr() == max);
  assert(cclib_min_sintptr() == min);
  assert(cclib_sizeof_sintptr() == sizeof(cclib_sintptr_t));
  assert(cclib_type_max(sintptr) == max);
  assert(cclib_type_min(sintptr) == min);
  assert(cclib_type_sizeof(sintptr) == sizeof(cclib_type_t(sintptr)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sintptr_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sintptr), cclib_type_printf_cast(sintptr, cclib_type_max(sintptr)));
    sscanf(buffer, "%" cclib_type_pri(sintptr), &out);
    assert(cclib_type_max(sintptr) == cclib_sintptr(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_sintptr_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(sintptr), cclib_type_printf_cast(sintptr, cclib_type_min(sintptr)));
    sscanf(buffer, "%" cclib_type_pri(sintptr), &out);
    assert(cclib_type_min(sintptr) == cclib_sintptr(out));
  }
}

static void
test_uintptr (void)
{
  cclib_uintptr_t		X = cclib_uintptr_const(1);
  cclib_uintptr_t		Y = cclib_uintptr_const(2);
  cclib_uintptr_t		max = cclib_max_uintptr();
  cclib_uintptr_t		min = cclib_min_uintptr();

  assert(X != Y);
  assert(cclib_max_uintptr() == max);
  assert(cclib_min_uintptr() == min);
  assert(cclib_sizeof_uintptr() == sizeof(cclib_uintptr_t));
  assert(cclib_type_max(uintptr) == max);
  assert(cclib_type_min(uintptr) == min);
  assert(cclib_type_sizeof(uintptr) == sizeof(cclib_type_t(uintptr)));


  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uintptr_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uintptr), cclib_type_printf_cast(uintptr, cclib_type_max(uintptr)));
    sscanf(buffer, "%" cclib_type_pri(uintptr), &out);
    assert(cclib_type_max(uintptr) == cclib_uintptr(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_uintptr_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(uintptr), cclib_type_printf_cast(uintptr, cclib_type_min(uintptr)));
    sscanf(buffer, "%" cclib_type_pri(uintptr), &out);
    assert(cclib_type_min(uintptr) == cclib_uintptr(out));
  }
}


/** --------------------------------------------------------------------
 ** Pointer-difference-width integer types.
 ** ----------------------------------------------------------------- */

static void
test_ptrdiff (void)
{
  cclib_ptrdiff_t		X = cclib_ptrdiff_const(1);
  cclib_ptrdiff_t		Y = cclib_ptrdiff_const(2);
  cclib_ptrdiff_t		max = cclib_max_ptrdiff();
  cclib_ptrdiff_t		min = cclib_min_ptrdiff();

  assert(X != Y);
  assert(cclib_max_ptrdiff() == max);
  assert(cclib_min_ptrdiff() == min);
  assert(cclib_sizeof_ptrdiff() == sizeof(cclib_ptrdiff_t));
  assert(cclib_type_max(ptrdiff) == max);
  assert(cclib_type_min(ptrdiff) == min);
  assert(cclib_type_sizeof(ptrdiff) == sizeof(cclib_type_t(ptrdiff)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ptrdiff_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ptrdiff), cclib_type_printf_cast(ptrdiff, cclib_type_max(ptrdiff)));
    sscanf(buffer, "%" cclib_type_pri(ptrdiff), &out);
    assert(cclib_type_max(ptrdiff) == cclib_ptrdiff(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ptrdiff_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ptrdiff), cclib_type_printf_cast(ptrdiff, cclib_type_min(ptrdiff)));
    sscanf(buffer, "%" cclib_type_pri(ptrdiff), &out);
    assert(cclib_type_min(ptrdiff) == cclib_ptrdiff(out));
  }
}


/** --------------------------------------------------------------------
 ** Offset-width integer types.
 ** ----------------------------------------------------------------- */

static void
test_off (void)
{
  cclib_off_t		X = cclib_off_const(1);
  cclib_off_t		Y = cclib_off_const(2);
  cclib_off_t		max = cclib_max_off();
  cclib_off_t		min = cclib_min_off();

  assert(X != Y);
  assert(cclib_max_off() == max);
  assert(cclib_min_off() == min);
  assert(cclib_sizeof_off() == sizeof(cclib_off_t));
  assert(cclib_type_max(off) == max);
  assert(cclib_type_min(off) == min);
  assert(cclib_type_sizeof(off) == sizeof(cclib_type_t(off)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_off_t		out;

    snprintf(buffer, 1024, "%" cclib_type_pri(off), cclib_type_printf_cast(off, cclib_type_max(off)));
    sscanf(buffer, "%" cclib_type_pri(off), &out);
    assert(cclib_type_max(off) == cclib_off(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_off_t		out;

    snprintf(buffer, 1024, "%" cclib_type_pri(off), cclib_type_printf_cast(off, cclib_type_min(off)));
    sscanf(buffer, "%" cclib_type_pri(off), &out);
    assert(cclib_type_min(off) == cclib_off(out));
  }
}


/** --------------------------------------------------------------------
 ** Wide-char integer and wide-char integer types.
 ** ----------------------------------------------------------------- */

static void
test_wint (void)
{
  cclib_wint_t		X = cclib_wint_const(1);
  cclib_wint_t		Y = cclib_wint_const(2);
  cclib_wint_t		max = cclib_max_wint();
  cclib_wint_t		min = cclib_min_wint();

  assert(X != Y);
  assert(cclib_max_wint() == max);
  assert(cclib_min_wint() == min);
  assert(cclib_sizeof_wint() == sizeof(cclib_wint_t));
  assert(cclib_type_max(wint) == max);
  assert(cclib_type_min(wint) == min);
  assert(cclib_type_sizeof(wint) == sizeof(cclib_type_t(wint)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_wint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(wint), cclib_type_printf_cast(wint, cclib_type_max(wint)));
    sscanf(buffer, "%" cclib_type_pri(wint), &out);
    assert(cclib_type_max(wint) == cclib_wint(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_wint_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(wint), cclib_type_printf_cast(wint, cclib_type_min(wint)));
    sscanf(buffer, "%" cclib_type_pri(wint), &out);
    assert(cclib_type_min(wint) == cclib_wint(out));
  }
}

static void
test_wchar (void)
{
  cclib_wchar_t		X = cclib_wchar_const(1);
  cclib_wchar_t		Y = cclib_wchar_const(2);
  cclib_wchar_t		max = cclib_max_wchar();
  cclib_wchar_t		min = cclib_min_wchar();

  assert(X != Y);
  assert(cclib_max_wchar() == max);
  assert(cclib_min_wchar() == min);
  assert(cclib_sizeof_wchar() == sizeof(cclib_wchar_t));
  assert(cclib_type_max(wchar) == max);
  assert(cclib_type_min(wchar) == min);
  assert(cclib_type_sizeof(wchar) == sizeof(cclib_type_t(wchar)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_wchar_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(wchar), cclib_type_printf_cast(wchar, cclib_type_max(wchar)));
    sscanf(buffer, "%" cclib_type_pri(wchar), &out);
    assert(cclib_type_max(wchar) == cclib_wchar(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_wchar_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(wchar), cclib_type_printf_cast(wchar, cclib_type_min(wchar)));
    sscanf(buffer, "%" cclib_type_pri(wchar), &out);
    assert(cclib_type_min(wchar) == cclib_wchar(out));
  }
}


/** --------------------------------------------------------------------
 ** Floating-point number types.
 ** ----------------------------------------------------------------- */

static void
test_float (void)
{
  cclib_float_t		X = cclib_float_const(1.0);
  cclib_float_t		Y = cclib_float_const(2.0);
  cclib_float_t		max = cclib_max_float();
  cclib_float_t		min = cclib_min_float();

  assert(X != Y);
  assert(cclib_max_float() == max);
  assert(cclib_min_float() == min);
  assert(cclib_sizeof_float() == sizeof(cclib_float_t));
  assert(cclib_type_max(float) == max);
  assert(cclib_type_min(float) == min);
  assert(cclib_type_sizeof(float) == sizeof(cclib_type_t(float)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_float_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(float), cclib_type_printf_cast(float, cclib_type_max(float)));
    sscanf(buffer, "%" cclib_type_pri(float), &out);
    assert(cclib_type_max(float) == cclib_float(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_float_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(float), cclib_type_printf_cast(float, cclib_type_min(float)));
    sscanf(buffer, "%" cclib_type_pri(float), &out);
    assert(cclib_type_min(float) == cclib_float(out));
  }
}

static void
test_double (void)
{
  cclib_double_t		X = cclib_double_const(1.0);
  cclib_double_t		Y = cclib_double_const(2.0);
  cclib_double_t		max = cclib_max_double();
  cclib_double_t		min = cclib_min_double();

  assert(X != Y);
  assert(cclib_max_double() == max);
  assert(cclib_min_double() == min);
  assert(cclib_sizeof_double() == sizeof(cclib_double_t));
  assert(cclib_type_max(double) == max);
  assert(cclib_type_min(double) == min);
  assert(cclib_type_sizeof(double) == sizeof(cclib_type_t(double)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_double_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(double), cclib_type_printf_cast(double, cclib_type_max(double)));
    sscanf(buffer, "%" cclib_type_pri(double), &out);
    assert(cclib_type_max(double) == cclib_double(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_double_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(double), cclib_type_printf_cast(double, cclib_type_min(double)));
    sscanf(buffer, "%" cclib_type_pri(double), &out);
    assert(cclib_type_min(double) == cclib_double(out));
  }
}

static void
test_ldouble (void)
{
  cclib_ldouble_t		X = cclib_ldouble_const(1.0);
  cclib_ldouble_t		Y = cclib_ldouble_const(2.0);
  cclib_ldouble_t		max = cclib_max_ldouble();
  cclib_ldouble_t		min = cclib_min_ldouble();

  assert(X != Y);
  assert(cclib_max_ldouble() == max);
  assert(cclib_min_ldouble() == min);
  assert(cclib_sizeof_ldouble() == sizeof(cclib_ldouble_t));
  assert(cclib_type_max(ldouble) == max);
  assert(cclib_type_min(ldouble) == min);
  assert(cclib_type_sizeof(ldouble) == sizeof(cclib_type_t(ldouble)));

  /* Conversion to/from string, maximum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ldouble_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ldouble), cclib_type_printf_cast(ldouble, cclib_type_max(ldouble)));
    sscanf(buffer, "%" cclib_type_pri(ldouble), &out);
    assert(cclib_type_max(ldouble) == cclib_ldouble(out));
  }

  /* Conversion to/from string, minimum range value. */
  {
    cclib_char_t	buffer[1024];
    cclib_ldouble_t	out;

    snprintf(buffer, 1024, "%" cclib_type_pri(ldouble), cclib_type_printf_cast(ldouble, cclib_type_min(ldouble)));
    sscanf(buffer, "%" cclib_type_pri(ldouble), &out);
    assert(cclib_type_min(ldouble) == cclib_ldouble(out));
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
  test_word();

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

  test_sint();
  test_uint();

  test_slong();
  test_ulong();

  test_sllong();
  test_ullong();

  test_sintmax();
  test_uintmax();

  test_sintptr();
  test_uintptr();

  test_ptrdiff();
  test_off();

  test_wint();
  test_wchar();

  test_float();
  test_double();
  test_ldouble();

  exit(EXIT_SUCCESS);
}

/* end of file */
