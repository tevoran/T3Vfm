#include "t3vwm.h"

extern Display *display;
extern int default_screen;

//returns T3V_okay if everything is fine
int init()
{
	printf("starting T3Vwm\n");
	printf("init...\n");
	/*if(XInitThreads()!=0)
	{
		printf("NO MULTITHREADING\nerror\n");
		return 1;
	}*/

	display = XOpenDisplay(NULL);
	if(display!=NULL)
	{
		printf("done\n");
	}
	else
	{
		printf("error\n");
		return 1;
	}

	default_screen=DefaultScreen(display);

	return T3V_okay;
}