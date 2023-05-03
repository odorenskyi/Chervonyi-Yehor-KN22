#include <iostream>
#include <fstream>
#include <string>
#include "ModulesChervonyi.h"
using namespace std;

int main()
{
    string line;
    if(fileInDir() == 0) {return 0;}

    ClassLab12_Chervonyi cube;
    ifstream TSFile("../TestSuite/TS.txt");
    ofstream RFile("../TestSuite/TestResults.txt");
    if(TSFile.is_open()){
        if(RFile.is_open()){
            int counter = 1;
            while (getline(TSFile, line))
            {
                cube.setSide(stof(line));
                RFile << declareTestResult(cube,counter);
                counter++;
            }
        }
    }
    TSFile.close();
    RFile.close();
    system("pause");
    return 0;
}
