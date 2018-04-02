#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <boost/compute/system.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/algorithm/sort.hpp>
#include <boost/compute/event.hpp>
#include <future>
#include <random>
#include <chrono>
void randfun(std::vector<int> &testVector, unsigned num_threads);
void threadTest();
