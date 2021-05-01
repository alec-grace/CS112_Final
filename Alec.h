/*************************************************************************
 * Filename: Alec.h
 * Date of creation: 4/17/2021
 *
 * Description: My personal header file to use across all projects for
 * simple but useful functions like split and playAgain
 *
 * Last updated: 4/29/2021
*************************************************************************/

#ifndef FINAL_PROJECT_ALEC_H
#define FINAL_PROJECT_ALEC_H

#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

bool playAgain();

vector<string> split(string str, string delimiter);

int randoNum(int start, int end);

void rStrip(string &str, char const &stripChar);

void rStrip(string &str);

void lStrip(string &str, char const &stripChar);

void lStrip(string &str);

void strip(string &str, char const &stripChar);

void strip(string &str);

#endif //FINAL_PROJECT_ALEC_H