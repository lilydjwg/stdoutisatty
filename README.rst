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

Use a two-character environment variable ``ISATTY`` to specify whether you want stdout and/or stderr to be treated as a tty::

``ISATTY`` value  which isatty
``yy``  stdout, stderr
``y.``  stdout
``.y``  stderr

``.`` indicates any characer other than (lower-cased) ``y``. Only the first two characters are examined (currently).

Links
-----
* `A blog article (Chinese) <http://lilydjwg.is-programmer.com/2013/7/9/pretend-that-stdout-is-a-tty.39922.html>`_
