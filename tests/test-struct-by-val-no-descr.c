/*
  Part of: CCLanguage
  Contents: demo program for structs as values with no descriptor, test program
  Date: Apr 11, 2020

  Abstract

	This  test   program  checks  the  behaviour   of  the  API  of   the  struct
	"my_coords_t", passed as value, using  the common structs API, without struct
	descriptor API.

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
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "struct-by-val-no-descr.h"


/** --------------------------------------------------------------------
 ** Allocation on the stack, no handlers.
 ** ----------------------------------------------------------------- */

static void
test_1_1 (void)
/* Make the struct, then destroy it with the "unmake()" function. */
{
  my_coords_t	A = cclib_make(my_coords_t, rec)(cclib_make(my_x_t)(1.0),
						 cclib_make(my_y_t)(2.0));

  fprintf(stderr, "%s: X=%f, Y=%f\n", __func__, A.X->val, A.Y->val);
  cclib_unmake(my_coords_t)(A);
}

static void
test_1_2 (void)
/* Make the struct, then destroy it with the "final()" function. */
{
  my_coords_t	A = cclib_make(my_coords_t, rec)(cclib_make(my_x_t)(1.0),
						 cclib_make(my_y_t)(2.0));

  fprintf(stderr, "%s: X=%f, Y=%f\n", __func__, A.X->val, A.Y->val);
  cclib_final(my_coords_t)(&A);
}


int
main (void)
{
  test_1_1();
  test_1_2();

  exit(EXIT_SUCCESS);
}

/* end of file */
