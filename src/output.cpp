#include <iostream>
#include <vector>
#include <algorithm>

#include "difference.h"
#include "config.h"


using namespace std;


inline bool compareDiffs(Difference a, Difference b)
{
    return (a.levenshteinSimilarity < b.levenshteinSimilarity);
}



void printAsTable(vector<Difference> &diff)
{
    sort(diff.begin(), diff.end(), compareDiffs);

    for (vector<Difference>::iterator it = diff.begin(),
        e = diff.end(); it != e; ++it)
        cout << it->filename << " : " << it->levenshteinSimilarity << "%\n";
}
