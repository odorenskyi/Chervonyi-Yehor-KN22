#include <iostream>
#include "ModulesChervonyi.h"
#include "windows.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream in1 ("in1.txt", ios::out);
    ofstream in2 ("in2.txt", ios::out);
    ofstream in3 ("in3.txt", ios::out);
    string ofname;
    string ifname;
    float x, y, z;
    int b;
    //TS1
    if (in1 && in2 && in3){
        in1 << "Машина" << endl;
        in1.close();
        in2 << "буде";
        in2.close();
        in3 << "словник";
        in3.close();
        for (int i =0; i<3; i++)
        {
            task10_1("out"+to_string(i+1)+".txt", "in"+to_string(i+1)+".txt");
        }
    }
    //TS2
    if (in2){
        for (int i =0; i<3; i++)
        {
            task10_2("in"+to_string(i+1)+".txt");
        }
    }
    //TS3
    if (in3){

        float tslist [3][4]= {{1, 0.2, 0.5, 8}, {3, 2, 1, 5}, {5, 1, 6, 10}};
        for (int i =0; i<3; i++)
        {
            task10_3("out"+to_string(i+1)+".txt", tslist[i][0], tslist[i][1], tslist[i][2], tslist[i][3]);
        }
    }

    //Check
    for (int i =0; i<3; i++)
    {
        //check in files
        fstream stream1;
        stream1.open("in"+to_string(i+1)+".txt", ios::in | ios::binary);
        fstream stream2;
        stream2.open("tsin"+to_string(i+1)+".txt", ios::in | ios::binary);
        if (!stream1.is_open() || !stream2.is_open())
            cout << "Error: Unable to open file." << endl;
        char c1 = stream1.get();
        char c2 = stream2.get();

        while (!stream1.eof() && !stream2.eof() && c1 == c2) {
            c1 = stream1.get();
            c2 = stream2.get();
        }
        if (stream1.eof() && stream2.eof())
            cout << "TS#"<<i+1<<" in file check : PASSED" << endl;
        else
            cout << "TS#"<<i+1<<" in file check : FAILED" << endl;

        //check out files
        stream1.open("out"+to_string(i+1)+".txt", ios::in | ios::binary);
        stream2.open("tsout"+to_string(i+1)+".txt", ios::in | ios::binary);
        if (!stream1.is_open() || !stream2.is_open())
            cout << "Error: Unable to open file." << endl;
        char c1 = stream1.get();
        char c2 = stream2.get();

        while (!stream1.eof() && !stream2.eof() && c1 == c2) {
            c1 = stream1.get();
            c2 = stream2.get();
        }
        if (stream1.eof() && stream2.eof())
            cout << "TS#"<<i+1<<" out file check : PASSED" << endl;
        else
            cout << "TS#"<<i+1<<" out file check : FAILED" << endl;
    }
    system("pause");
    return 0;
}
