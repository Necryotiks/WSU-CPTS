#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	cout << "Object Constructed" << endl;
	std::fstream Dietfile;
	std::fstream Exercisefile;
	Dietfile.open("Diet_File.txt", std::ios::in | std::ios::out);
	Exercisefile.open("Exercise_File.txt", std::ios::in | std::ios::out);
	cout << "Files opened" << endl;
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "Object Deconstructed" << endl;
}
