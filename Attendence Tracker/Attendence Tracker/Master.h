#pragma once
#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>
#include <cassert>
#include <regex>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <ctime>
#include <chrono>



using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::chrono::system_clock;

void run_exe();
string currentTime();