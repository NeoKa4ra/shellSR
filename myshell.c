#include "myshell.h"

// fonctions externes
void eval(char*cmdline, jobsT *jobs);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

int main()
{
  char cmdline[MAXLINE];                 // ligne de commande
  jobsT jobsTab = initJobs();
    
  while (1)
    {                            // boucle d'interpretation
      printf("<my_shell> ");             // message d'invite
      Fgets(cmdline, MAXLINE, stdin);    // lire commande
      if (feof(stdin))                   // fin (control-D)
	exit(0);
      eval(cmdline, &jobsTab);                     // interpreter commande
  }
}
