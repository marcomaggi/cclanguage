# CCLanguage

[![Build Status](https://travis-ci.org/marcomaggi/cclanguage.svg?branch=master)](https://travis-ci.org/marcomaggi/cclanguage)

## Introduction

This  package  installs a  C11  language  library that  implements  some
adaptations and extensions to the language.

The package targets  POSIX systems.  The package uses  the GNU Autotools
and it is tested, using Travis  CI, on both Ubuntu GNU+Linux systems and
OS X systems.

## License

Copyright (c) 2020 Marco Maggi <mrc.mgg@gmail.com>

This program is free software: you  can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free  Software Foundation, either version  3 of the License,  or (at
your option) any later version.

This program  is distributed  in the  hope that it  will be  useful, but
WITHOUT   ANY   WARRANTY;  without   even   the   implied  warranty   of
MERCHANTABILITY  or  FITNESS FOR  A  PARTICULAR  PURPOSE.  See  the  GNU
General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

## Install

To install from a proper release tarball, do this:

```
$ cd cclanguage-0.1.0
$ mkdir build
$ cd build
$ ../configure
$ make
$ make check
$ make install
```

to inspect the available configuration options:

```
$ ../configure --help
```

The Makefile is designed to allow parallel builds, so we can do:

```
$ make -j4 all && make -j4 check
```

which,  on  a  4-core  CPU,   should  speed  up  building  and  checking
significantly.

The Makefile supports the DESTDIR  environment variable to install files
in a temporary location, example: to see what will happen:

```
$ make -n install DESTDIR=/tmp/cclanguage
```

to really do it:

```
$ make install DESTDIR=/tmp/cclanguage
```

After the  installation it is  possible to verify the  installed library
against the test suite with:

```
$ make installcheck
```

From a repository checkout or snapshot  (the ones from the GitHub site):
we must install the GNU Autotools  (GNU Automake, GNU Autoconf), then we
must first run the script "autogen.sh" from the top source directory, to
generate the needed files:

```
$ cd cclanguage
$ sh autogen.sh

```

notice  that  `autogen.sh`  will   run  the  programs  `autoreconf`  and
`libtoolize`; the  latter is  selected through the  environment variable
`LIBTOOLIZE`,  whose  value  can  be  customised;  for  example  to  run
`glibtoolize` rather than `libtoolize` we do:

```
$ LIBTOOLIZE=glibtoolize sh autogen.sh
```

After this  the procedure  is the same  as the one  for building  from a
proper release tarball, but we have to enable maintainer mode:

```
$ ../configure --enable-maintainer-mode [options]
$ make
$ make check
$ make install
```

## Usage

Read the documentation generated from  the Texinfo sources.  The package
installs the documentation  in Info format; we can  generate and install
documentation in HTML format by running:

```
$ make html
$ make install-html
```

Usage examples for this package, and all the packages in the CCLibraries
project, are available in the companion package CCLibraries Examples.

## Credits

The  stuff was  written by  Marco Maggi.   If this  package exists  it's
because of the great GNU software tools that he uses all the time.

The  file  `cclanguage-map-macro.h`  is  copyright  2012,  2020  William
Swanson and it is distributed at (last verified on Sep 10, 2020):

[https://github.com/swansontec/map-macro](https://github.com/swansontec/map-macro)

with only minor editing (added `CCLANG_` prefix).

## Bugs

Bug  and vulnerability  reports are  appreciated, all  the vulnerability
reports  are  public; register  them  using  the  Issue Tracker  at  the
project's GitHub  site.  For  contributions and  patches please  use the
Pull Requests feature at the project's GitHub site.

## Resources

The latest release of this package can be downloaded from:

[https://bitbucket.org/marcomaggi/cclanguage/downloads](https://bitbucket.org/marcomaggi/cclanguage/downloads)

development takes place at:

[http://github.com/marcomaggi/cclanguage/](http://github.com/marcomaggi/cclanguage/)

and as backup at:

[https://bitbucket.org/marcomaggi/cclanguage/](https://bitbucket.org/marcomaggi/cclanguage/)

the documentation is available online:

[http://marcomaggi.github.io/docs/cclanguage.html](http://marcomaggi.github.io/docs/cclanguage.html)

the GNU Project software can be found here:

[http://www.gnu.org/](http://www.gnu.org/)

the companion package CCLibraries Examples is available from:

[http://github.com/marcomaggi/cclibraries-examples/](http://github.com/marcomaggi/cclibraries-examples/)

## Badges and static analysis

### Travis CI

Travis CI is  a hosted, distributed continuous  integration service used
to build and test software projects  hosted at GitHub.  We can find this
project's dashboard at:

[https://travis-ci.org/marcomaggi/cclanguage](https://travis-ci.org/marcomaggi/cclanguage)

Usage of this  service is configured through the  file `.travis.yml` and
additional scripts are under the directory `meta/travis-ci`.

### Clang's Static Analyzer

The Clang Static Analyzer is a source code analysis tool that finds bugs
in C, C++, and Objective-C programs.  It is distributed along with Clang
and we can find it at:

[http://clang-analyzer.llvm.org/](http://clang-analyzer.llvm.org/)

Usage of this  service is implemented with make rules;  see the relevant
section in the file `Makefile.am`.

