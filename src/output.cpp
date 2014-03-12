#include <iostream>
#include <vector>
#include <algorithm>

#include "difference.h"


using namespace std;


bool compareDiffs(Difference a, Difference b)
{
    return (a.levenshteinSimilarity < b.levenshteinSimilarity);
}



void printAsTable(vector<Difference> &diff)
{
    sort(diff.begin(), diff.end(), compareDiffs);

    for (size_t i = 0; i < diff.size(); ++i)
        cout << diff[i].filename << " : " << diff[i].levenshteinSimilarity << "%" << endl;
}
