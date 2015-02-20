#include "fctutil.h"

void refusedSignal(){
	sigset_t p_ens;
	sigfillset(&p_ens);
	sigprocmask(SIG_SETMASK, &p_ens, NULL);
}

void autorisedSignal(){
	sigset_t p_ens;
	sigemptyset(&p_ens);
	sigprocmask(SIG_SETMASK, &p_ens, NULL);
}



int allStopped(jobsT *jb)
{
  int i;
  int result = 1;
  for(i = 0; i < taille; i++)
    {
      if (jb->jobs[i].etat != ST)
	{
	  result = 0;
	  break;
	}
    }
  return result;
}
