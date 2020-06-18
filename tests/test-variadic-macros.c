/*
  Part of: CCLanguage
  Contents: test the facilities of variadic macros
  Date: Jun 18, 2020

  Abstract

	Tests for the facilities of the cclibraries.h header.

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
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Variadic macros: counting arguments.
 ** ----------------------------------------------------------------- */

static void
test_variadic_macros_counting_arguments (void)
{
  assert(1 == CCLIB_VNAME_PRIVATE_COUNT_ARGS());
  assert(1 == CCLIB_VNAME_PRIVATE_COUNT_ARGS(alpha));
  assert(2 == CCLIB_VNAME_PRIVATE_COUNT_ARGS(alpha,beta));
  assert(3 == CCLIB_VNAME_PRIVATE_COUNT_ARGS(alpha,beta,delta));
}


/** --------------------------------------------------------------------
 ** Variadic macros: variadic functions.
 ** ----------------------------------------------------------------- */

#define my_one(...)	CCLIB_VNAME(my_one,__VA_ARGS__)

static int
my_one_1 (int arg)
{
  return arg;
}

static int
my_one_2 (int arg1, int arg2)
{
  return arg1 + arg2;
}

static void
test_variadic_macros_variadic_functions (void)
{
  assert(1 == my_one(1));
  assert(5 == my_one(2,3));
}


/** --------------------------------------------------------------------
 ** Variadic macros: names composition.
 ** ----------------------------------------------------------------- */

#define my_two_1(A1)		my_two_ ## A1
#define my_two_2(A1,A2)		my_two_ ## A1 ## _ ## A2
#define my_two_63(A01, A02, A03, A04, A05, A06, A07, A08, A09, A10,	\
		  A11, A12, A13, A14, A15, A16, A17, A18, A19, A20,	\
		  A21, A22, A23, A24, A25, A26, A27, A28, A29, A30,	\
		  A31, A32, A33, A34, A35, A36, A37, A38, A39, A40,	\
		  A41, A42, A43, A44, A45, A46, A47, A48, A49, A50,	\
		  A51, A52, A53, A54, A55, A56, A57, A58, A59, A60,	\
		  A61, A62, A63)					\
  my_two_ ##								\
  A01 ## A02 ## A03 ## A04 ## A05 ## A06 ## A07 ## A08 ## A09 ## A10 ##	\
  A11 ## A12 ## A13 ## A14 ## A15 ## A16 ## A17 ## A18 ## A19 ## A20 ##	\
  A21 ## A22 ## A23 ## A24 ## A25 ## A26 ## A27 ## A28 ## A29 ## A30 ##	\
  A31 ## A32 ## A33 ## A34 ## A35 ## A36 ## A37 ## A38 ## A39 ## A40 ##	\
  A41 ## A42 ## A43 ## A44 ## A45 ## A46 ## A47 ## A48 ## A49 ## A50 ##	\
  A51 ## A52 ## A53 ## A54 ## A55 ## A56 ## A57 ## A58 ## A59 ## A60 ##	\
  A61 ## A62 ## A63
#define my_two(...)		CCLIB_VNAME(my_two,__VA_ARGS__)

int
my_two(alpha) (int arg)
{
  return arg;
}

int
my_two(alpha,beta) (int arg1, int arg2, int arg3)
{
  return arg1 + arg2 + arg3;
}

int
my_two(X01, X02, X03, X04, X05, X06, X07, X08, X09, X10,
       X11, X12, X13, X14, X15, X16, X17, X18, X19, X20,
       X21, X22, X23, X24, X25, X26, X27, X28, X29, X30,
       X31, X32, X33, X34, X35, X36, X37, X38, X39, X40,
       X41, X42, X43, X44, X45, X46, X47, X48, X49, X50,
       X51, X52, X53, X54, X55, X56, X57, X58, X59, X60,
       X61, X62, X63) (int arg)
{
  return -arg;
}

void
test_variadic_macros_names_composition (void)
{
  assert(1 == my_two(alpha)(1));
  assert(7 == my_two(alpha,beta)(1,2,4));
  assert(-123 == my_two(X01, X02, X03, X04, X05, X06, X07, X08, X09, X10,
			X11, X12, X13, X14, X15, X16, X17, X18, X19, X20,
			X21, X22, X23, X24, X25, X26, X27, X28, X29, X30,
			X31, X32, X33, X34, X35, X36, X37, X38, X39, X40,
			X41, X42, X43, X44, X45, X46, X47, X48, X49, X50,
			X51, X52, X53, X54, X55, X56, X57, X58, X59, X60,
			X61, X62, X63)(123));
}


int
main (void)
{
  if (1) { test_variadic_macros_counting_arguments(); }
  if (1) { test_variadic_macros_variadic_functions(); }
  if (1) { test_variadic_macros_names_composition(); }

  exit(EXIT_SUCCESS);
}

/* end of file */
