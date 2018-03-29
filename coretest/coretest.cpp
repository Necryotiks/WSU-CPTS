
#include "coretest.hpp"
namespace compute = boost::compute;
using std::vector;
using std::cout;
static std::string clr = "\033[2J\033[;H";
int randfun(std::vector <int> &testVector) 
{
 auto i =0;
 for(i =0;i < 1000000000;i++)
 {	
	 testVector.push_back(rand()%1000000000);
 }
}
void threadTest()
{
	unsigned num_threads = std::thread::hardware_concurrency();
	vector<int> v1;
//	randfun(v1);
	cout << "This is a GPU core load test." << '\n';
	cout << clr ;
	srand(time(NULL));
	// get the default device
	compute::device device = compute::system::default_device();
	for(const auto &device : boost::compute::system::devices()){
		std::cout << device.name() << std::endl;
	}

	//print the device's name
	std::cout << "Device: " << device.name() <<'\n'; 
	std::cout << "ID: " << device.id() <<'\n'; 
	std::cout << "Type: " << device.type() << '\n';
	std::cout << "Vendor: " << device.vendor() << '\n';
	std::cout << "Version: " << device.version() << '\n';
	std::cout << "Driver Version: " << device.driver_version() << '\n';
	std::cout << "Clock Frequency(Hz): " << device.clock_frequency() << '\n';
	std::cout << "Compute Units: " << device.compute_units() << '\n';
}
