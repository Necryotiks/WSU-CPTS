#include <iostream>
#include <regex>
#include <string>
#include "functions.cpp"
#include "vectorCalc.h"

using namespace std;

int main(int argc, const char *argv[])
{
    
    
    std::string input;
    std::smatch output;
    vectorCalc vectorCalculator;
    regex rgx_str("[0-9]");
    while (true)
    {
        cout << clearScreen; //ANSI Clear screen BS.
        cout << "\033[31;1H";
        cout << "Press Q to quit" << '\n';
        cout << "\033[1;1H";
        cout << "1. Vector Calculator" << '\n';
        //cout << "2. Cross Product" << '\n';
        cout << "Please enter a selection" << '\n';
        getline(cin >> ws, input);
        if (input == "Q" || input == "q")
        {
            break;
        }
        else
        {
            regex_match(input, output, rgx_str);
            if (output[0] == '0')
            {
                break;
            }
            switch (stoi(output[0]))
            {
            case 1: vectorCalculator.initializeVectorCalculator();
                break;
            case 2:
                break;
            }
        }
    }
}