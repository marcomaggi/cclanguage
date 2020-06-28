/*
  Part of: CCLanguage
  Contents: public header file for CCLibraries projects
  Date: Jun  5, 2020

  Abstract

	This header file contains  definitions to be used by all  the packages in the
	CCLibraries  project.  This  header files  defines varidic  macros for  names
	generation related to common data structures APIs.

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

#ifndef CCLANGUAGE_STRUCTS_H
#define CCLANGUAGE_STRUCTS_H 1

#ifdef __cplusplus
extern "C" {
#endif


/** --------------------------------------------------------------------
 ** Automatically generated names API: data structs.
 ** ----------------------------------------------------------------- */

/* Whether it appears to make sense or not, let's always implement 4 variants of each
   "well  known" macro  name: without  VAR, with  single VAR,  with double  VAR, with
   triple VAR. */

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "make()". */
#define cclib_make_1(STRUCT)				STRUCT ## __make
#define cclib_make_2(STRUCT, VAR)			STRUCT ## __make__ ## VAR
#define cclib_make_3(STRUCT, VAR1, VAR2)		STRUCT ## __make__ ## VAR1 ## _ ## VAR2
#define cclib_make_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __make__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_make(...)					CCLIB_VNAME(cclib_make, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "unmake()". */
#define cclib_unmake_1(STRUCT)				STRUCT ## __unmake
#define cclib_unmake_2(STRUCT, VAR)			STRUCT ## __unmake__ ## VAR
#define cclib_unmake_3(STRUCT, VAR1, VAR2)		STRUCT ## __unmake__ ## VAR1 ## _ ## VAR2
#define cclib_unmake_4(STRUCT, VAR1, VAR2, VAR3)	STRUCT ## __unmake__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_unmake(...)				CCLIB_VNAME(cclib_unmake, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "new()". */
#define cclib_new_1(STRUCT)				STRUCT ## __new
#define cclib_new_2(STRUCT, VAR)			STRUCT ## __new__ ## VAR
#define cclib_new_3(STRUCT, VAR1, VAR2)			STRUCT ## __new__ ## VAR1 ## _ ## VAR2
#define cclib_new_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __new__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_new(...)					CCLIB_VNAME(cclib_new, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "delete()". */
#define cclib_delete_1(STRUCT)				STRUCT ## __delete
#define cclib_delete_2(STRUCT, VAR)			STRUCT ## __delete__ ## VAR
#define cclib_delete_3(STRUCT, VAR1, VAR2)		STRUCT ## __delete__ ## VAR1 ## _ ## VAR2
#define cclib_delete_4(STRUCT, VAR1, VAR2, VAR3)	STRUCT ## __delete__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_delete(...)				CCLIB_VNAME(cclib_delete, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "init()". */
#define cclib_init_1(STRUCT)				STRUCT ## __init
#define cclib_init_2(STRUCT, VAR)			STRUCT ## __init__ ## VAR
#define cclib_init_3(STRUCT, VAR1, VAR2)		STRUCT ## __init__ ## VAR1 ## _ ## VAR2
#define cclib_init_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __init__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_init(...)					CCLIB_VNAME(cclib_init, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "final()". */
#define cclib_final_1(STRUCT)				STRUCT ## __final
#define cclib_final_2(STRUCT, VAR)			STRUCT ## __final__ ## VAR
#define cclib_final_3(STRUCT, VAR1, VAR2)		STRUCT ## __final__ ## VAR1 ## _ ## VAR2
#define cclib_final_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __final__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_final(...)				CCLIB_VNAME(cclib_final, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "alloc()". */
#define cclib_alloc_1(STRUCT)				STRUCT ## __alloc
#define cclib_alloc_2(STRUCT, VAR)			STRUCT ## __alloc__ ## VAR
#define cclib_alloc_3(STRUCT, VAR1, VAR2)		STRUCT ## __alloc__ ## VAR1 ## _ ## VAR2
#define cclib_alloc_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __alloc__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_alloc(...)				CCLIB_VNAME(cclib_alloc, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the API function "release()". */
#define cclib_release_1(STRUCT)				STRUCT ## __release
#define cclib_release_2(STRUCT, VAR)			STRUCT ## __release__ ## VAR
#define cclib_release_3(STRUCT, VAR1, VAR2)		STRUCT ## __release__ ## VAR1 ## _ ## VAR2
#define cclib_release_4(STRUCT, VAR1, VAR2, VAR3)	STRUCT ## __release__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_release(...)				CCLIB_VNAME(cclib_release, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into a function name. */
#define cclib_fun_1(STRUCT)				STRUCT ## __fun
#define cclib_fun_2(STRUCT, VAR)			STRUCT ## __fun__ ## VAR
#define cclib_fun_3(STRUCT, VAR1, VAR2)			STRUCT ## __fun__ ## VAR1 ## _ ## VAR2
#define cclib_fun_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __fun__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_fun(...)					CCLIB_VNAME(cclib_fun, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into a function name to be used for the type predicates. */
#define cclib_is_1(STRUCT)				STRUCT ## __is
#define cclib_is_2(STRUCT, VAR)				STRUCT ## __is__ ## VAR
#define cclib_is_3(STRUCT, VAR1, VAR2)			STRUCT ## __is__ ## VAR1 ## _ ## VAR2
#define cclib_is_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __is__ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_is(...)					CCLIB_VNAME(cclib_is, __VA_ARGS__)


