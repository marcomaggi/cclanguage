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
 ** Char types.
 ** ----------------------------------------------------------------- */

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
}


/** --------------------------------------------------------------------
 ** Let's go.
 ** ----------------------------------------------------------------- */

int
main (void)
{
  test_schar();
  test_uchar();

  exit(EXIT_SUCCESS);
}

/* end of file */
