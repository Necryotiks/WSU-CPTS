#define BOOST_COMPUTE_USE_OFFLINE_CACHE 1
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <boost/compute/system.hpp>
#include <boost/compute/function.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/algorithm/sort.hpp>
#include <boost/compute/event.hpp>
#include <boost/compute/container/mapped_view.hpp>
#include <boost/compute/random/mersenne_twister_engine.hpp>
#include <boost/compute/random/uniform_int_distribution.hpp>
#include <future>
#include <regex>
#include <random>
#include <chrono>
static std::string clr = "\033[2J\033[;H";
using std::vector;
namespace compute = boost::compute;
int intRand(const int & min, const int & max);
void randfun(std::vector<int> &testVector, unsigned num_threads);
void do_join(std::thread& t);
void join_all(std::vector<std::thread>& v);
void randThread( double &size, vector<vector<int>> &v1,vector<int> &v2,vector<std::thread> &tVect,std::chrono::duration<double> &elapsed_seconds1);
void randThread(vector<vector<int>> &v1,vector<int> &v2);
void copyTest(vector<int> &v2,std::chrono::duration<double> &elapsed_seconds1 ,double &size, compute::context &context,compute::command_queue &queue);
void mapTest(vector<int> &v2,compute::context &context,compute::command_queue &queue);
void randTest(compute::context &context,compute::command_queue &queue);
void GPUDetails(boost::compute::device device);
