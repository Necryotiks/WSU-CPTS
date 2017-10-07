#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <regex>

//template later
using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stringstream;
using std::skipws;

const static string clearScreen = "\033[2J\033[1;1H";
const static string underLine = "\033[4m"; //m is for SGR in ANSI
const static string textReset = "\033[0m";
const static string strikeThrough = "\033[9m";
const static string textBold = "\033[1m";
const static string textItalics = "\033[3m";
const static string setColorBlack = "\033[30m";
const static string setColorRed = "\033[31m";
const static string setColorBrightAssRed = "\033[31;1m";
const static string setColorGreen = "\033[32m";
const static string setColorYellow = "\033[33m";
const static string setColorBlue = "\033[34m";
const static string setColorMagenta = "\033[35m";
const static string setColorCyan = "\033[36m";
const static string setColorWhite = "\033[37m";