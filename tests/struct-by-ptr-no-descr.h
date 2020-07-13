/*
  Part of: CCLanguage
  Contents: data structure type definition example
  Date: Jan 11, 2019

  Abstract

	This  header file  defines the  struct "my_coords_t"  using the  "common data
	structures API", it defines no struct descriptor.

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

#ifndef STRUCT_BY_PTR_NO_DESCR_H
#define STRUCT_BY_PTR_NO_DESCR_H

#ifdef __cplusplus
extern "C" {
#endif


/** --------------------------------------------------------------------
 ** Descrs.
 ** ----------------------------------------------------------------- */

#include <cclanguage.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/** --------------------------------------------------------------------
 ** Preliminary type definitions.
 ** ----------------------------------------------------------------- */

#undef  MY_DEFINE_PARM
#define MY_DEFINE_PARM(NAME)				    \
  cclib_struct_typedef(my_ ## NAME ## _t);		    \
							    \
  struct my_ ## NAME ## _t {				    \
    double	val;					    \
  };							    \
							    \
  CCLIB_FUNC_ATTRIBUTE_ALWAYS_INLINE			    \
  static inline my_ ## NAME ## _t			    \
  cclib_make(my_ ## NAME ## _t) (double val)		    \
  {							    \
    return (my_ ## NAME ## _t) { .val = val };		    \
  }

MY_DEFINE_PARM(x)
MY_DEFINE_PARM(y)
MY_DEFINE_PARM(rho)
MY_DEFINE_PARM(theta)

CCLIB_FUNC_ATTRIBUTE_ALWAYS_INLINE
static inline my_x_t
cclib_make(my_x_t, pol) (my_rho_t rho, my_theta_t theta)
{
  return (my_x_t) { .val = rho.val * cos(theta.val) };
}

CCLIB_FUNC_ATTRIBUTE_ALWAYS_INLINE
static inline my_y_t
cclib_make(my_y_t, pol) (my_rho_t rho, my_theta_t theta)
{
  return (my_y_t) { .val = rho.val * sin(theta.val) };
}


/** --------------------------------------------------------------------
 ** Type definitions: data struct "my_coords_t".
 ** ----------------------------------------------------------------- */

cclib_struct_typedef(my_coords_t);

struct my_coords_t {
  my_x_t	X;
  my_y_t	Y;
};


/** --------------------------------------------------------------------
 ** Data struct "my_coords_t": well known functions API.
 ** ----------------------------------------------------------------- */

cclib_decl void cclib_init(my_coords_t, rec) (my_coords_t * S, my_x_t X, my_y_t Y)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl void cclib_init(my_coords_t, pol) (my_coords_t * S, my_rho_t RHO, my_theta_t THETA)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

cclib_decl void cclib_final(my_coords_t) (my_coords_t const * S)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

cclib_decl my_coords_t const * cclib_new(my_coords_t, rec) (my_x_t X, my_y_t Y)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl my_coords_t const * cclib_new(my_coords_t, pol) (my_rho_t RHO, my_theta_t THETA)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

/* ------------------------------------------------------------------ */

cclib_decl void cclib_delete(my_coords_t) (my_coords_t const * S)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* define STRUCT_BY_PTR_NO_DESCR_H */

/* end of file */