/** --------------------------------------------------------------------
 ** Automatically generated names API: methods table.
 ** ----------------------------------------------------------------- */

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the struct's methods table type. */
#define cclib_methods_table_type_1(STRUCT)			STRUCT ## __methods_table_t
#define cclib_methods_table_type_2(STRUCT, VAR)			STRUCT ## __methods_table_t__ ## VAR
#define cclib_methods_table_type_3(STRUCT, VAR1, VAR2)		STRUCT ## __methods_table_t__ ## VAR1 ## _ ## VAR2
#define cclib_methods_table_type_4(STRUCT, VAR1, VAR2, VAR3)	STRUCT ## __methods_table_t__ ## VAR1 ## _ ## VAR2 ## __ ## VAR3
#define cclib_methods_table_type(...)				CCLIB_VNAME(cclib_methods_table_type, __VA_ARGS__)
#define cclib_methods_table_t(...)				CCLIB_VNAME(cclib_methods_table_type, __VA_ARGS__)

/* Given a struct type name STRUCT  and an optional variant specification VAR: expand
   into the name of the struct's methods table. */
#define cclib_methods_table_1(STRUCT)				STRUCT ## __methods_table
#define cclib_methods_table_2(STRUCT, VAR)			STRUCT ## __methods_table__ ## VAR
#define cclib_methods_table_3(STRUCT, VAR1, VAR2)		STRUCT ## __methods_table__ ## VAR1 ## _ ## VAR2
#define cclib_methods_table_4(STRUCT, VAR1, VAR2, VAR3)		STRUCT ## __methods_table__ ## VAR1 ## _ ## VAR2 ## __ ## VAR3
#define cclib_methods_table(...)				CCLIB_VNAME(cclib_methods_table, __VA_ARGS__)

/* Given the  struct type name  STRUCT, the method  name METHOD, an  optional variant
   specification  VAR: expand  into  the type  name  of that  variant  of the  method
   function for the struct type. */
#define cclib_method_type_2(STRUCT, METHOD)			STRUCT ## __method_t__ ## METHOD
#define cclib_method_type_3(STRUCT, METHOD, VAR)		STRUCT ## __method_t__ ## METHOD ## __ ## VAR
#define cclib_method_type_4(STRUCT, METHOD, VAR1, VAR2)		STRUCT ## __method_t__ ## METHOD ## __ ## VAR1 ## _ ## VAR2
#define cclib_method_type_5(STRUCT, METHOD, VAR1, VAR2, VAR3)	STRUCT ## __method_t__ ## METHOD ## __ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_method_type(...)					CCLIB_VNAME(cclib_method_type, __VA_ARGS__)
#define cclib_method_t(...)					CCLIB_VNAME(cclib_method_type, __VA_ARGS__)

/* Given  a struct  type  name STRUCT,  a  method name  METHOD,  an optional  variant
   specification VAR: expand into the name of the method for that type. */
#define cclib_method_2(STRUCT, METHOD)				STRUCT ## __method__ ## METHOD
#define cclib_method_3(STRUCT, METHOD, VAR)			STRUCT ## __method__ ## METHOD ## __ ## VAR
#define cclib_method_4(STRUCT, METHOD, VAR1, VAR2)		STRUCT ## __method__ ## METHOD ## __ ## VAR1 ## _ ## VAR2
#define cclib_method_5(STRUCT, METHOD, VAR1, VAR2, VAR3)	STRUCT ## __method__ ## METHOD ## __ ## VAR1 ## _ ## VAR2 ## _ ## VAR3
#define cclib_method(...)					CCLIB_VNAME(cclib_method, __VA_ARGS__)


/** --------------------------------------------------------------------
 ** Automatically generated definitions API: data structure with descriptor.
 ** ----------------------------------------------------------------- */

/* Given a data  structure name STRUCT, which  is meant to be a  "struct with descr":
   expand into the type name of its descriptor field. */
#define cclib_struct_descriptor_type(STRUCT)			cclib_struct_descriptor_ ## STRUCT ## _descr_t
#define cclib_struct_descriptor_t(STRUCT)			cclib_struct_descriptor_ ## STRUCT ## _descr_t

