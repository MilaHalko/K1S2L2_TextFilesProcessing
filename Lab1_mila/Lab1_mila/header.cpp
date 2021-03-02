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
        res[i].name = findTeam(arr[i]);
        res[i].score = findScore(arr[i]);
    }
}

string findTeam(string str)
{
    string temp;

    int pos = str.find(',');
    temp = str.substr(0, pos);

    return temp;
}

int findScore(string str)
{
    int pos = 0,
        n1, n2,
        result = 0;

    while (str.find(':') != string::npos)
    {
        pos = str.find(':');

        n1 = stoi(str.substr(pos - 1));
        n2 = stoi(str.substr(pos + 1));

        if (n1 > n2) result += 3;
        else
        {
            if (n1 == n2) result += 1;
        }
        str.erase(str.begin() + pos);
    }

    return result;
}

void sortRes(team res[])
{
    team temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (res[j].score < res[j + 1].score)
            {
                temp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = temp;
            }
        }
    }
}

void writeFile(string path, team res[])
{
    ofstream fout;
    fout.open(path);

    if (!fout.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fout << res[i].name << "  " << res[i].score << "\n";
        }
    }

    fout.close();
}