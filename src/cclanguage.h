/*
  Part of: CCLanguage
  Contents: public header file for CCLanguage projects
  Date: Mar 30, 2020

  Abstract

	This header file contains  definitions to be used by all  the packages in the
	CCLibraries project.

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

#ifndef CCLANGUAGE_H
#define CCLANGUAGE_H 1

#ifdef __cplusplus
extern "C" {
#endif


/** --------------------------------------------------------------------
 ** Helper macros.
 ** ----------------------------------------------------------------- */

/* Pointer cast macro helper. */
#define CCLIB_PC(TYPE,X,Y)		TYPE * X = (TYPE *) (Y)

/* Type cast macro helper. */
#define CCLIB_CAST(TYPE,X,Y)		TYPE X = (TYPE) (Y)


/** --------------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------------- */

#include <cclanguage-compiler.h>
#include <cclanguage-typedefs.h>
#include <cclanguage-variadic-macros.h>
#include <cclanguage-structs.h>


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

cclib_decl char const *	cclang_version_string			(void);
cclib_decl int		cclang_version_interface_current	(void);
cclib_decl int		cclang_version_interface_revision	(void);
cclib_decl int		cclang_version_interface_age		(void);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* defined CCLANGUAGE_H */

/* end of file */
