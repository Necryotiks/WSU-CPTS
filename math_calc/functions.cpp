#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <regex>
#include <type_traits>

//template later
using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stringstream;
using std::skipws;

const string clearScreen = "\033[2J\033[1;1H";
const string underLine = "\033[4m"; //m is for SGR in ANSI
const string textReset = "\033[0m";
const string strikeThrough = "\033[9m";
const string textBold = "\033[1m";
const string textItalics = "\033[3m";
const string setColorBlack = "\033[30m";
const string setColorRed = "\033[31m";
const string setColorBrightAssRed = "\033[31;1m";
const string setColorGreen = "\033[32m";
const string setColorYellow = "\033[33m";
const string setColorBlue = "\033[34m";
const string setColorMagenta = "\033[35m";
const string setColorCyan = "\033[36m";
const string setColorWhite = "\033[37m";
