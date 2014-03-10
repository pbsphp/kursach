
#ifndef TEXT_OVERLAP_H
#define TEXT_OVERLAP_H


#include <vector>
#include <string>
#include <algorithm>

#include "levenshtein_distance.hpp"


using std::vector;
using std::string;
using std::max;



int textOverlap(vector<string> &file1, vector<string> &file2)
{
    int k = file1.size();
    int l = file2.size();

    float difference = levenshteinDistance(file1, file2);

    int diffInPercents = (1 - difference / max(k, l)) * 100;

    return diffInPercents;
}


#endif
