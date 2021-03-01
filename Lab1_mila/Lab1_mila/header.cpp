#include "header.hpp"
using namespace std;

int line = 0;   // current line number

void readFile(string path, string* arr)     //  open file and write its 
{                                           //  content to array of strings
    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Unable to open the file!" << endl;
    }
    else
    {
        string str;

        while (!fin.eof())
        {
            str.clear();
            getline(fin, str);

            if (!isdigit(str[0]))
            {
                arr[line] = str;
                line++;
            }
        }

    }
    fin.close();
}

void processArr(string* arr, team res[])
{
    for (int i = 0; i < line; i++)
    {
        res[i].name = findTeam();
        res[i].score = findScore();
    }
}