#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int n = 20;
struct team
{
	string club;
	int score = 0;
};

void readFile(string path, string* arr);
void processArr(string* arr, team res[]);
string findClub(string club);
int findScore(string score);
void sortRes(team res[]);
void FinalFile(team res[]);
