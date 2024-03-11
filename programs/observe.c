#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <strerror.h>
#include <sys/wait.h>
#include <io/ansi_colors.h>



int main(int argc, char *argv[])
{
  if (argc < 2) {
      printf("Usage: %s <command> \n", argv[0]);
      return 1;
  }

  const unsigned short num_args = argc - 1;
  char *cmd_args[num_args];
  for (int i = 1; i < argc; i++) {
    cmd_args[i-1] = argv[i];
  }
  cmd_args[num_args] = NULL;

  while (1) {
    int status;
    pid_t cpid = fork();
    char *name = argv[1];
    if (cpid == 0) {
      if (execvp(name , cmd_args) == -1) {
        perror("execvp");
        exit(1);
      }
    }

    waitpid(cpid, &status, 0);
    if (WIFSIGNALED(status)) {
      printf(FG_RED "\nExit status %d, killed by signal %d\n" FG_RESET, WEXITSTATUS(status), WTERMSIG(status));
    } else if (WIFSTOPPED(status)) {
      printf(FG_YELLOW "\nExit status %d, stopped by signal %d\n" FG_RESET, WEXITSTATUS(status), WSTOPSIG(status));
    }

    sleep(2);
  }
}