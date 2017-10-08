#include "functions.cpp"
#include "vectorCalc.h"

void matrixMultiplication(void)
{
    int matrixA[1][3]={0};
    int matrixB[3][1]={0};
    int matrixC[(std::extent<int(matrixA), 1>::value][(std::extent<int(matrixB), 0>::value]
    auto 
    
    if(std::extent<int(matrixA), 0>::value == std::extent<int(matrixB), 1>::value)
    {
        for(auto i = 0; i < std::extent<int(matrixA), 0>::value; i++)
        {
            
        }
    }
}
void vectorCalc::dotProduct(void)
{
    vector<string> inputVector1;
    vector<string> inputVector2;
    double output = 0.0000;
    string size;
    string v1input;
    string v2input;
    std::smatch check;
    std::regex regex_str("[A-Za-z]"); //going to be used to check if user didnt enter a number.
    while (true)
    {
        cout << "\033[2J\033[1;1H"; //ANSI Clear screen bs. first clear screen then reset cursor position.\033-cursor,[-cmd,2J-arguments
        cout << "Enter vector size: ";
        getline(cin, size);
        regex_match(size, check, regex_str);
        if (check.empty())
        {
            break;
        }
    }
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "Enter vector 1(seperate different values with a space): ";
        getline(cin >> std::ws, v1input);
        regex_search(v1input, check, regex_str);
        if (check.empty())
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter vector 2(seperate different values with a space): ";
        getline(cin >> std::ws, v2input);
        regex_search(v2input, check, regex_str);
        if (check.empty())
        {
            break;
        }
    }
    stringstream str1(v1input);
    stringstream str2(v2input);
    for (auto h = 0; h < stoi(size); h++)
    {
        string temp1;
        string temp2;
        str1 >> temp1;
        inputVector1.push_back(temp1);
        str2 >> temp2;
        inputVector2.push_back(temp2);
    }
    for (auto i = 0; i < stoi(size); i++)
    {
        output += atof(inputVector1[i].c_str()) * atof(inputVector2[i].c_str());
    }
    cout << clearScreen;
    cout << "Dot Product value: " << output << '\n';
    if (output == 0.00)
    {
        cout << "Vectors are orthogonal!" << '\n';
    }
    else
    {
        cout << "Vectors are ";
        cout << textBold;
        cout << "NOT ";
        cout << textReset;
        cout << "orthogonal!" << '\n';
    }
    getchar();
}
void vectorCalc::dotProduct(string IV1, string IV2)
{
    vector<string> inputVector1;
    vector<string> inputVector2;
    double output = 0.0000;
    if (IV1.size() != IV2.size())
    {
        cout << setColorBrightAssRed;
        cout << "Invalid vector dimensions!" << '\n';
        cout << textReset;
        getchar();
        return;
    }
    auto size = IV1.size();
    stringstream str1(IV1);
    stringstream str2(IV2);
    for (auto h = 0; h < size; h++)
    {
        string temp1;
        string temp2;
        str1 >> temp1;
        inputVector1.push_back(temp1);
        str2 >> temp2;
        inputVector2.push_back(temp2);
    }
    for (auto i = 0; i < size; i++)
    {
        output += atof(inputVector1[i].c_str()) * atof(inputVector2[i].c_str());
    }
    cout << "Dot Product value: " << output;
    getchar();
}
void vectorCalc::crossProduct()
{
    vector<string> inputVector1;
    vector<string> inputVector2;
    vector<int> outputVector;
    string size = "3";
    string v1input;
    string v2input;
    std::smatch check;
    std::regex regex_str("[A-Za-z]"); //going to be used to check if user didnt enter a number.
    while (true)
    {
        cout << "\033[2J\033[1;1H"; //clear screen
        cout << "Enter vector 1(seperate different values with a space): ";
        getline(cin >> std::ws, v1input);
        regex_search(v1input, check, regex_str);
        if (check.empty())
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter vector 2(seperate different values with a space): ";
        getline(cin >> std::ws, v2input);
        regex_search(v2input, check, regex_str);
        if (check.empty())
        {
            break;
        }
    }
    stringstream str1(v1input);
    stringstream str2(v2input);
    for (auto h = 0; h < stoi(size); h++)
    {
        string temp1;
        string temp2;
        str1 >> temp1;
        inputVector1.push_back(temp1);
        str2 >> temp2;
        inputVector2.push_back(temp2);
    }
    auto x_nought = (atof(inputVector1[1].c_str()) * atof(inputVector2[2].c_str()) - atof(inputVector1[2].c_str()) * atof(inputVector2[1].c_str()));
    auto y_nought = -(atof(inputVector1[0].c_str()) * atof(inputVector2[2].c_str()) - atof(inputVector1[2].c_str()) * atof(inputVector2[0].c_str()));
    auto z_nought = (atof(inputVector1[0].c_str()) * atof(inputVector2[1].c_str()) - atof(inputVector1[1].c_str()) * atof(inputVector2[0].c_str()));

    outputVector.push_back(x_nought);
    outputVector.push_back(y_nought);
    outputVector.push_back(z_nought);

    cout << "Cross Product: ";
    for (auto b = 0; b < outputVector.size(); b++)
    {
        cout << outputVector[b] << " ";
    }
    getchar();
}
void vectorCalc::initializeVectorCalculator(void)
{
    std::string input;
    std::smatch output;
    regex rgx_str("[0-9]");
    while (true)
    {
        cout << clearScreen; //ANSI Clear screen BS.
        cout << "\033[31;1H";
        cout << "Press R to return to main menu." << '\n';
        cout << "\033[1;1H";
        cout << "1. Dot Product" << '\n';
        cout << "2. Cross Product" << '\n';
        cout << "Please enter a selection" << '\n';
        getline(cin >> ws, input);
        if (input == "R" || input == "r")
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
            case 1:
                this->dotProduct();
                break;
            case 2:
                this->crossProduct();
                break;
            }
        }
    }
}
