#include "header.hpp"

int main() 
{
    string* arr = new string[n];
    
    // Считываем файлы в arr
    readFile("premier_league1.csv", arr);
    readFile("premier_league2.csv", arr);

    // Создаем team(struct) со значениями club и score + Заполнение значениями
    team res[n];
    processArr(arr, res);

    // Сортировка выбором по убыванию
    sortRes(res);

    // Вывод конечного результата
    FinalFile(res);
    
    return 0;
}
