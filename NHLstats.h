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

#include <fstream>
#include <string>
#include <vector>
#include "Game.h"
#include "Referee.h"

using namespace std;

vector<int> getHomePIMs();

vector<int> getAwayPIMs();

int getHomePenalties();

int getAwayPenalties();

double getAvg(vector<int> &rawNums);

vector<Ref> getRefStructs();

vector<Game> getGameStructs();

vector<Ref> getCompleteRefs(vector<Ref> refValues,
                               vector<Game> gameValues);

vector<string> getTop3(vector<Ref> &allRefs);

vector<string> getMostPenalties(vector<Ref> &allRefs);

vector<string> getLeastPenalties(vector<Ref> &allRefs);

#endif //FINALPROJECT_NHLSTATS_H
