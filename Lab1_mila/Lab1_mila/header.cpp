#include "header.hpp"

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
        res[i].club = findClub(arr[i]);
        res[i].score = findScore(arr[i]);
    }
}

string findClub(string club)
{
    int pos;               // позиция запятой после названия клуба
    pos = club.find(',');
    club.erase(pos);
    
    return club;
}

int findScore(string score)
{
    int pos = 0,          // позиция ":"
        n1, n2,           // счет команды(n1), противника(n2z)
        result = 0;       // количество баллов полученых за игру

    while (score.find(':') != string::npos)
    {
        pos = score.find(':');

        n1 = stoi(score.substr(pos - 1));
        n2 = stoi(score.substr(pos + 1));

        if (n1 > n2) result += 3;
        else
        {
            if (n1 == n2) result += 1;
        }
        score.erase(score.begin() + pos);
    }

    return result;
}

void sortRes(team res[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = res[i].score;
        int index = i;
        
        for (int j = i; j < n; j++)
        {
            if (max < res[j].score)
            {
                max = res[j].score;
                index = j;
            }
        }
        
        swap(res[i], res[index]);
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

void FinalFile(team res[])
{
    ofstream fout;
    fout.open("FinalResults.csv");
    
    if(!fout.is_open())
    {
        cout << "Unable to create a file of results!" << endl;
    }
    else
    {
        for(int i = 0; i < n; i++){
            fout << res[i].club << ";" << res[i].score << endl;
        }
    }
    
    fout.close();
}