/* Define everything needed to declare a "struct with descriptor":
 *
 * - The struct typedef.
 * - The typedef of the methods table.
 * - The typedef of the descriptor struct.
 * - The descriptor struct definition.
 *
 * We can define a "struct with descr" as follows:
 *
 *   CCLIB_DEFINE_STRUCT_WITH_DESCRIPTOR(my_complex_t);
 *
 *   struct my_complex_t {
 *     cclib_struct_descriptor(my_complex_t);
 *     double  re;
 *     double  im;
 *   };
 */
#undef  CCLIB_DEFINE_STRUCT_WITH_DESCRIPTOR
#define CCLIB_DEFINE_STRUCT_WITH_DESCRIPTOR(STRUCT)					\
  CCLIB_STRUCT_TYPEDEF(cclib_methods_table_type(STRUCT));				\
											\
  CCLIB_STRUCT_TYPEDEF(cclib_struct_descriptor_type(STRUCT));				\
											\
  struct cclib_struct_descriptor_type(STRUCT) {						\
    cclib_methods_table_type(STRUCT) const	*cclib_table_of_methods_pointer;	\
  }

/* Given the  name of a data  structure STRUCT, which is  meant to be a  "struct with
   descr": expand into the descriptor struct field declaration. */
#define cclib_struct_descriptor(STRUCT)		cclib_struct_descriptor_type(STRUCT) cclib_struct_descr

/* Given a pointer do data structure PTR, which is meant to be a "struct with descr":
   return a pointer to its methods table usable as both lvalue and rvalue. */
#define cclib_struct_descriptor_ref_methods_table_pointer(PTR)	\
  ((PTR)->cclib_struct_descr.cclib_table_of_methods_pointer)

/* Given a pointer do data structure PTR, which is meant to be a "struct with descr":
   set its pointer to methods table to METHODS_TABLE_POINTER. */
#define cclib_struct_descriptor_set_methods_table_pointer(PTR, METHODS_TABLE_POINTER)	\
  (cclib_struct_descriptor_ref_methods_table_pointer(PTR) = (METHODS_TABLE_POINTER))

/* Given a struct type  name STRUCT, a method name METHOD:  expand into an expression
   evaluating to a pointer to the method implementation. */
#define cclib_method_pointer(PTR, METHOD)	(cclib_struct_descriptor_ref_methods_table_pointer(PTR)->METHOD)

/* Given the name of a variable PTR holding  a data structure pointer and the name of
   a method METHOD: expand into an expression evaluating to the pointer to the method
   implementation in the table of methods, usable to call the method. */
#define cclib_call_worker(METHOD, PTR, ...)	cclib_method_pointer(PTR, METHOD)
#define cclib_call(METHOD, ...)			(cclib_call_worker(METHOD, __VA_ARGS__, CCLIB_DUMMY)(__VA_ARGS__))

/* Given the name of a variable VAR holding a data structure and the name of a method
   METHD:  expand  into  an  expression  evaluating to  the  pointer  to  the  method
   implementation in the table of methods, usable to call the method itself. */
#define cclib_vcall_worker(METHOD, VAR, ...)	cclib_method_pointer(&(VAR), METHOD)
#define cclib_vcall(METHOD, ...)		(cclib_vcall_worker(METHOD, __VA_ARGS__, CCLIB_DUMMY)(__VA_ARGS__))


/** --------------------------------------------------------------------
 ** Helper macros: trait values.
 ** ----------------------------------------------------------------- */

#undef  CCLIB_DEFINE_TRAIT
#define CCLIB_DEFINE_TRAIT(TRAIT)										\
  CCLIB_DEFINE_STRUCT_WITH_DESCRIPTOR(TRAIT);									\
  CCLIB_STRUCT_TYPEDEF(TRAIT);											\
														\
  struct TRAIT {												\
    cclib_struct_descriptor(TRAIT);										\
    cclib_resource_data_t const *self;										\
  };														\
														\
  CCLIB_FUNC_ATTRIBUTE_UNUSED											\
  CCLIB_FUNC_ATTRIBUTE_ALWAYS_INLINE										\
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1,2)										\
    static inline TRAIT												\
    cclib_make(TRAIT) (cclib_resource_data_t const * self, cclib_methods_table_type(TRAIT) const * methods)	\
  {														\
    TRAIT	impl = { .self = self };									\
														\
    cclib_struct_descriptor_set_methods_table_pointer(&impl, methods);						\
    return impl;												\
  }														\
														\
  /* We want the use of  this macro to be followed by a semicolon.   So we put this				\
     harmless declaration at the end. */									\
  struct TRAIT

#define cclib_trait_resource_pointer(TRAIT)		((TRAIT).self)


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* defined CCLANGUAGE_STRUCTS_H */

/* end of file */
