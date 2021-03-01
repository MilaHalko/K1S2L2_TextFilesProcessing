#include "header.hpp"
using namespace std;

int main() 
{
    string* arr = new string[n];
    
    readFile("premier_league1.csv", arr);
    readFile("premier_league2.csv", arr);


    // output
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    system("pause");
}
