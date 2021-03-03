#include "header.hpp"

int line = 0;   // current line number
extern int n;   // clubs' quantity

int ClubsQuantity(string path)               // open file -> check errors -> read 1st line -> return number (clubs' quantity)
{
    int quantity = 0;
    
    ifstream fin;
    fin.open(path);
    
    if (!fin.is_open())
    {
        cout << "Unable to open the file!" << endl;
    }
    else
    {
        string str;
        getline(fin, str);
        quantity = stoi(str);
    }
    
    fin.close();
    
    return quantity;
}

void readFile(string path, string* arr)       //  open file -> check errors -> move text to 'arr'
{
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

void processArr(string* arr, team res[])     // create the structure (club, score)
{
    for (int i = 0; i < line; i++)
    {
        res[i].club = findClub(arr[i]);      // returns club's name
        res[i].score = findScore(arr[i]);    // returns club's score
    }
}

string findClub(string str)                  // returns club's name from 'arr[i]'
{
    int pos;                                 // first comma's position (written after club's name)
    pos = str.find(',');
    str.erase(pos);
    
    return str;
}

int findScore(string str)                    // returns clubs's total score from 'arr[i]'
{
    int pos = 0,                             // position of ":"
        n1, n2,                              // points of: current team(n1), rival team(n2)
        result = 0;                          // total score

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

void sortRes(team res[])                     // selection sort of res[]
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = res[i].score;              // the biggest score
        int index = i;                       // score's index in rez[]
        
        for (int j = i; j < n; j++)
        {
            if (max < res[j].score)
            {
                max = res[j].score;
                index = j;
            }
        }
        
        swap(res[i], res[index]);            // invert max element with current
    }
}

void FinalFile(team res[])                   // create file -> check errors -> output in file using csv format
{
    ofstream fout;
    fout.open("FinalResults.csv");
    
    if(!fout.is_open())
    {
        cout << "Unable to create a file of results!" << endl;
    }
    else
    {
        char ch;
        
        do {
        cout << "Write '+' for oct:";
        cin >> ch;
        } while (ch != '+');
        
        for(int i = 0; i < n; i++){
            fout << res[i].club << ";" << oct << res[i].score << endl;
        }
        
    }
        /*
        for(int i = 0; i < n; i++){
            fout << res[i].club << ";" << res[i].score << endl;
        }*/
    
    fout.close();
}

string ToHex(int num)               // dec to hex
{
     
}

vector<string> input(string path)
{
    vector<string> arr; 
    path += "\\*.csv";                  // form mask
    const char* path_1 = path.c_str();

    _finddata_t data;
    intptr_t handle = _findfirst(path_1, &data);
    do
    {
        arr.push_back(data.name);
    } while (_findnext(handle, &data) == 0);

    _findclose(handle);

   
    cout << "=============================" << "\nIn this folder: \n";  // print file names
    for (int size = arr.size(), i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;

    return arr;
}
