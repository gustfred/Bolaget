// Bolaget.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <ctime>
#include <iostream>
#include <stdio.h>

int main()
{
  POINT p[100];
    COLORREF color, color_tmp;
    HDC hDC;
    BOOL b;
	int bottles, wines, counter, counter2, wait, dummy;
    
	printf("How many different kinds of wine (amount of clicks): ");
	scanf_s("%d", &wines);
	printf("How many bottles of each wine (loops?): ");
	scanf_s("%d", &bottles);
	printf("How sleep between clicks (ms): ");
	scanf_s("%d", &wait);

	for (counter=1;counter<=wines;counter++){
		printf("Put the mouse pointer in place and press '1' and ENTER: ");
		scanf_s("%d",&dummy);
		b = GetCursorPos(&p[counter-1]);
		if (!b)
			return 2;
	}

    // Get the device context for the screen
    hDC = GetDC(NULL);
    if (hDC == NULL)
        return 3;

//TEMP
/*	HANDLE hStdin; 
	DWORD cNumRead; 
	INPUT_RECORD irInBuf[1];
 
	if ( HANDLE(hStdin = GetStdHandle( STD_INPUT_HANDLE )) == INVALID_HANDLE_VALUE )
		return 1;
 
	while ( true )  { 
		if (! ReadConsoleInput( hStdin, irInBuf, 1, &cNumRead) )
			return 1;
 
		for (DWORD i = 0; i < cNumRead; ++i)
			if ( irInBuf[i].EventType == MOUSE_EVENT && irInBuf[i].Event.MouseEvent.dwEventFlags != MOUSE_MOVED ) {
				if ( irInBuf[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED ) {
					std::cout << "Left Click.\n";
				}
			}
	}*/
//TEMP


	color = GetPixel(hDC, p[0].x, p[0].y);
    color_tmp = color;
	while (color == color_tmp){
		color_tmp = GetPixel(hDC, p[0].x, p[0].y);
		system("cls");
		printf("%i %i %i", GetRValue(color_tmp), GetGValue(color_tmp), GetBValue(color_tmp));
	}

	// Release the device context again
    ReleaseDC(GetDesktopWindow(), hDC);

    printf("%i %i %i", GetRValue(color), GetGValue(color), GetBValue(color));
    //return 0;
   
	for (counter=1;counter<=bottles;counter++){
		//SetCursorPos(CURSOR_X,CURSOR_Y1);
		for (counter2=1;counter2<=wines;counter2++){
			SetCursorPos(p[counter2-1].x, p[counter2-1].y);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(wait);
		}
	}	
	
	return 0;
}
