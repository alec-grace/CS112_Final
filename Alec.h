/*************************************************************************
 * Filename: Alec.h
 * Date of creation: 4/17/2021
 *
 * Description: My personal header file to use across all projects for
 * simple but useful functions like split and playAgain
 *
 * Last updated: 5/5/2021
*************************************************************************/

#ifndef FINAL_PROJECT_ALEC_H
#define FINAL_PROJECT_ALEC_H

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

bool playAgain();

vector<string> split(string str, string delimiter);

vector<string> split(string &str);

int randoNum(int start, int end);

void rStrip(string &str, char const &stripChar);

void rStrip(string &str);

void lStrip(string &str, char const &stripChar);

void lStrip(string &str);

void strip(string &str, char const &stripChar);

void strip(string &str);

int getIntput(string &message, int beginRange, int endRange);

int getIndex(string const &findStr, vector<string> const &searchVec);

string lowerCase(string &my_str);

double round2(double &toRound);

#endif //FINAL_PROJECT_ALEC_H
