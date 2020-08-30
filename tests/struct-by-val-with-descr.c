/*
  Part of: CCLanguage
  Contents: example of data structure type implementing the common API
  Date: Apr 12, 2020

  Abstract

	This source file defines the struct "my_coords_t", passed as value, using the
	common structs API, using the struct descriptor API.

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
 ** Descrs.
 ** ----------------------------------------------------------------- */

#include "struct-by-val-with-descr.h"


/** --------------------------------------------------------------------
 ** Data struct "my_coords_t": methods table.
 ** ----------------------------------------------------------------- */

/* A prototype for every method. */
static cclib_method_type(my_coords_t, destroy)	cclib_method_implementation(my_coords_t, destroy);
static cclib_method_type(my_coords_t, print)	cclib_method_implementation(my_coords_t, print);

/* The methods table. */
static cclib_methods_table_type(my_coords_t) const cclib_methods_table(my_coords_t) = {
  .destroy	= cclib_method_implementation(my_coords_t, destroy),
  .print	= cclib_method_implementation(my_coords_t, print)
};


/** --------------------------------------------------------------------
 ** Data struct "my_coords_t": well known functions.
 ** ----------------------------------------------------------------- */

my_coords_t
cclib_make(my_coords_t, rec) (my_x_t X, my_y_t Y)
{
  my_coords_t	S = {
    /* We ignore "malloc()" errors in this simple program. */
    .X = malloc(sizeof(my_x_t)),
    .Y = malloc(sizeof(my_y_t))
  };

  cclib_struct_with_methods_field_set_methods_table_pointer(&S, &cclib_methods_table(my_coords_t));
  *(S.X) = X;
  *(S.Y) = Y;
  return S;
}

my_coords_t
cclib_make(my_coords_t, pol) (my_rho_t RHO, my_theta_t THETA)
{
  return cclib_make(my_coords_t, rec)(cclib_make(my_x_t, pol)(RHO, THETA),
				      cclib_make(my_y_t, pol)(RHO, THETA));
}

void
cclib_unmake(my_coords_t) (my_coords_t S)
{
  fprintf(stderr, "%s: enter unmake function\n", __func__);
  free(S.X);
  free(S.Y);
  fprintf(stderr, "%s: unmade \n", __func__);
}

void
cclib_final(my_coords_t) (my_coords_t * SP)
{
  cclib_unmake(my_coords_t)(*SP);
}


/** --------------------------------------------------------------------
 ** Method implementations: destructor methods.
 ** ----------------------------------------------------------------- */

void
cclib_method_implementation(my_coords_t, destroy) (my_coords_t self)
{
  cclib_unmake(my_coords_t)(self);
}

void
cclib_method_implementation(my_coords_t, print) (my_coords_t self, FILE * stream)
{
  fprintf(stream, "my_coords_t: %s: X=%f, Y=%f\n", __func__, self.X->val, self.Y->val);
}

/* end of file */
