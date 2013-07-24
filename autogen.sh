#!/bin/sh

aclocal 
autoconf
libtoolize
automake --add-missing --foreign

