#include <vector>
#include <string>
#include <algorithm>

#include "levenshtein_distance.hpp"


using namespace std;


int textOverlap(vector<string> &file1, vector<string> &file2)
{
    int distance = levenshteinDistance(file1, file2);

    int m = max(file1.size(), file2.size());

    float difference = (m != 0) ? float(distance) / m
                                : 1;

    int differencePercent = difference * 100;

    return 100 - differencePercent;
}
