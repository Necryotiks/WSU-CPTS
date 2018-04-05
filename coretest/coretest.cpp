
#include "coretest.hpp"
namespace compute = boost::compute;
using std::cout;
int intRand(const int & min, const int & max) 
{
	static thread_local std::mt19937 generator; //seed with system time
	std::uniform_int_distribution<int> distribution(min,max); //maybe make static.
	return distribution(generator);
}
void randfun(std::vector <int> &testVector, unsigned num_threads) 
{
	unsigned i =0;
	for(i =0;i < (100000000/num_threads);i++)
	{	
		testVector.push_back(intRand(0,100000000)); //rand() is NOT thread safe.
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
void randThread( double &size, vector<vector<int>> &v1,vector<int> &v2,vector<std::thread> &tVect, std::chrono::duration<double> &elapsed_seconds1)
{
	unsigned num_threads = std::thread::hardware_concurrency();
	auto start1= std::chrono::system_clock::now();
	for (unsigned i =0; i < num_threads; ++i)
	{
		v1.push_back(vector<int>());	
	}
	for (unsigned i =0; i < num_threads; ++i)
	{
		tVect.push_back(std::thread(randfun, std::ref(v1[i]),num_threads));
	}
	join_all(tVect);
	for (unsigned i =0; i < num_threads; ++i)
	{
		size += v1[i].size();
		v2.insert(std::end(v2), std::begin(v1[i]), std::end(v1[i]));// use boost compute insert.
	}
	auto end1= std::chrono::system_clock::now();
	elapsed_seconds1 = end1-start1;
}
void randThread(vector<vector<int>> &v1,vector<int> &v2)
{
	unsigned num_threads = std::thread::hardware_concurrency();
	v2.clear();
	v2.push_back(0);
	for (unsigned i =0; i < num_threads; ++i)
	{
		v2.insert(std::end(v2), std::begin(v1[i]), std::end(v1[i]));// use boost compute insert.
	}
}
void copyTest(boost::compute::device &device,  vector<int> &v2,std::chrono::duration<double> &elapsed_seconds1 ,double &size)
{
	//generate an OpenCL context
	compute::context context(device);

	//create a command queue for the device
	compute::command_queue queue(context,device);
	//make a vector on the device
	compute::vector<int> device_vector(100000000, context);
	//print the device's name
	//transfer data from host to gpu
	auto start2= std::chrono::system_clock::now();
	compute::copy(	v2.begin(), v2.end(), device_vector.begin(), queue);
	auto end2= std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end2-start2;
	// sort data on the device
	auto start3= std::chrono::system_clock::now();
	compute::sort(device_vector.begin(), device_vector.end(), queue);
	auto end3= std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds3 = end3-start3;

	// copy data back to the host
	auto start4= std::chrono::system_clock::now();
	compute::copy(device_vector.begin(), device_vector.end(), v2.begin(), queue);
	auto end4= std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds4 = end4-start4;


	unsigned elementCount = size;
	size *=4;
	cout << "Vector Size: " << (size/(1024*1024*1024))<< "GiB" << '\n';
	cout << "Transfer Vector element count: " << (elementCount)<< '\n';
	cout << "Number generation time: " << elapsed_seconds1.count() <<  '\n';
	cout << "GPU transfer time: " << elapsed_seconds2.count() << '\n';
	cout << "GPU sort time: " << elapsed_seconds3.count() << '\n';//use gpu time
	cout << "GPU writeback time: " << elapsed_seconds4.count() << '\n';
}	
void mapTest(boost::compute::device &device, vector<int> &v2)
{
	//generate an OpenCL context
	compute::context context(device);
	//create a command queue for the device
	compute::command_queue queue(context,device);
	//make a vector on the device
	compute::vector<int> device_vector(100000000, context);
	//print the device's name

	int * mapbuf = &v2[0];//pointer to the start of the vector memory

	compute::mapped_view<int> view(mapbuf,100000000, context);//create memory mapped object.

	view.map(queue);//map object to host memory.

	auto start5= std::chrono::system_clock::now();

	compute::sort(view.begin(),view.end(),queue);

	auto end5= std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds5 = end5-start5;

	view.unmap(queue);//makes data available to host.


	cout << "Mapped sort time: " << elapsed_seconds5.count() << '\n';
}
void GPUDetails(boost::compute::device device)
{	
	cout << "Platform Profile: " << device.platform().profile() << '\n';
	cout << "Platform Version: " << device.platform().version() << '\n';
	cout << "Platform Name: " << device.platform().name() << '\n';
	cout << "Platform Vendor: " << device.platform().vendor() << '\n';
	cout << "Device: " << device.name() <<'\n'; 
	cout << "ID: " << device.id() <<'\n'; 
	cout << "Type: " << device.type() << '\n';
	cout << "Vendor: " << device.vendor() << '\n';
	cout << "Driver Version: " << device.driver_version() << '\n';
	cout << "Max Clock Frequency(MHz): " << device.clock_frequency() << '\n';
	cout << "Compute Units: " << device.compute_units() << '\n';
}
