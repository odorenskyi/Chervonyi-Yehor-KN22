#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <bitset>
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

void task10_1 (string ofname, string ifname)
{
    string word;
    fstream ofile;
    ofile.open(ofname, ios::out | ios::trunc);

    if (ofile.is_open())
    {
        ofile << "                        Червоний Єгор                      " << endl
              << " Центрально український національний технічний університет " << endl
              << "                        Кропивнийький                      " << endl
              << "                           Україна                         " << endl
              << "                            2023                           " << endl << endl;
        fstream ifile;
        ifile.open(ifname, ios::in);
        if(ifile.is_open())
        {
            string word;
            char ch;
            int lcount = 0;
            getline(ifile, word);
            for (int i = 0; i < word.length(); i++)
            {
                ch = word[i];
                if (ch == 'а' || ch == 'е' || ch == 'є' || ch == 'и' || ch == 'і' || ch == 'ї' || ch == 'о' || ch == 'у' || ch == 'ю' || ch == 'я' ||
                    ch == 'А' || ch == 'Е' || ch == 'Є' || ch == 'И' || ch == 'І' || ch == 'Ї' || ch == 'О' || ch == 'У' || ch == 'Ю' || ch == 'Я')
                    continue;
                else
                    lcount++;
            }
            ofile << "Кількість приголосних літер у слові із вхідного файлу: "<< lcount/4 << endl;
            string phrase = "Про себе не кажи недобрих слів, Бо має сказане таємну силу. Кажи: \"Я сильний, впевнений, щасливий!\" І буде саме так, як ти хотів!";
            if(phrase.find(word) != string::npos)
                ofile << "Слово " << word << " є у краплинці Віталія Іващенка" << endl;
            else
                ofile << "Слова " << word << " немає у краплинці Віталія Іващенка" << endl;
        ifile.close();
        }
    ofile.close();
    }
}

void task10_2(string fname)
{
    fstream ffile;
    time_t time = std::time(nullptr);
    ffile.open(fname, ios::in);
    if (ffile.is_open())
    {
        string word;
        getline(ffile, word);
        ffile.close();

        ffile.open(fname, ios::app);
        if (ffile.is_open())
        {
            ffile <<endl
                << "Перша літера слова: " << word[0] << endl
                <<  "Остання літера слова: " << word[word.length() - 1] << endl
                <<  "Дата дозапису: " << asctime(localtime(&time)) << endl;
        }
        ffile.close();
    }
}

void task10_3(string fname, float x, float y, float z, int b)
{

    fstream ofile;
    bitset<8> binary(b);
    ofile.open(fname, ios::app);
    ofile << "Результат функції s_calculation: " << s_calculation(x,y,z) << endl
          << "Число у двійковому коді: " << binary << endl;
    ofile.close();
}

