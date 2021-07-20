#include "t3vwm.h"

extern Display *display;
extern int default_screen;

extern XSetWindowAttributes attr;
extern unsigned long value_mask;

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

	spawn("/usr/bin/feh -F /home/johannes/Pictures/tree.jpg");

	Window w2 = XCreateWindow
	(
		display,
		RootWindow(display, default_screen),
		100, 100,
		1366, 768,
		0,
		CopyFromParent,
		InputOutput,
		CopyFromParent,
		value_mask,
		&attr
	);

	XMapWindow(display,w2);
	int x_ret=XFillRectangle(display, w2, DefaultGC(display, default_screen), 100, 100, 400, 400);
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
	XSelectInput(display, w2, KeyPressMask);

  	//execute another program
	//wait
	while(1)//for(int i=0; i<2; i++)
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