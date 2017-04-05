#include "Master.h"
#include "List.h"
#include <chrono>
#include "Menu.h"

void run_exe()
{
	Menu instance;
	instance.runapp();
}
string currentTime()
{


	auto t = system_clock::now();
	auto time = system_clock::to_time_t(t);
	return ctime(&time);
}