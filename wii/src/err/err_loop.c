/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** main
*/

#include "headers.h"

GXRModeObj *rmode = NULL;

void error_display(char *fmt, ...)
{
    va_list ap;
    va_list cpy;

    va_start(ap, fmt);

    VIDEO_SetNextFramebuffer(_demo->buf.xfb);

    printf("\x1b[%d;%dH", 2, 0);

    printf("\x1b[30m");
    printf("\x1b[47m");
    printf("\nError.\n");

    printf("\x1b[40m");
    printf("\x1b[37m");
    va_copy(cpy, ap);
    vprintf(fmt, cpy);
    while (1) {
		WPAD_ScanPads();

		// WPAD_ButtonsDown tells us which buttons were pressed in this loop
		// this is a "one shot" state which will not fire again until the button has been released
		u32 pressed = WPAD_ButtonsDown(0);

		// We return to the launcher application via exit
		if ( pressed & WPAD_BUTTON_HOME ) exit(0);
		
		VIDEO_WaitVSync();
    }
}
