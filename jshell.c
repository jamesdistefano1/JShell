// jshell

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  char buf[5000]; /* from apue.h */
  pid_t pid;
  int status;
  printf("[jshell]> "); /* print prompt (printf requires %% to print %) */
  while (fgets(buf, 5000, stdin) != NULL) {
    if (strlen(buf) > 1){
		    buf[strlen(buf) - 1] = '\0';
	  }
    if (strcmp(buf, "pwd") == 0){
      printf("built in pwd \n");

    }
    //else if (){
      // other built ins
    //}
    int pid;
    pid = fork();
    if (pid < 0) {
      perror("fork");
    }
    else if (pid == 0) { /* child */
      execlp(buf, buf, (char *)0);
      exit(127);
    }
    /* parent */
    if ((pid = waitpid(pid, &status, 0)) < 0){
      perror("waitpid");
    }
    printf("[jshell]> ");
  }
  exit(0);
}
