Make programs think their stdout is a tty / terminal.

Build & Install
---------------
::

$ ./autogen.sh
$ ./configure
$ make
$ sudo make install

Usage
-----
Just prefix your command with ``stdoutisatty``::

$ stdoutisatty ls --color=auto | less

Links
-----
* `A blog article (Chinese) <http://lilydjwg.is-programmer.com/2013/7/9/pretend-that-stdout-is-a-tty.39922.html>`_
