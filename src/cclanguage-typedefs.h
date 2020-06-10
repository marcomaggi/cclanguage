/*
  Part of: CCLanguage
  Contents: public header file for CCLibraries projects
  Date: Jun  5, 2020

  Abstract

	This header file contains  definitions to be used by all  the packages in the
	CCLibraries project.  It defines some common types.

  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>

  This is free software; you can redistribute  it and/or modify it under the terms of
  the GNU Lesser General Public License as published by the Free Software Foundation;
  either version 3.0 of the License, or (at your option) any later version.

  This library  is distributed in the  hope that it  will be useful, but  WITHOUT ANY
  WARRANTY; without  even the implied  warranty of  MERCHANTABILITY or FITNESS  FOR A
  PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with
  this library; if not, write to the Free Software Foundation, Inc., 59 Temple Place,
  Suite 330, Boston, MA 02111-1307 USA.
*/

#ifndef CCLANGUAGE_TYPEDEFS_H
#define CCLANGUAGE_TYPEDEFS_H 1

#ifdef __cplusplus
extern "C" {
#endif


/** --------------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------------- */

#include <cclanguage-platform.h>


/** --------------------------------------------------------------------
 ** Helper macros.
 ** ----------------------------------------------------------------- */

#define CCLIB_STRUCT_TYPEDEF(STRUCT)	typedef struct STRUCT STRUCT


/** --------------------------------------------------------------------
 ** Common type definitions: opaque data structures handling.
 ** ----------------------------------------------------------------- */

typedef void				cclib_resource_data_t;
typedef cclib_resource_data_t *		cclib_resource_pointer_t;

#undef  cclib_resource_pointer
#define cclib_resource_pointer(EXPR)	((cclib_resource_pointer_t)(EXPR))


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* defined CCLANGUAGE_TYPEDEFS_H */

/* end of file */
