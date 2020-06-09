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
#  define CCLIB_FUNC_ATTRIBUTE_ALWAYS_INLINE	__attribute__((__always_inline__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_ALWAYS_INLINE	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define CCLIB_FUNC_ATTRIBUTE_CONST		__attribute__((__const__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_CONST	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define CCLIB_FUNC_ATTRIBUTE_CONSTRUCTOR	__attribute__((__constructor__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_CONSTRUCTOR	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define CCLIB_FUNC_ATTRIBUTE_DLLEXPORT	__attribute__((__dllexport__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_DLLEXPORT	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define CCLIB_FUNC_ATTRIBUTE_DLLIMPORT	__attribute__((__dllimport__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_DLLIMPORT	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define CCLIB_FUNC_ATTRIBUTE_FORMAT(...)	__attribute__((__format__(__VA_ARGS__)))
#else
#  define CCLIB_FUNC_ATTRIBUTE_FORMAT	/* empty string */
#endif

#if (((defined __GNUC__) && (__GNUC__ >= 4)) || (defined __clang__))
#  define CCLIB_FUNC_ATTRIBUTE_HOT		__attribute__((__hot__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_HOT	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_LEAF		__attribute__((__leaf__))
#elif (defined __clang__)
/* Clang does not recognise "leaf".  (Marco Maggi; Apr 21, 2020) */
#  define CCLIB_FUNC_ATTRIBUTE_LEAF	/* empty string */
#else
#  define CCLIB_FUNC_ATTRIBUTE_LEAF	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_NONNULL(...)	__attribute__((__nonnull__(__VA_ARGS__)))
#else
#  define CCLIB_FUNC_ATTRIBUTE_NONNULL	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_NORETURN		__attribute__((__noreturn__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_NORETURN	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_PURE		__attribute__((__pure__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_PURE	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL	__attribute__((__returns_nonnull__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_UNUSED		__attribute__((__unused__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_UNUSED	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_USED		__attribute__((__used__))
#else
#  define CCLIB_FUNC_ATTRIBUTE_USED	/* empty string */
#endif

#if ((defined __GNUC__) && (__GNUC__ >= 4))
#  define CCLIB_FUNC_ATTRIBUTE_VISIBILITY(...)	__attribute__((__visibility__(__VA_ARGS__)))
#else
#  define CCLIB_FUNC_ATTRIBUTE_VISIBILITY	/* empty string */
#endif


/** --------------------------------------------------------------------
 ** Preliminary definitions.
 ** ----------------------------------------------------------------- */

/* The macro  CCLIB_UNUSED indicates that  a function, function argument  or variable
   may potentially be unused. Usage examples:

   static int unused_function (char arg) CCLIB_UNUSED;
   int foo (char unused_argument CCLIB_UNUSED);
   int unused_variable CCLIB_UNUSED;
*/
#define CCLIB_UNUSED		CCLIB_FUNC_ATTRIBUTE_UNUSED

#ifndef __GNUC__
#  define __builtin_expect(...)	/* empty */
#endif

#if (defined _WIN32 || defined __CYGWIN__)
#  ifdef BUILDING_DLL
#    ifdef __GNUC__
#      define cclib_decl	CCLIB_FUNC_ATTRIBUTE_DLLEXPORT extern
#    else
#      define cclib_decl	__declspec(dllexport) extern
#    endif
#  else
#    ifdef __GNUC__
#      define cclib_decl	CCLIB_FUNC_ATTRIBUTE_DLLIMPORT extern
#    else
#      define cclib_decl	__declspec(dllimport) extern
#    endif
#  endif
#  define cclib_private_decl	extern
#else
#  define cclib_decl		CCLIB_FUNC_ATTRIBUTE_VISIBILITY("default") extern
#  define cclib_private_decl	CCLIB_FUNC_ATTRIBUTE_VISIBILITY("hidden")  extern
#endif


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* defined CCLANGUAGE_COMPILER_H */

/* end of file */
