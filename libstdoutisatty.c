#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include<dlfcn.h>

static int (*orig_isatty)(int) = 0;
static char* env = NULL;
static int env_len = 0;

static bool should_fake(int fd){
  if(fd != 1 && fd != 2)
    return false;

  if(env_len >= 2){
    return env[fd-1] == 'y';
  }else if(fd == 1){
    return true;
  }
  return false;
}

int isatty(int fd){
  if(should_fake(fd)){
    return 1;
  }
  return orig_isatty(fd);
}

__attribute__ ((constructor)) static void setup(void) {
  void *libhdl;

  orig_isatty = dlsym(RTLD_NEXT, "isatty");

  env = getenv("ISATTY");
  if(env)
    env_len = strlen(env);
}
