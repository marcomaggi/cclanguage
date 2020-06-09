/*
  Part of: CCLanguage
  Contents: public header file for CCLibraries projects
  Date: Jun  5, 2020

  Abstract

	This header file contains  definitions to be used by all  the packages in the
	CCLibraries project.  This header file defines the variadic macros machinery.

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

#ifndef CCLANGUAGE_VARIADIC_MACROS_H
#define CCLANGUAGE_VARIADIC_MACROS_H 1

#ifdef __cplusplus
extern "C" {
#endif


/** --------------------------------------------------------------------
 ** Variadic macros mechanism.
 ** ----------------------------------------------------------------- */

/* The following  macros are adapted  from Stack Overflow  (URL last accessed  Jan 2,
 * 2019):
 *
 *   <https://stackoverflow.com/a/26408195>
 *
 * for a full explanation, see also (URL last accessed Apr  1, 2020):
 *
 *   <https://gustedt.wordpress.com/2010/06/03/default-arguments-for-c99/>
 *
 * NOTE I know that the project P99 by implements an extensino to this mechanism that
 * allows  using zero  optional  arguments in  the call  to  "CCLIB_VNAME()"; but  it
 * involves defining even more complex preprocessor macors, so I do not implement it.
 * Anyway, here is the project's link (URL last accessed Apr 1, 2020):
 *
 *   <https://p99.gforge.inria.fr/>
 *
 * (Marco Maggi; Apr  1, 2020)
 */

/* The macro use:
 *
 *   CCLIB_VNAME_PRIVATE_COUNT_ARGS(__VA_ARGS__)
 *
 * expands into the number of arguments in __VA_ARGS__.
 */
#define CCLIB_VNAME_PRIVATE_COUNT_ARGS(...)	\
  CCLIB_VNAME_PRIVATE_COUNT_ARGS_I(__VA_ARGS__,CCLIB_VNAME_PRIVATE_REVERSED_SEQUENCE)

/* This   is   a  worker   macro   that   just   merges   the  arguments   given   to
 * "CCLIB_VNAME_PRIVATE_COUNT_ARGS(...)" into a single "__VA_ARGS__".
 *
 *   CCLIB_VNAME_PRIVATE_COUNT_ARGS(alpha,beta,delta)
 *   ==> CCLIB_VNAME_PRIVATE_COUNT_ARGS_I(alpha,beta,delta,CCLIB_VNAME_PRIVATE_REVERSED_SEQUENCE())
 *   ==> CCLIB_VNAME_PRIVATE_ARG_N(alpha,beta,delta,63,62,...,1,0)
 */
#define CCLIB_VNAME_PRIVATE_COUNT_ARGS_I(...)	CCLIB_VNAME_PRIVATE_ARG_N(__VA_ARGS__)

/* This macro  accepts at least  64 arguments: from ARG_01  to ARG_63, plus  at least
 * one.   The  result of  the  expansion  equals the  number  of  arguments given  to
 * "CCLIB_VNAME_PRIVATE_COUNT_ARGS()".
 *
 *   CCLIB_VNAME_PRIVATE_COUNT_ARGS(alpha,beta,delta)
 *   ==> CCLIB_VNAME_PRIVATE_ARG_N(alpha,beta,delta,63,62,---,1,0)
 *   ==> 3
 *
 * In the macro use:
 *
 *   CCLIB_VNAME_PRIVATE_ARG_N(alpha,beta,delta,63,62,---,1,0)
 *
 * the arguments are bound as follows:
 *
 *   ARG_01 = alpha
 *   ARG_02 = beta
 *   ARG_03 = delta
 *   ARG_04 = 63
 *   ARG_05 = 62
 *   ---
 *   ARG_63 = 4
 *   N      = 3
 *   __VA_ARGS__ = 2,1,0
 */
#define CCLIB_VNAME_PRIVATE_ARG_N(ARG_01, ARG_02, ARG_03, ARG_04, ARG_05, ARG_06, ARG_07, ARG_08, ARG_09, ARG_10,	\
				  ARG_11, ARG_12, ARG_13, ARG_14, ARG_15, ARG_16, ARG_17, ARG_18, ARG_19, ARG_20,	\
				  ARG_21, ARG_22, ARG_23, ARG_24, ARG_25, ARG_26, ARG_27, ARG_28, ARG_29, ARG_30,	\
				  ARG_31, ARG_32, ARG_33, ARG_34, ARG_35, ARG_36, ARG_37, ARG_38, ARG_39, ARG_40,	\
				  ARG_41, ARG_42, ARG_43, ARG_44, ARG_45, ARG_46, ARG_47, ARG_48, ARG_49, ARG_50,	\
				  ARG_51, ARG_52, ARG_53, ARG_54, ARG_55, ARG_56, ARG_57, ARG_58, ARG_59, ARG_60,	\
				  ARG_61, ARG_62, ARG_63, N, ...)		N

/* This macro just expands into the reversed integers sequence:
 *
 *   63,62,...,1,0
 */
#define CCLIB_VNAME_PRIVATE_REVERSED_SEQUENCE		    \
  63,62,61,60,						    \
    59,58,57,56,55,54,53,52,51,50,			    \
    49,48,47,46,45,44,43,42,41,40,			    \
    39,38,37,36,35,34,33,32,31,30,			    \
    29,28,27,26,25,24,23,22,21,20,			    \
    19,18,17,16,15,14,13,12,11,10,			    \
    9,8,7,6,5,4,3,2,1,0

/* This macro builds the output name.
 *
 *   CCLIB_VNAME_PRIVATE_COMPOSE_NAME(my_new, 2)
 *   ==> my_new_2
 */
#define CCLIB_VNAME_PRIVATE_COMPOSE_NAME(NAME, N)	NAME ## _ ## N

/* This is an intermediate step that makes sure that:
 *
 *   CCLIB_VNAME_PRIVATE_COUNT_ARGS(__VA_ARGS__)
 *
 * in the expansion of "CCLIB_VNAME()"  is itself expanded before the stringification
 * performed by "##".
 */
#define CCLIB_VNAME_PRIVATE__VNAME(NAME, N)	CCLIB_VNAME_PRIVATE_COMPOSE_NAME(NAME, N)

/* The macro uses:
 *
 *    CCLIB_VNAME(cce_new, alpha)
 *    CCLIB_VNAME(cce_new, alpha, beta)
 *
 * respectively expand into:
 *
 *    cce_new_1(alpha)
 *    cce_new_2(alpha, beta)
 */
#define CCLIB_VNAME(FUNC, ...)		\
  CCLIB_VNAME_PRIVATE__VNAME(FUNC, CCLIB_VNAME_PRIVATE_COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* defined CCLANGUAGE_VARIADIC_MACROS_H */

/* end of file */
