
#include "coretest.hpp"
namespace compute = boost::compute;
using std::vector;
using std::cout;
static std::string clr = "\033[2J\033[;H";
int intRand(const int & min, const int & max) 
{
	static thread_local std::mt19937 generator;
	std::uniform_int_distribution<int> distribution(min,max);
	return distribution(generator);
}
void randfun(std::vector <int> &testVector, unsigned num_threads) 
{
	//int x = intRand(1,100000);
	auto i =0;
	for(i =0;i < 100000000;i++)
	{	
		testVector.push_back(i); //rand() is NOT thread safe.
	}
}
void do_join(std::thread& t)
{
	t.join();
}

void join_all(std::vector<std::thread>& v)
{
	std::for_each(v.begin(),v.end(),do_join);
}
void threadTest()
{
	unsigned num_threads = std::thread::hardware_concurrency();
	cout << clr ;
	vector<vector<int>> v1;
	vector<std::thread> tVect;
	for(auto i =0; i < num_threads; ++i)
	{
		v1.push_back(vector<int>());	
	}
	for (auto i =0; i < num_threads; i++)
	{
		tVect.push_back(std::thread(randfun, std::ref(v1[i]),num_threads));
	}
	join_all(tVect);
	cout << "This is a GPU core load test." << '\n';
	srand(time(NULL));
	// get the default device
	compute::device device = compute::system::default_device();


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
