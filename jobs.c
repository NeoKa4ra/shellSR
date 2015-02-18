#include "jobs.h"

jobT initJob(pid_t pid, state etat, char *cmd)
{
  jobT jb;
  jb.pid = pid;
  jb.etat = etat;
  strcpy(jb.cmd, cmd);
  return jb;    
}

jobsT initJobs()
{
	jobsT jb;
	jb.taille = 0;
	jb.indiceFG = -1;
	return jb;
}
//renvoi l'indice qui correspond au pid donée ou -1 si le pid n'existe pas
int searchIndWithPid(pid_t pid, jobsT *jobs)
{
  int indice = 0;
  while(indice < jobs->taille && jobs->jobs[indice].pid != pid)
    indice++;
  if(jobs->jobs[indice].pid == pid)
    return indice;
  else
    return -1;
}


void delJobPid(pid_t pid, jobsT *jobs){
  int ind = searchIndWithPid(pid, jobs);
  if (ind == -1)
    {
      printf("pas de processus ayant ce pid");
    }
  else
    delJobInd(ind,jobs);
}

void delJobInd(int i, jobsT *jobs){
  if(i > jobs->taille)
    printf("cette indice est supèrieur aux nombres de processus actuelle");
  else if(i < 0)
    printf("cette indice est infèrieur a 0");
  else
    {
      int j;
      for(j = i + 1; j < jobs->taille; j++)
	{
	  jobs->jobs[j-1] = jobs->jobs[j];
	}
     jobs->taille--;
    }
  
    
}

void addJob(jobT job, jobsT *jobs){
  if(job.etat == FG)
    jobs->indiceFG = jobs->taille;
  jobs->jobs[jobs->taille] = job;
  jobs->taille++;
}

void printJob(jobsT jobs){
	int i;
	for (i=0;i<jobs.taille;i++){
	  printf("[%d]\t",i);
	  if(jobs.jobs[i].etat == ST)
	    printf("Stopped\t%s", jobs.jobs[i].cmd);
	  else
	    printf("Running\t%s",  jobs.jobs[i].cmd);
	}
}
