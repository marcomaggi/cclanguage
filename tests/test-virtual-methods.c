/*
  Part of: CCLanguage
  Contents: tests for virtual methods
  Date: Jun 29, 2020

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
 ** Thing struct type definitions.
 ** ----------------------------------------------------------------- */

CCLIB_STRUCT_TYPEDEF(cclib_methods_table_t(my_thing_t));

typedef int cclib_method_t(my_thing_t, alpha) (int a);
typedef int cclib_method_t(my_thing_t, beta)  (int b);

#define CCLIB_METHODS_TABLE_MY_THING_T			    \
  cclib_method_t(my_thing_t, alpha)	*alpha;		    \
  cclib_method_t(my_thing_t, beta)	*beta

struct cclib_methods_table_t(my_thing_t) {
  CCLIB_METHODS_TABLE_MY_THING_T;
};


/** --------------------------------------------------------------------
 ** Thing struct methods.
 ** ----------------------------------------------------------------- */

static cclib_method_t(my_thing_t, alpha)	cclib_method(my_thing_t, alpha);
static cclib_method_t(my_thing_t, beta)		cclib_method(my_thing_t, beta);

int
cclib_method(my_thing_t, alpha) (int a)
{
  return a;
}

int
cclib_method(my_thing_t, beta) (int b)
{
  return b;
}


/** --------------------------------------------------------------------
 ** Thing struct table of methods.
 ** ----------------------------------------------------------------- */

static cclib_methods_table_t(my_thing_t) const cclib_methods_table(my_thing_t) = {
  .alpha	= cclib_method(my_thing_t, alpha),
  .beta		= cclib_method(my_thing_t, beta),
};


/** --------------------------------------------------------------------
 ** Stuff struct type definitions.
 ** ----------------------------------------------------------------- */

CCLIB_STRUCT_TYPEDEF(cclib_methods_table_t(my_stuff_t));

typedef int cclib_method_t(my_stuff_t, delta) (int d);
typedef int cclib_method_t(my_stuff_t, gamma) (int g);

struct cclib_methods_table_t(my_stuff_t) {
  CCLIB_METHODS_TABLE_MY_THING_T;
  cclib_method_t(my_stuff_t, delta)	*delta;
  cclib_method_t(my_stuff_t, gamma)	*gamma;
};


/** --------------------------------------------------------------------
 ** Stuff struct methods.
 ** ----------------------------------------------------------------- */

static cclib_method_t(my_thing_t, beta)		cclib_method(my_stuff_t, beta);
static cclib_method_t(my_stuff_t, delta)	cclib_method(my_stuff_t, delta);
static cclib_method_t(my_stuff_t, gamma)	cclib_method(my_stuff_t, gamma);

int
cclib_method(my_stuff_t, beta) (int b)
{
  return 10 + b;
}

int
cclib_method(my_stuff_t, delta) (int d)
{
  return d;
}

int
cclib_method(my_stuff_t, gamma) (int g)
{
  return g;
}


/** --------------------------------------------------------------------
 ** Stuff struct table of methods.
 ** ----------------------------------------------------------------- */

static cclib_methods_table_t(my_stuff_t) cclib_methods_table(my_stuff_t) = {
  .delta	= cclib_method(my_stuff_t, delta),
  .gamma	= cclib_method(my_stuff_t, gamma),
};


/** --------------------------------------------------------------------
 ** Let's go.
 ** ----------------------------------------------------------------- */

static void
initialise_methods_tables (void)
{
  /* Copy the methods from "my_thing_t"'s table into "my_stuff_t"'s table. */
  CCLIB_PC(cclib_methods_table_type(my_thing_t), T, &cclib_methods_table(my_stuff_t));
  *T = cclib_methods_table(my_thing_t);

  /* Override method "beta" for "my_stuff_t". */
  cclib_methods_table(my_stuff_t).beta = cclib_method(my_stuff_t, beta);
}

int
main (void)
{
  initialise_methods_tables();

  assert(1 == cclib_methods_table(my_thing_t).alpha(1));
  assert(2 == cclib_methods_table(my_thing_t).beta(2));

  assert(1  == cclib_methods_table(my_stuff_t).alpha(1));
  assert(12 == cclib_methods_table(my_stuff_t).beta(2));
  assert(3  == cclib_methods_table(my_stuff_t).delta(3));
  assert(4  == cclib_methods_table(my_stuff_t).gamma(4));

  exit(EXIT_SUCCESS);
}

/* end of file */
