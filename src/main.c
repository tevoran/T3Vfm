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


	//test window
	window=XCreateSimpleWindow(display, RootWindow(display, default_screen), 10, 10, 800, 800, 1, BlackPixel(display, default_screen), WhitePixel(display, default_screen));
	XMapWindow(display, window);
  	XSelectInput(display, window, ExposureMask | KeyPressMask);
  	XFlush(display);

  	//execute another program
  		execlp("/usr/bin/feh", "feh", "-F", "/home/johannes/Pictures/tree.jpg", NULL);
	//wait
	for(int i=0; i<3; i++)
	{
		if(event.type==Expose)
		{
			XMapWindow(display, window);
			XDrawString(
				display,
				window,
				XDefaultGC(
					display,
					default_screen),
				50,
				50,
				msg,
				strlen(msg));
		}
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