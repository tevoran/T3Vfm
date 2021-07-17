#include "t3vwm.h"

#include <unistd.h>
#include <string.h>

extern Display *display;
extern int default_screen;

void main()
{
	//initialization of X
	Window window;
	XEvent event;

	char *msg="HALLO2";

	if(init()!=T3V_okay)
	{
		return;
	}

	Window w = XCreateSimpleWindow(
		display, 
		RootWindow(
			display, 
			default_screen),
		100,100,
		1366,768,
		1, BlackPixel(display, default_screen),
		WhitePixel(display, default_screen));

	Window w2 = XCreateSimpleWindow(
		display, 
		w,
		100,100,
		1366,768,
		1, BlackPixel(display, default_screen),
		BlackPixel(display, default_screen));

	XMapWindow(display,w);
	int x_ret=XFillRectangle(display, w, DefaultGC(display, default_screen), 100, 100, 400, 400);
	switch(x_ret)
	{
		case BadDrawable:
			printf("TEST: BadDrawable\n");
			break;
		case BadGC:
			printf("TEST: BadGC\n");
			break;
		case BadMatch:
			printf("TEST: BadMatch\n");
			break;
		default:
			printf("TEST: okay\n");
			break;
	}
	XSelectInput(display, w, KeyPressMask);

  	//execute another program
  		//execlp("/usr/bin/feh", "feh", "-F", "/home/johannes/Pictures/tree.jpg", NULL);
	//wait
	for(int i=0; i<2; i++)
	{
		if(event.type==KeyPress)
		{
			break;
		}
		XNextEvent(display, &event);
	}



	//cleaning up
	printf("ending connection to X...");
	XCloseDisplay(display);
	printf("done\n");

	printf("ending T3Vwm\n");
	return;
}