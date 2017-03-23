#include "Header.h"

void printVector(string label, vector<double>& vect)
{
	cout << label << " ";
	for (auto i = 0; i < vect.size(); ++i) {
		cout << vect[i] << " ";
	}

	cout << endl;
}
