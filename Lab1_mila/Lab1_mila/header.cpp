#include "header.hpp"

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
