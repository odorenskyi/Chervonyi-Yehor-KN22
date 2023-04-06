#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

float s_calculation(float x, float y, float z)
{
    float s;
    s = log(x - y)+sqrt((M_PI * pow(x, 2))/(x + (z/2 * pow(y,2))));
    return roundf(s * 100000.0f) / 100000.0f;
}

string task9_1(int point)
{
    if (point >= 0 && point <=12)
    {
        switch (point)
        {
        case 0:
            return "<1.08";
        case 1:
            return "1.08-5.4";
        case 2:
            return "5.76-33.84";
        case 3:
            return "33.84-19.44";
        case 4:
            return "19.8-28.4";
        case 5:
            return "28.8-38.52";
        case 6:
            return "38.88-49.68 ";
        case 7:
            return "50.04-61.56";
        case 8:
            return "61.92-74.52";
        case 9:
            return "74.88-87.84";
        case 10:
            return "88.2-102.24";
        case 11:
            return "102.6-117.36";
        case 12:
            return ">=117.72";
        }
    }
}

float task9_2(float footsize)
{
    if(footsize == 35)
        return 23;
    if(footsize == 36)
        return 23.5;
    if(footsize == 36.5)
        return 24;
    if (footsize == 37)
        return 24.5;
    if (footsize == 38)
        return 25;
    if (footsize == 39)
        return 25.5;
    if (footsize == 40.5)
        return 26;
    if (footsize == 41)
        return 26.5;
    if (footsize == 41.5)
        return 27;
    if (footsize == 42)
        return 27.5;
    if (footsize == 43)
        return 28.5;
    if (footsize == 44)
        return 29;
    if (footsize == 45)
        return 29.5;
    if (footsize == 46)
        return 30;
    if (footsize == 47)
        return 30.5;
    if (footsize == 47.5)
        return 31;
    if (footsize == 48)
        return 31.5;
    if (footsize == 48.5)
        return 32;
}

int task9_3(int number)
{
    if (number >=1000 && number <=10000)
    {
        int bit = (number >> 14) & 1;
        int count = 0;

        if (bit == 0)
            {
            while (number != 0)
            {
                count += (number & 1) == 0 ? 1 : 0;
                number >>= 1;
            }
            return count;
        }
        else
        {
            while (number != 0)
            {
                count += (number & 1) == 1 ? 1 : 0;
                number >>= 1;
            }
            return count;
        }
    }
}


