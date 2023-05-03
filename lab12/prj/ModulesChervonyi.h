#ifndef MODULESCHERVONYI_H_INCLUDED
#define MODULESCHERVONYI_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
class ClassLab12_Chervonyi
{
public:
    ClassLab12_Chervonyi();
    void setSide(float newside);
    float getSide(){return side;}
    float getVolume(){return volume(side);}
private:
    float side;
    float volume(float vside){return vside*vside*vside;}
};

ClassLab12_Chervonyi::ClassLab12_Chervonyi()
{
    side = 1;
}

void ClassLab12_Chervonyi::setSide(float newside)
{
    side = newside;
}

bool fileInDir()
{
    string cpp = __FILE__;
    size_t found = cpp.find("\\lab12\\prj");

    if (found == string::npos) {
        ofstream oufile("../TestSuite/TestResults.txt");
        oufile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        for (int i = 0; i < 100; i++) {
            cout << "\a";
        }
        oufile.close();
        return false;
    }
    return true;
}

string declareTestResult(ClassLab12_Chervonyi cube, int num)
{
    string result;
    result = "-------------------TS#"+to_string(num)+"--------------------\nSide: "+to_string(cube.getSide())+"\nVolume: "+to_string(cube.getVolume())+"\n";
    return result;
}

#endif // MODULESCHERVONYI_H_INCLUDED
