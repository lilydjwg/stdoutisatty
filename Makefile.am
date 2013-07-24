lib_LTLIBRARIES=libstdoutisatty.la
libstdoutisatty_la_SOURCES=libstdoutisatty.c
libstdoutisatty_la_LDFLAGS=-export-dynamic -avoid-version

bin_PROGRAMS=stdoutisatty
stdoutisatty_SOURCES=stdoutisatty.c
AM_CFLAGS=-DLIBDIR=\"${libdir}\"
stdoutisatty_LDADD=libstdoutisatty.la
stdoutisatty_LDFLAGS=-ldl

