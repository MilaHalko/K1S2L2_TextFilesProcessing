#include "header.hpp"


int main() {
    string file1 = "/Users/mila/Documents/Progs/1 Lab/Lab_1_semester2/Lab1_mila/Lab1_mila/premier_league1.csv";  // путь к файлу1 csv
    string file2 = "/Users/mila/Documents/Progs/1 Lab/Lab_1_semester2/Lab1_mila/Lab1_mila/premier_league2.csv";  // путь к файлу2 csv
    int i = F_numb_of_clubs(file1);    // количество команд из файл1
    int j = F_numb_of_clubs(file2);    // количество команд из файл2
    int sum = i + j;                   // количество (общее) команд
    
    string* array_of_clubs = new string [i+j];  // массив названий футб. клубов
    F_array_of_clubs(array_of_clubs, file1, file2, i, j);
    // F_print_array(array_of_clubs, sum);   проверка заполнения массива
    return 0;
}
