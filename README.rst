Make programs think their stdout is a tty / terminal.

Build & Install
---------------
::

$ mkdir -p build && cd build
$ cmake ..
$ make
$ sudo make install
$ sudo ldconfig

Usage
-----
Just prefix your command with ``stdoutisatty``::

$ stdoutisatty ls --color=auto | less

Use a two-character environment variable ``ISATTY`` to specify whether you want stdout and/or stderr to be treated as a tty:

.. list-table::
   :header-rows: 1

   * - ``ISATTY`` value
     - which isatty
   * - ``yy``
     - stdout, stderr
   * - ``y.``
     - stdout
   * - ``.y``
     - stderr

``.`` indicates any characer other than (lower-cased) ``y``. Only the first two characters are examined (currently).

Links
-----
* `A blog article (Chinese) <https://blog.lilydjwg.me/2013/7/9/pretend-that-stdout-is-a-tty.39922.html>`_
