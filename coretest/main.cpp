#include "coretest.hpp"
using std::vector;
int main()
{
	std::cout << clearScreen();
	// get the default device
	auto device = boost::compute::system::devices();
	std::string input;
	std::regex rgx("[0-9]");
	std::smatch output;
	int dSwitch = 0;
	if (device.size() >= 1)
	{
		while(true)
		{
			std::cout << clearScreen();
			std::cout << "Multiple devices detected.\n";
			std::cout << "Please select a device.\n" ;
			for (unsigned i = 0; i < device.size();++i)
			{
				std::cout<< i << '-'<< device[i].name()<<'\n';
			}
			std::cin >> input;
			regex_match(input,output,rgx);
			if (output.size() > 0 && (unsigned)std::stoi(output[0]) < device.size())
			{
				dSwitch = std::stoi(output[0]);
				std::cout << clearScreen();
				break;
			}
		}
	}
	compute::context context(device[dSwitch]);
	compute::command_queue queue(context,device[dSwitch]);
	vector<vector<int>> v1;
	vector<int> v2;
	vector<std::thread> tVect;
	double size = 0.00;
	std::chrono::duration<double> elapsed_time;
	GPUDetails(device[dSwitch]);
	randThread(size,v1,v2,tVect,elapsed_time);
	copyTest(v2,elapsed_time,size, context,queue);
	randThread(v1,v2);
	mapTest(v2,context,queue);
	randTest(context,queue);
	//make new tests
}
