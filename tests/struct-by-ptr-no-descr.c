/*
  Part of: CCLanguage
  Contents: data structure type definition example
  Date: Jan  4, 2019

  Abstract

	This  body file  implements  functions for  the  struct "my_coords_t",  which
	implements the common API.

  Copyright (C) 2019-2020 Marco Maggi <mrc.mgg@gmail.com>

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
 ** Header files.
 ** ----------------------------------------------------------------- */

#include "struct-by-ptr-no-descr.h"
#include <errno.h>
#include <math.h>
#include <stdarg.h>


/** --------------------------------------------------------------------
 ** Data struct "my_coords_t": well known functions.
 ** ----------------------------------------------------------------- */

void
cclib_init(my_coords_t, rec) (my_coords_t * S, my_x_t X, my_y_t Y)
{
  S->X = X;
  S->Y = Y;
}

void
cclib_init(my_coords_t, pol) (my_coords_t * S, my_rho_t RHO, my_theta_t THETA)
{
  S->X = cclib_make(my_x_t, pol)(RHO, THETA);
  S->Y = cclib_make(my_y_t, pol)(RHO, THETA);
}

/* ------------------------------------------------------------------ */

void
cclib_final(my_coords_t) (my_coords_t const * S CCLIB_UNUSED)
{
  if (1) { fprintf(stderr, "%-35s: finalised\n", __func__); }
}

/* ------------------------------------------------------------------ */

static my_coords_t *
cclib_alloc(my_coords_t) (void)
{
  /* We ignore the errors of "malloc()" in this simple test program. */
  return (my_coords_t *)malloc(sizeof(my_coords_t));
}

/* ------------------------------------------------------------------ */

static void
cclib_release(my_coords_t) (my_coords_t const * S)
{
  free((void *)S);
  if (1) { fprintf(stderr, "%-35s: released\n", __func__); }
}

/* ------------------------------------------------------------------ */

my_coords_t const *
cclib_new(my_coords_t, rec) (my_x_t X, my_y_t Y)
{
  my_coords_t * S = cclib_alloc(my_coords_t)();

  cclib_init(my_coords_t, rec)(S, X, Y);
  return S;
}

my_coords_t const *
cclib_new(my_coords_t, pol) (my_rho_t RHO, my_theta_t THETA)
{
  my_coords_t * S = cclib_alloc(my_coords_t)();

  cclib_init(my_coords_t, pol)(S, RHO, THETA);
  return S;
}

/* ------------------------------------------------------------------ */

void
cclib_delete(my_coords_t) (my_coords_t const * S)
{
  cclib_final(my_coords_t)(S);
  cclib_release(my_coords_t)(S);
  if (1) { fprintf(stderr, "%-35s: delete\n", __func__); }
}

/* end of file */
