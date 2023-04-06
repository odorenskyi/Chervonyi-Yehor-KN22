#include <iostream>
#include "ModulesChervonyi.h"
using namespace std;

int main()
{
    cout << "Unit testing for task 9.1\n";
    for(int i = 0; i < 4; i++)
        {
            int p;
            string result;
            cout << "Enter Bophor point: ";
            cin >> p;
            cout << "Result: ";
            cin >> result;
            if (task9_1(p) == result)
                cout << "Test#"<<i+1<<" Passed\n";
            else
                cout << "Test#"<<i+1<<" Failed\n";
        }

    cout << "Unit testing for task 9.2\n";
    for (int i = 0; i < 4; i++)
        {
            float footsize;
            float result;
            cout << "Enter Ukraine foot size: ";
            cin >> footsize;
            cout << "Result: ";
            cin >> result;
            if (task9_2(footsize) == result)
                cout << "Test#"<<i+1<<" Passed\n";
            else
                cout << "Test#"<<i+1<<" Failed\n";
        }

    cout << "Unit testing for task 9.3\n";
    for (int i = 0; i < 4; i++)
        {
            int number;
            int result;
            cout << "Enter number: ";
            cin >> number;
            cout << "Result: ";
            cin >> result;
            if (task9_3(number) == result)
                cout << "Test#"<<i+1<<" Passed\n";
            else
                cout << "Test#"<<i+1<<" Failed\n";
        }

}
