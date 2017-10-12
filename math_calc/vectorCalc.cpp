#include "functions.cpp"
#include "vectorCalc.h"

vectorCalc::vectorCalc(void)
{
}
vectorCalc::~vectorCalc(void)
{
}
void vectorCalc::dotProduct(void)
{
    vector<string> inputVector1;
    vector<string> inputVector2;
    double output = 0.0000;
    string size;
    size_t xsize = 0;
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
            xsize = stoi(size);
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
    for (size_t h = 0; h < xsize; h++)
    {
        string temp1;
        string temp2;
        str1 >> temp1;
        inputVector1.push_back(temp1);
        str2 >> temp2;
        inputVector2.push_back(temp2);
    }
    for (size_t i = 0; i < xsize; i++)
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
        //throw exception
        cout << textReset;
        getchar();
        return;
    }
    size_t size = IV1.size();
    stringstream str1(IV1);
    stringstream str2(IV2);
    for (size_t h = 0; h < size; h++)
    {
        string temp1;
        string temp2;
        str1 >> temp1;
        inputVector1.push_back(temp1);
        str2 >> temp2;
        inputVector2.push_back(temp2);
    }
    for (size_t i = 0; i < size; i++)
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
    vector<double> outputVector;
    size_t xsize = 3;
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
    for (size_t h = 0; h < xsize; h++)
    {
        string temp1;
        string temp2;
        str1 >> temp1;
        inputVector1.push_back(temp1);
        str2 >> temp2;
        inputVector2.push_back(temp2);
    }
    double x_nought = (atof(inputVector1[1].c_str()) * atof(inputVector2[2].c_str()) - atof(inputVector1[2].c_str()) * atof(inputVector2[1].c_str()));
    double y_nought = -(atof(inputVector1[0].c_str()) * atof(inputVector2[2].c_str()) - atof(inputVector1[2].c_str()) * atof(inputVector2[0].c_str()));
    double z_nought = (atof(inputVector1[0].c_str()) * atof(inputVector2[1].c_str()) - atof(inputVector1[1].c_str()) * atof(inputVector2[0].c_str()));

    outputVector.push_back(x_nought);
    outputVector.push_back(y_nought);
    outputVector.push_back(z_nought);

    cout << "Cross Product: ";
    for (size_t b = 0; b < outputVector.size(); b++)
    {
        cout << outputVector[b] << " ";
    }
    getchar();
}
void vectorCalc::matrixReduce(void) //taken from stack overflow also broke af
{
    // double arrayA[3][3] =
    //     {
    //         {1.00, 2.00, 3.00},
    //         {4.00, 5.00, 6.00},
    //         {7.00, 8.00, 9.00}};
    // int nrows = std::extent<decltype(arrayA), 0>::value; // number of rows
    // int ncols = std::extent<decltype(arrayA), 1>::value; // number of columns

    // int pivot = 0; // the determines the column we are at which holds the diagonal,
    // // the basis for all elimination above and below

    // while (pivot < nrows)
    // {

    //     for (int row = 0; row < nrows; row++)
    //     {
    //         for (int col = 0; col < ncols; col++)
    //         {
    //             if (arrayA[pivot][pivot] != 1 && arrayA[pivot][pivot] != 0)
    //             {
    //                 arrayA[row][col] = arrayA[row][col] / arrayA[pivot][pivot];
    //             }
    //         }
    //     }

    //     pivot++;
    // }
    // for (auto i = 0; i < nrows; i++)
    // {
    //     cout << '[';
    //     for (auto j = 0; j < ncols; j++)
    //     {
    //         cout << arrayA[i][j] << " ";
    //     }
    //     cout << ']';
    //     cout << '\n';
    // }
    // getchar();
}
void vectorCalc::initializeVectorCalculator(void)
{
    std::string input;
    std::smatch output;
    std::regex rgx_str("[0-9]");
    while (true)
    {
        cout << clearScreen; //ANSI Clear screen BS.
        cout << "\033[31;1H";
        cout << "Press R to return to main menu." << '\n';
        cout << "\033[1;1H";
        cout << "1. Dot Product" << '\n';
        cout << "2. Cross Product" << '\n';
        cout << "3. Matrix reduction" << '\n';
        cout << "Please enter a selection" << '\n';
        getline(cin >> std::ws, input);
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
            case 3:
                this->matrixReduce();
                break;
            }
        }
    }
}