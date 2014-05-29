AC_PREREQ([2.69])
AC_INIT([stdoutisatty], 1.0)
AC_CONFIG_SRCDIR([stdoutisatty.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

AM_INIT_AUTOMAKE
LT_INIT

# Checks for libraries.
# FIXME: Replace `main' with a function in `-ldl':
AC_CHECK_LIB([dl], [main])

# Checks for header files.
AC_CHECK_HEADERS([locale.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([setenv setlocale])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
