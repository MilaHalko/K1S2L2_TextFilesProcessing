#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct team
{
	string club;
	int score = 0;
};

int ClubsQuantity(string path);              // returns clubs' quantity
void readFile(string path, string* arr);     // open file -> check errors -> move text to 'arr'
void processArr(string* arr, team res[]);    // create the structure (club, score)
string findClub(string str);                 // returns club's name from 'arr[i]'
int findScore(string str);                   // returns clubs's total score from 'arr[i]'
void sortRes(team res[]);                    // selection sort of res[]
void FinalFile(team res[]);                  // create file -> check errors -> output in file using csv format
