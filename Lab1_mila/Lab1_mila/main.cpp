#include "header.hpp"

int n = 0;

int main() 
{
    // path to the folder
    string path;
    cout << "Enter path to the folder that contains .csv files: \n";
    cin >> path;

    // read files from the folder
    vector<string> fileNames = input(path);

    // Clubs' quantity
    path += "\\";
    for (int size = fileNames.size(), i = 0; i < size; i++)
    {
        n += ClubsQuantity(path + fileNames[i]);
    }

    string* arr = new string[n];  // will store text of original files
    
    // Moving text from files csv into arr
    for (int size = fileNames.size(), i = 0; i < size; i++)
    {
        readFile(path + fileNames[i], arr);
    }
    
    // Creating the structure with values "club" and "score" + Filling values
    team* res = new team[n];
    processArr(arr, res);

    // Selection sort in descending order
    sortRes(res);

    // Outup of final result
    FinalFile(res);

    delete[] res, arr;
    system("pause");
    return 0;
}
