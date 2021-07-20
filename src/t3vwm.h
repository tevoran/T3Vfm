#ifndef T3VFM
#define T3VFM

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define T3V_true 1


#define T3V_okay 0

int init();
int spawn(const char *cmd);

#endif