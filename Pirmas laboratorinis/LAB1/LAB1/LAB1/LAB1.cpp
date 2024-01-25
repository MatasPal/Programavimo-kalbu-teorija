#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/// <summary>
/// Binary number class
/// </summary>
struct BinaryNumber
{
    string line; //binary number

    /// <summary>
    /// Converting from skew binary to decimal number
    /// </summary>
    /// <param name="line"> Skew binary number </param>
    /// <param name="n"> Amount of numbers </param>
    /// <returns> Converted decimal number </returns>
    int to_decimal(string line, int& n)
    {
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            int l = line.size();
            for (int i = 0; i < l; i++) {
                res += (((int)line[i] - 48) * (pow(2, l - i) - 1));
            }
            return res;
        }
    }

};

/// <summary>
/// Decimal number class
/// </summary>
struct DecimalNumber
{    
    int number;   
};

/// <summary>
/// Printing converted numbers to file
/// </summary>
/// <param name="outputFile"> Output file </param>
/// <param name="line"> Binary numbers </param>
/// <param name="convertedNumber"> Decimal numbers </param>
/// <param name="append"></param>
void PrintResult(string outputFile, string line,
    int convertedNumber, bool append)
{
    ofstream result;
    
    if (append)
        result.open(outputFile, ios_base::app);
    else
        result.open(outputFile);
    result << "Skew binary: " << line << "  " << "decimal: " << convertedNumber << endl;
    return;
}

/// <summary>
/// Reading data and performing all tasks
/// </summary>
/// <param name="inputFile"> Data file </param>
/// <param name="outputFile"> Result file </param>
void ReadAndPerform( string inputFile, string outputFile)
{  
    int n;// Amount of numbers 
    DecimalNumber numbers[20];
    BinaryNumber binary[20];

    ifstream data(inputFile);
    data >> n;
    for (int i = 0; i < n; i++)
    {
        string line;
        data.ignore();
        data >> binary[i].line;
        line = binary[i].line;
       
        numbers[i].number = binary->to_decimal(line, n);
        int calculated = numbers[i].number;        

        bool append = false;
        if (i > 0)
            append = true;
        PrintResult(outputFile, line, calculated, append);
    }

    data.close();
    return;
}

int main()
{
    string inputFile = "Data.txt";
    string outputFile = "Results.txt";

    // Duration of operations start point
    auto start = high_resolution_clock::now();

    // Main calculations method
    ReadAndPerform(inputFile, outputFile);

    // Duration of operations end point
    auto stop = high_resolution_clock::now();

    // Duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;

    return 0;
}
