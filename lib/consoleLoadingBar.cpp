#include "consoleLoadingBar.h"
#include "osdef.h"
#define WIN32_LEAN_AND_MEAN
#if !defined(linux)&&defined(windows)
#include <windows.h>
#elif defined(linux)&&!defined(windows)
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
typedef short SHORT;
#else
#error Not Supported OS!
#endif
#include <iostream>
#include <memory>
#include <cstring>

CloadingBarConsole::CloadingBarConsole() :pcent(0)
{
	pcent = (int*)std::malloc(sizeof(int));
	memset(pcent, 0, sizeof(int));
#if !defined(linux)&&defined(windows)
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#else
#endif
	return;
}
#if !defined(linux) && defined(windows)
#define colorA(cc) (cc==colorcode::OK ? (BACKGROUND_GREEN) : \
	cc == colorcode::SUSPEND ? (BACKGROUND_RED | BACKGROUND_GREEN) : BACKGROUND_RED)
#else
#endif

void CloadingBarConsole::render()
{
#if !defined(linux)&&defined(windows)
	CONSOLE_SCREEN_BUFFER_INFO i;
	ZeroMemory(&i, sizeof(i));
#else
	short err = -1;
#ifdef TIOCGSIZE
	struct ttysize ts;
	err = ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
#define Xsize ts.ts_cols
#elif defined(TIOCGWINSZ)
	struct winsize ts;
	err = ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
#define Xsize ts.ws_col
#else
#error NO SUPPORTED LINUX
#define Xsize 1
#endif
#endif
	double xt = static_cast<double>(*pcent) / 100.0;
	SHORT xs = 100;

	if (
#if !defined(linux) && defined(windows)
		GetConsoleScreenBufferInfo(hConsole, &i) != 0
#else
		err != -1
#endif
		) {
#define apx 3
#if !defined(linux) && defined(windows)
#define Xsize i.dwSize.X
#endif
		xt *= Xsize - apx;
		xs = (Xsize - 1) - apx;
#undef apx
		if (
#if !defined(linux) && defined(windows)
			i.dwCursorPosition.X > 0
#else
			1
#endif
			)
			std::cout << "\r" << std::flush;
	}
	else {
		xt *= 100;
		std::cout << "\r" << std::flush;
	}


	for (int c = 0; c <= xs; c++) {
#if !defined(linux)&&defined(windows)
		SetConsoleTextAttribute(hConsole, colorA(cc) | (c >= xt ? 0 : BACKGROUND_INTENSITY));
#else
		printf("\033[97;%im", (cc == colorcode::OK ? 42 :
			(cc == colorcode::SUSPEND ? 43 : 41)) + (c >= xt ? 0 : 60));
#endif
		std::cout << " ";
	}
	this->resetColor();
}

void CloadingBarConsole::setPercent(int percent)
{
	*pcent = percent;
}

CloadingBarConsole::~CloadingBarConsole()
{
	std::free(pcent);
}

void CloadingBarConsole::setColorCode(colorcode cc)
{
	this->cc = cc;
}

void CloadingBarConsole::resetColor()
{
#if !defined(linux)&&defined(windows)
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
#else
	printf("\033[0m");
#endif
}
