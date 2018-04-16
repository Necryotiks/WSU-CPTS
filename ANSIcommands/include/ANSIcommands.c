#include "ANSIcommands.h"
/*
 * =====================================================================================
 *
 *       Filename:  ANSIcommands.h
 *
 *    Description:  ANSI commands
 *
 *        Version:  1.0
 *        Created:  04/13/2018 22:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ELLIOTT VILLARS (), eman13vil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

 const char * clearScreen()
{
	char * temp = "\033[2J\033[;H";
	return temp;

}
 const char * resetScreen()
{
	char * temp = "\033[0m";
	return temp;
}
 const char * setTerminalColorBlack()
{
	char * temp = "\033[30m";
	return temp;
}
 const char * setTerminalColorBrightBlack()
{
	char * temp = "\033[30;1m";
	return temp;

}
 const char * setBackgroundColorBlack()
{

	char * temp = "\033[40m";
	return temp;
}
 const char * setBackgroundColorBrightBlack()
{

	char * temp = "\033[40;1m";
	return temp;
}
 const char * setTerminalColorRed()
{

	char * temp = "\033[31m";
	return temp;
}
 const char * setTerminalColorBrightRed()
{
	char * temp = "\033[31;1m";
	return temp;

}
 const char * setBackgroundColorRed()
{
	char * temp = "\033[41m";
	return temp;

}
 const char * setBackgroundColorBrightRed()
{

	char * temp = "\033[41;1m";
	return temp;
}
 const char * setTerminalColorGreen()
{
	char * temp = "\033[32m";
	return temp;

}
 const char * setTerminalColorBrightGreen()
{
	char * temp = "\033[32;1m";
	return temp;

}
 const char * setBackgroundColorGreen()
{
	char * temp = "\033[42m";
	return temp;

}
 const char * setBackgroundColorBrightGreen()
{

	char * temp = "\033[42;1m";
	return temp;
}
 const char * setTerminalColorYellow()
{
	char * temp = "\033[33m";
	return temp;

}
 const char * setTerminalColorBrightYellow()
{
	char * temp = "\033[33;1m";
	return temp;

}
 const char * setBackgroundColorYellow()
{
	char * temp = "\033[43m";
	return temp;

}
 const char * setBackgroundColorBrightYellow()
{

	char * temp = "\033[43;1m";
	return temp;
}
 const char * setTerminalColorBlue()
{
	char * temp = "\033[34m";
	return temp;

}
 const char * setTerminalColorBrightBlue()
{
	char * temp = "\033[34;1m";
	return temp;

}
 const char * setBackgroundColorBlue()
{
	char * temp = "\033[44m";
	return temp;

}
 const char * setBackgroundColorBrightBlue()
{

	char * temp = "\033[44;1m";
	return temp;
}
 const char * setTerminalColorMagenta()
{
	char * temp = "\033[35m";
	return temp;

}
 const char * setTerminalColorBrightMagenta()
{
	char * temp = "\033[35;1m";
	return temp;

}
 const char * setBackgroundColorMagenta()
{
	char * temp = "\033[45m";
	return temp;

}
 const char * setBackgroundColorBrightMagenta()
{

	char * temp = "\033[45;1m";
	return temp;
}
 const char * setTerminalColorCyan()
{
	char * temp = "\033[36m";
	return temp;

}
 const char * setTerminalColorBrightCyan()
{
	char * temp = "\033[36;1m";
	return temp;

}
 const char * setBackgroundColorCyan()
{
	char * temp = "\033[46m";
	return temp;

}
 const char * setBackgroundColorBrightCyan()
{

	char * temp = "\033[46;1m";
	return temp;
}
 const char * setTerminalColorWhite()
{
	char * temp = "\033[37m";
	return temp;

}
 const char * setTerminalColorBrightWhite()
{
	char * temp = "\033[37;1m";
	return temp;

}
 const char * setBackgroundColorWhite()
{
	char * temp = "\033[47m";
	return temp;

}
 const char * setBackgroundColorBrightWhite()
{

	char * temp = "\033[47;1m";
	return temp;
}
