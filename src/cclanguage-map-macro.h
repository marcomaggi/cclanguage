/*
 * Abstract
 *
 *	This file comes from the distribution at (last verified on Sep 10, 2020):
 *
 *		<https://github.com/swansontec/map-macro>
 *
 *	with only minor editing (added CCLANG_ prefix).
 *
 * Copyright (C) 2012, 2020 William Swanson
 *
 * Permission is hereby  granted, free of charge,  to any person obtaining  a copy of
 * this software and associated documentation files  (the "Software"), to deal in the
 * Software  without restriction,  including without  limitation the  rights to  use,
 * copy, modify,  merge, publish, distribute,  sublicense, and/or sell copies  of the
 * Software,  and to  permit persons  to whom  the Software  is furnished  to do  so,
 * subject to the following conditions:
 *
 * The above  copyright notice and  this permission notice  shall be included  in all
 * copies or substantial portions of the Software.
 *
 * THE  SOFTWARE IS  PROVIDED  "AS IS",  WITHOUT  WARRANTY OF  ANY  KIND, EXPRESS  OR
 * IMPLIED, INCLUDING BUT  NOT LIMITED TO THE WARRANTIES  OF MERCHANTABILITY, FITNESS
 * FOR A  PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO  EVENT SHALL THE  AUTHORS BE
 * LIABLE  FOR  ANY CLAIM,  DAMAGES  OR  OTHER LIABILITY,  WHETHER  IN  AN ACTION  OF
 * CONTRACT,  TORT OR  OTHERWISE, ARISING  FROM,  OUT OF  OR IN  CONNECTION WITH  THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the names of the authors or their institutions
 * shall not be  used in advertising or  otherwise to promote the sale,  use or other
 * dealings in this Software without prior written authorization from the authors.
 */

#if 0 /* Usage examples. */

/* Basic `MAP` usage: */
#define STRING(x) char const *x##_string = #x;
CCLANG_MAP(STRING, foo, bar, baz)

/* Basic `MAP_LIST` usage: */
#define PARAM(x) int x
void function(CCLANG_MAP_LIST(PARAM, foo, bar, baz));

/* Test `MAP` with parentheses in the arguments: */
#define CALL(x) putchar x;
CCLANG_MAP(CALL, ('a'), ('b'), ('c'))

/* Test `MAP_LIST` with parentheses in the arguments: */
#define CALL_LIST(x) putchar x
CCLANG_MAP_LIST(CALL_LIST, ('a'), ('b'), ('c'));

#endif

#ifndef CCLANGUAGE_MAP_MACRO_H
#define CCLANGUAGE_MAP_MACRO_H

#define CCLANG_EVAL0(...) __VA_ARGS__
#define CCLANG_EVAL1(...) CCLANG_EVAL0(CCLANG_EVAL0(CCLANG_EVAL0(__VA_ARGS__)))
#define CCLANG_EVAL2(...) CCLANG_EVAL1(CCLANG_EVAL1(CCLANG_EVAL1(__VA_ARGS__)))
#define CCLANG_EVAL3(...) CCLANG_EVAL2(CCLANG_EVAL2(CCLANG_EVAL2(__VA_ARGS__)))
#define CCLANG_EVAL4(...) CCLANG_EVAL3(CCLANG_EVAL3(CCLANG_EVAL3(__VA_ARGS__)))
#define CCLANG_EVAL(...)  CCLANG_EVAL4(CCLANG_EVAL4(CCLANG_EVAL4(__VA_ARGS__)))

#define CCLANG_MAP_END(...)
#define CCLANG_MAP_OUT
#define CCLANG_MAP_COMMA ,

#define CCLANG_MAP_GET_END2() 0, CCLANG_MAP_END
#define CCLANG_MAP_GET_END1(...) CCLANG_MAP_GET_END2
#define CCLANG_MAP_GET_END(...) CCLANG_MAP_GET_END1
#define CCLANG_MAP_NEXT0(test, next, ...) next CCLANG_MAP_OUT
#define CCLANG_MAP_NEXT1(test, next) CCLANG_MAP_NEXT0(test, next, 0)
#define CCLANG_MAP_NEXT(test, next)  CCLANG_MAP_NEXT1(CCLANG_MAP_GET_END test, next)

#define CCLANG_MAP0(f, x, peek, ...) f(x) CCLANG_MAP_NEXT(peek, MAP1)(f, peek, __VA_ARGS__)
#define CCLANG_MAP1(f, x, peek, ...) f(x) CCLANG_MAP_NEXT(peek, MAP0)(f, peek, __VA_ARGS__)

#define CCLANG_MAP_LIST_NEXT1(test, next) CCLANG_MAP_NEXT0(test, CCLANG_MAP_COMMA next, 0)
#define CCLANG_MAP_LIST_NEXT(test, next)  CCLANG_MAP_LIST_NEXT1(CCLANG_MAP_GET_END test, next)

#define CCLANG_MAP_LIST0(f, x, peek, ...) f(x) CCLANG_MAP_LIST_NEXT(peek, MAP_LIST1)(f, peek, __VA_ARGS__)
#define CCLANG_MAP_LIST1(f, x, peek, ...) f(x) CCLANG_MAP_LIST_NEXT(peek, MAP_LIST0)(f, peek, __VA_ARGS__)

/**
 * Applies the function macro `f` to each of the remaining parameters.
 */
#define CCLANG_MAP(f, ...) CCLANG_EVAL(CCLANG_MAP1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

/**
 * Applies the function macro `f` to each of the remaining parameters and
 * inserts commas between the results.
 */
#define CCLANG_MAP_LIST(f, ...) CCLANG_EVAL(CCLANG_MAP_LIST1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

#endif /* defined CCLANGUAGE_MAP_MACRO_H */

/* end of file */
