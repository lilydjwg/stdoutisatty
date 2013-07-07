#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
 
#define PRELOAD_LEN 2048
#ifndef LIB_FILE
# define LIB_FILE "libstdoutisatty.so"
#endif

int main(int argc, char **argv){
  int n = 0;
  char *preload = NULL;
  char *preload_env;
  char *old_preload = getenv("LD_PRELOAD");

  if(argc == 1){
    fprintf(stderr, "usage: stdoutisatty command [args]\n");
    return 1;
  }
  setlocale(LC_ALL, "");

  preload_env = malloc(PRELOAD_LEN);
  if(!preload){
    strcpy(preload_env, LIB_FILE);
  }else{
    strcat(preload_env, preload);
  }
  if(old_preload){
    n = strlen(preload_env);
    preload_env[n] = ':';
    preload_env[n+1] = '\0';
    strcat(preload_env, old_preload);
  }
  setenv("LD_PRELOAD", preload_env, 1);
  free(preload_env);
  execvp(argv[1], argv + 1);

  perror("execve");
  return 2;
}