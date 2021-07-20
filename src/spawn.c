#include "t3vwm.h"

int spawn(const char *cmd)
{
	if(fork()==0) //if this is the child process
	{
		printf("T3Vwm executes: %s\n", cmd);
  		system(cmd);
  		exit(0);
	}
	return T3V_okay;
}