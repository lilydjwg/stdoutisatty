#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>

static int (*orig_isatty)(int) = 0;

int isatty(int fd){
  if(fd == 1){
    return 1;
  }
  return orig_isatty(fd);
}

void die(char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
  fprintf(stderr, "\n");
  fflush(stderr);
  exit(-1);
}

__attribute__ ((constructor)) static void setup(void) {
  void *libhdl;
  char *dlerr;

  if (!(libhdl=dlopen("libc.so.6", RTLD_LAZY)))
    die("Failed to patch library calls: %s", dlerror());

  orig_isatty = dlsym(libhdl, "isatty");
  if ((dlerr=dlerror()) != NULL)
    die("Failed to patch isatty() library call: %s", dlerr);
}
