#include "t3vfm.h"

void main()
{
	printf("starting T3Vfm\n");

	//initialization of X
	Display *display;
	Window window;
	XEvent event;

	printf("init X...");
	display = XOpenDisplay(NULL);
	if(display!=NULL)
	{
		printf("done\n");
	}
	else
	{
		printf("error\n");
		return;
	}


	//cleaning up
	printf("ending connection to X...");
	XCloseDisplay(display);
	printf("done\n");

	printf("ending T3Vfm\n");
	return;
}