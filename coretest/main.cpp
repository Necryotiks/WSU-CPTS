#include "coretest.hpp"
using std::vector;
int main()
{
	std::cout << clr;
	// get the default device
	boost::compute::device device = boost::compute::system::default_device();
	vector<vector<int>> v1;
	vector<int> v2;
	vector<std::thread> tVect;
	double size = 0.00;
	std::chrono::duration<double> elapsed_time;
	GPUDetails(device);
	randThread(size,v1,v2,tVect,elapsed_time);
	copyTest(device,v2,elapsed_time,size);
	randThread(v1,v2);
	mapTest(device,v2);
	//make new tests
}
