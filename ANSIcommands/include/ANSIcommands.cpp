#include "ANSIcommands.hpp"
/*
 * =====================================================================================
 *
 *       Filename:  ANSIcommands.c
 *
 *    Description:  ANSI commands
 *
 *        Version:  1.0
 *        Created:  04/13/2018 22:43
 *       Revision:  none
 *       Compiler:  g++ 
 *
 *         Author:  ELLIOTT VILLARS (), eman13vil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
const char * clearScreen()
{
	const char * temp = "\033[2J\033[;H";
	return temp;

}
const char * resetScreen()
{
	const char * temp = "\033[0m";
	return temp;
}
const char * setTerminalColorBlack()
{
	const char * temp = "\033[30m";
	return temp;
}
const char * setTerminalColorBrightBlack()
{
	const char * temp = "\033[30;1m";
	return temp;

}
const char * setBackgroundColorBlack()
{

	const char * temp = "\033[40m";
	return temp;
}
const char * setBackgroundColorBrightBlack()
{

	const char * temp = "\033[40;1m";
	return temp;
}
const char * setTerminalColorRed()
{

	const char * temp = "\033[31m";
	return temp;
}
const char * setTerminalColorBrightRed()
{
	const char * temp = "\033[31;1m";
	return temp;

}
const char * setBackgroundColorRed()
{
	const char * temp = "\033[41m";
	return temp;

}
const char * setBackgroundColorBrightRed()
{

	const char * temp = "\033[41;1m";
	return temp;
}
const char * setTerminalColorGreen()
{
	const char * temp = "\033[32m";
	return temp;

}
const char * setTerminalColorBrightGreen()
{
	const char * temp = "\033[32;1m";
	return temp;

}
const char * setBackgroundColorGreen()
{
	const char * temp = "\033[42m";
	return temp;

}
const char * setBackgroundColorBrightGreen()
{

	const char * temp = "\033[42;1m";
	return temp;
}
const char * setTerminalColorYellow()
{
	const char * temp = "\033[33m";
	return temp;

}
const char * setTerminalColorBrightYellow()
{
	const char * temp = "\033[33;1m";
	return temp;

}
const char * setBackgroundColorYellow()
{
	const char * temp = "\033[43m";
	return temp;

}
const char * setBackgroundColorBrightYellow()
{

	const char * temp = "\033[43;1m";
	return temp;
}
const char * setTerminalColorBlue()
{
	const char * temp = "\033[34m";
	return temp;

}
const char * setTerminalColorBrightBlue()
{
	const char * temp = "\033[34;1m";
	return temp;

}
const char * setBackgroundColorBlue()
{
	const char * temp = "\033[44m";
	return temp;

}
const char * setBackgroundColorBrightBlue()
{

	const char * temp = "\033[44;1m";
	return temp;
}
const char * setTerminalColorMagenta()
{
	const char * temp = "\033[35m";
	return temp;

}
const char * setTerminalColorBrightMagenta()
{
	const char * temp = "\033[35;1m";
	return temp;

}
const char * setBackgroundColorMagenta()
{
	const char * temp = "\033[45m";
	return temp;

}
const char * setBackgroundColorBrightMagenta()
{

	const char * temp = "\033[45;1m";
	return temp;
}
const char * setTerminalColorCyan()
{
	const char * temp = "\033[36m";
	return temp;

}
const char * setTerminalColorBrightCyan()
{
	const char * temp = "\033[36;1m";
	return temp;

}
const char * setBackgroundColorCyan()
{
	const char * temp = "\033[46m";
	return temp;

}
const char * setBackgroundColorBrightCyan()
{

	const char * temp = "\033[46;1m";
	return temp;
}
const char * setTerminalColorWhite()
{
	const char * temp = "\033[37m";
	return temp;

}
const char * setTerminalColorBrightWhite()
{
	const char * temp = "\033[37;1m";
	return temp;

}
const char * setBackgroundColorWhite()
{
	const char * temp = "\033[47m";
	return temp;

}
const char * setBackgroundColorBrightWhite()
{

	const char * temp = "\033[47;1m";
	return temp;
}
