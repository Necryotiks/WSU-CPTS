#ifndef ANSICOMMANDS_H
#define ANSICOMMANDS_H
/*
 * =====================================================================================
 *
 *       Filename:  ANSIcommands.hpp
 *
 *    Description:  ANSI command header.
 *
 *        Version:  1.0
 *        Created:  04/14/2018 12:37
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  ELLIOTT VILLARS (), eman13vil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
//For future reference, when making a static library, make sure all header declarations are marked 
//as extern in order to be used in outside projects
extern const char * clearScreen();
extern const char * resetScreen();
extern const char * setTerminalColorBlack();
extern const char * setTerminalColorBrightBlack();
extern const char * setBackgroundColorBlack();
extern const char * setBackgroundColorBrightBlack();
extern const char * setTerminalColorRed();
extern const char * setTerminalColorBrightRed();
extern const char * setBackgroundColorRed();
extern const char * setBackgroundColorBrightRed();
extern const char * setTerminalColorGreen();
extern const char * setTerminalColorBrightGreen();
extern const char * setBackgroundColorGreen();
extern const char * setBackgroundColorBrightGreen();
extern const char * setTerminalColorYellow();
extern const char * setTerminalColorBrightYellow();
extern const char * setBackgroundColorYellow();
extern const char * setBackgroundColorBrightYellow();
extern const char * setTerminalColorBlue();
extern const char * setTerminalColorBrightBlue();
extern const char * setBackgroundColorBlue();
extern const char * setBackgroundColorBrightBlue();
extern const char * setTerminalColorMagenta();
extern const char * setTerminalColorBrightMagenta();
extern const char * setBackgroundColorMagenta();
extern const char * setBackgroundColorBrightMagenta();
extern const char * setTerminalColorCyan();
extern const char * setTerminalColorBrightCyan();
extern const char * setBackgroundColorCyan();
extern const char * setBackgroundColorBrightCyan();
extern const char * setTerminalColorWhite();
extern const char * setTerminalColorBrightWhite();
extern const char * setBackgroundColorWhite();
extern const char * setBackgroundColorBrightWhite();
#endif
