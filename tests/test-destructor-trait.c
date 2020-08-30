/*
  Part of: CCLanguage
  Contents: test program for the example destructor trait
  Date: Apr 12, 2020

  Abstract

	This  test program  checks  the  behaviour of  the  example destructor  trait
	defined in the header file "examples/destructor-trait.h".

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

#include "destructor-trait.h"
#include "struct-by-ptr-with-descr.h"
#include "struct-by-val-with-descr.h"


/** --------------------------------------------------------------------
 ** The destructor trait as implemented by my_coords_t.
 ** ----------------------------------------------------------------- */

/* A prototype for every method in the destructor trait implementation. */
static cclib_method_type(my_destructor_T, destroy)	cclib_method_implementation(my_destructor_T, destroy, my_coords_t);

/* The table  of methods  for the  destructor trait as  implemented by  the structure
   "my_coords_t". */
static cclib_methods_table_type(my_destructor_T) const cclib_methods_table(my_destructor_T, my_coords_t) = {
  .destroy = cclib_method_implementation(my_destructor_T, destroy, my_coords_t),
};

my_destructor_T
cclib_make(my_destructor_T, my_coords_t) (my_coords_t const * self)
/* The constructor for my_destructor_T implemented by "my_coords_t". */
{
  return cclib_make(my_destructor_T)(cclib_resource_pointer(self), &cclib_methods_table(my_destructor_T, my_coords_t));
}

void
cclib_method_implementation(my_destructor_T, destroy, my_coords_t) (my_destructor_T impl)
/* Implementation  of  the  method  "destroy()" of  the  trait  "my_destructor_T"  as
   implemented by the data type "my_coords_t". */
{
  fprintf(stderr, "%s: enter method destroy\n", __func__);
  {
    my_coords_t const	* self = cclib_trait_resource_pointer(impl);

    cclib_vcall_method(destroy, *self);
  }
  fprintf(stderr, "%s: method destroy done\n", __func__);
}


/** --------------------------------------------------------------------
 ** The destructor trait as implemented by my_complex_t.
 ** ----------------------------------------------------------------- */

/* A prototype for every method in the destructor trait implementation. */
static cclib_method_type(my_destructor_T, destroy)	cclib_method_implementation(my_destructor_T, destroy, my_complex_t);

/* The table  of methods  for the  destructor trait as  implemented by  the structure
   "my_complex_t". */
static cclib_methods_table_type(my_destructor_T) const cclib_methods_table(my_destructor_T, my_complex_t) = {
  .destroy = cclib_method_implementation(my_destructor_T, destroy, my_complex_t),
};

my_destructor_T
cclib_make(my_destructor_T, my_complex_t) (my_complex_t const * self)
/* The constructor for my_destructor_T implemented by "my_complex_t". */
{
  return cclib_make(my_destructor_T)(cclib_resource_pointer(self), &cclib_methods_table(my_destructor_T, my_complex_t));
}

void
cclib_method_implementation(my_destructor_T, destroy, my_complex_t) (my_destructor_T impl)
/* Implementation  of  the  method  "destroy()" of  the  trait  "my_destructor_T"  as
   implemented by the data type "my_complex_t". */
{
  fprintf(stderr, "%s: enter method destroy\n", __func__);
  {
    my_complex_t const	* self = cclib_trait_resource_pointer(impl);

    cclib_call_method(destroy, self);
  }
  fprintf(stderr, "%s: method destroy done\n", __func__);
}


/** --------------------------------------------------------------------
 ** Test for the data structure as value.
 ** ----------------------------------------------------------------- */

void
test_1_1 (void)
/* Make the struct, then destroy it with the "unmake()" common function. */
{
  my_coords_t	A = cclib_make(my_coords_t, rec)(cclib_make(my_x_t)(1.0),
						 cclib_make(my_y_t)(2.0));

  cclib_vcall_method(print, A, stderr);
  cclib_unmake(my_coords_t)(A);
}

void
test_1_2 (void)
/* Make the struct, then destroy it with the "final()" common function. */
{
  my_coords_t	A = cclib_make(my_coords_t, rec)(cclib_make(my_x_t)(1.0), cclib_make(my_y_t)(2.0));

  cclib_vcall_method(print, A, stderr);
  cclib_final(my_coords_t)(&A);
}

