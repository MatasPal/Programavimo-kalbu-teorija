#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class InOutUtils
{
    /// <summary>
    /// 
    /// </summary>
    /// <param name="numbers"></param>
    /// <param name="n"></param>
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
};

