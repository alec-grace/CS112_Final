/*************************************************************************
 * Filename: NHLstats.h
 * Date created: 5/2/2021
 *
 * Description: Header file for the functions that retrieve
 * statistics in my final project.
 *
 * Last updated: 5/2/2021
*************************************************************************/

#ifndef FINALPROJECT_NHLSTATS_H
#define FINALPROJECT_NHLSTATS_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> getHomePIMs();

vector<int> getAwayPIMs();

int getHomePenalties();

int getAwayPenalties();

double getAvg(vector<int> &rawNums);

#endif //FINALPROJECT_NHLSTATS_H