void
test_1_3 (void)
/* Make the struct, then destroy it with the "destroy()" method of "my_coords_t". */
{
  my_coords_t	A  = cclib_make(my_coords_t, rec)(cclib_make(my_x_t)(1.0), cclib_make(my_y_t)(2.0));

  cclib_vcall_method(print, A, stderr);
  cclib_vcall_method(destroy, A);
}

void
test_1_4 (void)
/* Make the  struct, then destroy  it with the  "destroy()" method of  the destructor
   trait. */
{
  my_coords_t		A  = cclib_make(my_coords_t, rec)(cclib_make(my_x_t)(1.0), cclib_make(my_y_t)(2.0));
  my_destructor_T	AD = cclib_make(my_destructor_T, my_coords_t)(&A);

  cclib_vcall_method(print, A, stderr);
  cclib_vcall_method(destroy, AD);
}


/** --------------------------------------------------------------------
 ** Test for the data structure as value.
 ** ----------------------------------------------------------------- */

void
test_2_1 (void)
/* Allocate  the struct  on the  heap,  then destroy  it with  the "delete()"  common
   function. */
{
  my_complex_t const *	A = cclib_new(my_complex_t, rec)(cclib_make(my_real_part_t)(1.0), cclib_make(my_imag_part_t)(2.0));

  cclib_call_method(print, A, stderr);
  cclib_delete(my_complex_t)(A);
}

void
test_2_2 (void)
/* Allocate  the struct  on the  stack,  then destroy  it with  the "final()"  common
   function. */
{
  my_complex_t	A[1];

  cclib_init(my_complex_t, rec)(A, cclib_make(my_real_part_t)(1.0), cclib_make(my_imag_part_t)(2.0));

  cclib_call_method(print, A, stderr);
  cclib_final(my_complex_t)(A);
}

void
test_2_3 (void)
/* Allocate the struct  on the heap, then  destroy it with the  "destroy()" method of
   "my_complex_t". */
{
  my_complex_t const *	A = cclib_new(my_complex_t, rec)(cclib_make(my_real_part_t)(1.0), cclib_make(my_imag_part_t)(2.0));

  cclib_call_method(print, A, stderr);
  cclib_call_method(destroy, A);
}

void
test_2_4 (void)
/* Allocate the struct on  the stack, then destroy it with  the "destroy()" method of
   "my_complex_t". */
{
  my_complex_t	A[1];

  cclib_init(my_complex_t, rec)(A, cclib_make(my_real_part_t)(1.0), cclib_make(my_imag_part_t)(2.0));

  cclib_call_method(print, A, stderr);
  cclib_call_method(destroy, A);
}

void
test_2_5 (void)
/* Allocate the struct  on the heap, then  destroy it with the  "destroy()" method of
   the destructor trait. */
{
  my_complex_t const *	A  = cclib_new(my_complex_t, rec)(cclib_make(my_real_part_t)(1.0), cclib_make(my_imag_part_t)(2.0));
  my_destructor_T	AD = cclib_make(my_destructor_T, my_complex_t)(A);

  cclib_call_method(print, A, stderr);
  cclib_vcall_method(destroy, AD);
}

void
test_2_6 (void)
/* Allocate the struct on  the stack, then destroy it with  the "destroy()" method of
   the destructor trait. */
{
  my_complex_t		A[1];
  my_destructor_T	AD;

  cclib_init(my_complex_t, rec)(A, cclib_make(my_real_part_t)(1.0), cclib_make(my_imag_part_t)(2.0));
  AD = cclib_make(my_destructor_T, my_complex_t)(A);

  cclib_call_method(print, A, stderr);
  cclib_vcall_method(destroy, AD);
}


int
main (void)
{
  test_1_1();
  test_1_2();
  test_1_3();
  test_1_4();

  test_2_1();
  test_2_2();
  test_2_3();
  test_2_4();
  test_2_5();
  test_2_6();

  exit(EXIT_SUCCESS);
}

/* end of file */
