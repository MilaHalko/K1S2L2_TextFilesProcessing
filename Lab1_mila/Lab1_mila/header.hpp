#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int n = 20;
struct team
{
	string name;
	int score = 0;
};

void readFile(string path, string* arr);
void processArr(string* arr, team res[]);
string findTeam(string str);
int findScore(string str);
void sortRes(team res[]);
int F_numb_of_clubs(string);
void F_array_of_clubs(string*, string, string, int, int);
void F_print_array(string*, int);
