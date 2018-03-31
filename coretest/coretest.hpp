#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <boost/compute/core.hpp>
#include <future>
#include <random>
void randfun(std::vector<int> &testVector, unsigned num_threads);
void threadTest();
