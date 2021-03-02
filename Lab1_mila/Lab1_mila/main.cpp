#include "header.hpp"

int main() 
{
    string* arr = new string[n];  // stores text of 2 orinal files
    
    // Moving text from files csv into arr
    readFile("premier_league1.csv", arr);
    readFile("premier_league2.csv", arr);

    
    // Creating the structure with values "club" and "score" + Filling values
    team res[n];
    processArr(arr, res);

    
    // Selection sort in descending order
    sortRes(res);

    
    // Outup of final result
    FinalFile(res);
    
    return 0;
}
