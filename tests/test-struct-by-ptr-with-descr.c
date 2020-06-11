/*
  Part of: CCLanguage
  Contents: test file for sample struct with descriptor
  Date: Dec 27, 2018

  Abstract

	This  test   program  checks  the  behaviour   of  the  API  of   the  struct
	"my_complex_t" implemented as "struct with descr".  See the documentation for
	details.

  Copyright (C) 2018-2020 Marco Maggi <mrc.mgg@gmail.com>

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

#include "struct-by-ptr-with-descr.h"
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Allocation and destruction, explicit destructor call.
 ** ----------------------------------------------------------------- */

void
test_1_1_1 (void)
/* Allocate  the  struct on  the  stack,  then  destroy  by excplicitly  calling  the
   "final()" function. */
{
  my_complex_t		A[1];

  cclib_init(my_complex_t, rec)(A,
				cclib_make(my_real_part_t)(1.0),
				cclib_make(my_imag_part_t)(2.0));

  cclib_call(print, A, stderr);
  cclib_final(my_complex_t)(A);
}

void
test_1_1_2 (void)
/* Allocate  the  struct on  the  stack,  then  destroy  by excplicitly  calling  the
   "destroy()" method. */
{
  my_complex_t		A[1];

  cclib_init(my_complex_t, rec)(A,
				cclib_make(my_real_part_t)(1.0),
				cclib_make(my_imag_part_t)(2.0));

  cclib_call(print, A, stderr);
  cclib_call(destroy, A);
}

void
test_1_2_1 (void)
/* Allocate  the struct  on  the heap,  then  destroy it  by  explicitly calling  the
   "delete()" function. */
{
  my_complex_t const *A = cclib_new(my_complex_t, rec)(cclib_make(my_real_part_t)(1.0),
						       cclib_make(my_imag_part_t)(2.0));
  cclib_call(print, A, stderr);
  cclib_delete(my_complex_t)(A);
}

void
test_1_2_2 (void)
/* Allocate  the struct  on  the heap,  then  destroy it  by  explicitly calling  the
   "destroy()" method. */
{
  my_complex_t const *A = cclib_new(my_complex_t, rec)(cclib_make(my_real_part_t)(1.0),
						       cclib_make(my_imag_part_t)(2.0));

  cclib_call(print, A, stderr);
  cclib_call(destroy, A);
}


int
main (void)
{
  test_1_1_1();
  test_1_1_2();
  test_1_2_1();
  test_1_2_2();

  exit(EXIT_SUCCESS);
}

/* end of file */
