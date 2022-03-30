#pragma once
#ifndef osparts
#if !defined(_WIN32) && ((defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))))
#define linux 0x00
#define ostype "unix"
#else
#ifdef _WIN32
#define windows 0x00
#define ostype "windows"
#else
#error OS not Supported!
#endif
#endif
#define osparts 0x0
#endif
