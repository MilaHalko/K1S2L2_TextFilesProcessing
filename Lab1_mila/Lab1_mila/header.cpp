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
int F_numb_of_clubs(string file)
{
    int number;  // число команд
    string s;    // вспомогательная строка
    ifstream fin(file);
    
    getline(fin, s);
    number = stoi(s);
    
    return number;
}


void F_array_of_clubs(string* array_of_clubs, string file1, string file2, int i, int j)
{
    ifstream fin(file1);
    string line = "";   // строка из файла в последствии очищается до названия клуба
    int pos;            // позиция запятой после названия клуба
    
    if (!fin.is_open()) {
        cout << "Ошибка! (файл №1)" << endl;
    }
    
    else {
        fin.ignore(10, '\n');
        for(int n = 0; n < i; n++) {
            getline(fin, line);
            pos = line.find(',');
            line.erase(pos);
            array_of_clubs[n] = line;
            line = "";
        }
    }
    fin.close();
    
    
    ifstream fin2(file2);
    
    if (!fin2.is_open()) {
        cout << "Ошибка! (файл №2)" << endl;
    }
    
    else {
        fin2.ignore(10, '\n');
        for(int n = i; n < i + j; n++) {
            getline(fin2, line);
            pos = line.find(',');
            line.erase(pos);
            array_of_clubs[n] = line;
            line = "";
        }
    }
    fin2.close();
}


void F_print_array(string* array_of_clubs, int sum)
{
    for(int n = 0; n < sum; n++)
    {
        cout << array_of_clubs[n] << endl;
    }
}
