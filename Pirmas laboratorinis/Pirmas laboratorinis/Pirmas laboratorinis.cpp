#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

/// <summary>
/// Binary number class
/// </summary>
struct binaryNumber 
{
    string line;
    //struct binaryNumber();
};

/// <summary>
/// Decimal number class
/// </summary>
struct decimalNumber 
{
    int number;
};

// reading data
void reading(struct binaryNumber numbers[], int& n);
// coverting from skew binary to decimal
int calculating(string line, int& n);
// filling with decimal numbers
void filling(struct binaryNumber numbers[], struct decimalNumber decimal[], int& n);
// printing data
void printing(struct decimalNumber decimal[], int n);

int main()
{
    int n;
    struct binaryNumber numbers[20];
    struct decimalNumber decimal[20];

    reading(numbers, n);
    filling(numbers, decimal, n);
    printing(decimal, n);

    return 0;
}

/// <summary>
/// Reading primary data
/// </summary>
/// <param name="numbers"> Numbers array </param>
/// <param name="n"> Amount of numbers </param>
void reading(struct binaryNumber numbers[], int& n) 
{
    ifstream duom("data.txt");
    duom >> n;
        for (int i = 0; i < n; i++) {
            duom.ignore();
            duom >> numbers[i].line;
        }
    duom.close();
    return;
}

/// <summary>
/// Converting from skew binary to decimal number
/// </summary>
/// <param name="line"> Skew binary number </param>
/// <param name="n"> Amount of numbers </param>
/// <returns> Converted decimal number </returns>
int calculating(string line, int& n) 
{
    int res = 0;
    for(int j=0; j < n; j++)
    {        
        int l = line.size();        
        for (int i = 0; i < l; i++) {
            res += (((int)line[i] - 48) * (pow(2, l - i) - 1));
        }
        return res;
    }
}

/// <summary>
/// Fills up the decimal number class with a converted numbers
/// </summary>
/// <param name="numbers"> Binary number array </param>
/// <param name="decimal"> Decimal number array </param>
/// <param name="n"> Amount of numbers </param>
void filling(struct binaryNumber numbers[], struct decimalNumber decimal[], int& n) 
{
    for (int i = 0; i < n; i++)
        decimal[i].number = calculating( numbers[i].line, n);
    return;
}

/// <summary>
/// Printing converted numbers to file
/// </summary>
/// <param name="decimal"> Converted decimal numbers </param>
/// <param name="n"> Amount of numbers </param>
void printing(struct decimalNumber decimal[], int n)
{
    ofstream rez("rez.txt");

    for (int i = 0; i < n; i++) {
        rez << decimal[i].number << endl; 
    }
    rez.close();
    return;
}
