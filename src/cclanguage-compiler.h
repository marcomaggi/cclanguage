/*
  Part of: CCLanguage
  Contents: public header file for CCLibraries projects
  Date: Jun  5, 2020

  Abstract

	This header file contains  definitions to be used by all  the packages in the
	CCLibraries  project.   It   defines  what  is  needed   to  use  compilers's
	facilities.

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

#ifndef CCLANGUAGE_COMPILER_H
#define CCLANGUAGE_COMPILER_H 1

#ifdef __cplusplus
extern "C" {
#endif


/** --------------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------------- */


/** --------------------------------------------------------------------
 ** Compiler attributes.
 ** ----------------------------------------------------------------- */

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define cclib_func_attribute_always_inline	__attribute__((__always_inline__))
#else
#  define cclib_func_attribute_always_inline	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define cclib_func_attribute_const		__attribute__((__const__))
#else
#  define cclib_func_attribute_const	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define cclib_func_attribute_constructor	__attribute__((__constructor__))
#else
#  define cclib_func_attribute_constructor	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define cclib_func_attribute_dllexport	__attribute__((__dllexport__))
#else
#  define cclib_func_attribute_dllexport	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define cclib_func_attribute_dllimport	__attribute__((__dllimport__))
#else
#  define cclib_func_attribute_dllimport	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define cclib_func_attribute_format(...)	__attribute__((__format__(__VA_ARGS__)))
#else
#  define cclib_func_attribute_format	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define cclib_func_attribute_hot		__attribute__((__hot__))
#else
#  define cclib_func_attribute_hot	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_leaf		__attribute__((__leaf__))
#elif (defined __clang__)
/* Clang does not recognise "leaf".  (Marco Maggi; Apr 21, 2020) */
#  define cclib_func_attribute_leaf	/* empty string */
#else
#  define cclib_func_attribute_leaf	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_nonnull(...)	__attribute__((__nonnull__(__VA_ARGS__)))
#else
#  define cclib_func_attribute_nonnull	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_noreturn		__attribute__((__noreturn__))
#else
#  define cclib_func_attribute_noreturn	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_pure		__attribute__((__pure__))
#else
#  define cclib_func_attribute_pure	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_returns_nonnull	__attribute__((__returns_nonnull__))
#else
#  define cclib_func_attribute_returns_nonnull	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_unused		__attribute__((__unused__))
#else
#  define cclib_func_attribute_unused	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_used		__attribute__((__used__))
#else
#  define cclib_func_attribute_used	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define cclib_func_attribute_visibility(...)	__attribute__((__visibility__(__VA_ARGS__)))
#else
#  define cclib_func_attribute_visibility	/* empty string */
#endif

#define cclib_func_attribute_visibility_default		cclib_func_attribute_visibility("default")
#define cclib_func_attribute_visibility_hidden		cclib_func_attribute_visibility("hidden")


/** --------------------------------------------------------------------
 ** Preliminary definitions.
 ** ----------------------------------------------------------------- */

/* The macro  CCLIB_UNUSED indicates that  a function, function argument  or variable
   may potentially be unused. Usage examples:

   static int unused_function (char arg) CCLIB_UNUSED;
   int foo (char unused_argument CCLIB_UNUSED);
   int unused_variable CCLIB_UNUSED;
*/
#define CCLIB_UNUSED		cclib_func_attribute_unused

#ifndef __GNUC__
#  define __builtin_expect(...)	/* empty */
#endif

#if (defined _WIN32 || defined __CYGWIN__)
#  ifdef BUILDING_DLL
#    ifdef __GNUC__
#      define cclib_decl	cclib_func_attribute_dllexport extern
#    else
#      define cclib_decl	__declspec(dllexport) extern
#    endif
#  else
#    ifdef __GNUC__
#      define cclib_decl	cclib_func_attribute_dllimport extern
#    else
#      define cclib_decl	__declspec(dllimport) extern
#    endif
#  endif
#  define cclib_private_decl	extern
#else
#  define cclib_decl		cclib_func_attribute_visibility_default extern
#  define cclib_private_decl	cclib_func_attribute_visibility_hidden  extern
#endif


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* defined CCLANGUAGE_COMPILER_H */

/* end of file */
