#include "t3vwm.h"

extern Display *display;
extern int default_screen;

//returns T3V_okay if everything is fine
int init()
{
	printf("starting T3Vwm\n");
	printf("init...");

	display = XOpenDisplay(NULL); //use default display
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
	printf("using screen %i\n", default_screen);

	return T3V_okay;
}