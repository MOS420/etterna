#ifndef STEPMANIA_H
#define STEPMANIA_H
/*
-----------------------------------------------------------------------------
 File: StepMania.h

 Desc: Objects accessable from anywhere in the program.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/

int SMmain(int argc, char* argv[]);
void ApplyGraphicOptions();
void ExitGame();
void ResetGame( bool ReturnToFirstScreen=true );
void ReadGamePrefsFromDisk();
void SaveGamePrefsToDisk();

#if defined(WIN32)
extern HWND g_hWndMain;
#endif

extern CString DirOfExecutable;

extern int g_argc;
extern char **g_argv;

#endif
