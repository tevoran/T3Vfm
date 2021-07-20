#include "t3vwm.h"

extern Display *display;
extern int default_screen;
extern XSetWindowAttributes attr;
extern unsigned long value_mask;

//returns T3V_okay if everything is fine
int init()
{
	printf("starting T3Vwm\n");
	printf("init X11...");

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

	printf("getting privileges...");
	attr.override_redirect=T3V_true;
	attr.event_mask=
		SubstructureRedirectMask |
		SubstructureNotifyMask |
		KeyReleaseMask | 
		PointerMotionMask;
	value_mask=
		CWEventMask |
		CWOverrideRedirect;
	int x_ret=XChangeWindowAttributes(
		display,
		RootWindow(
			display,
			default_screen),
		value_mask,
		&attr
		);
	switch(x_ret)
	{
		case BadAccess:
			printf("BadAccess\n");
			break;
		case BadColor:
			printf("BadColor\n");
			break;
		case BadMatch:
			printf("BadMatch\n");
			break;
		case BadCursor:
			printf("BadCursor\n");
			break;
		case BadPixmap:
			printf("BadPixmap\n");
			break;
		case BadValue:
			printf("BadValue\n");
			break;
		case BadWindow:
			printf("BadWindow\n");
			break;
		default:
			printf("done\n");
			break;
	}
	return T3V_okay;
}