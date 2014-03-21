#include <iostream>
#include <vector>
#include <algorithm>

#include "difference.h"
#include "config.h"


using namespace std;


void printAsTable(vector<Difference> &diff)
{
    sort(diff.begin(), diff.end(), [](Difference a, Difference b) {
        return (a.levenshteinSimilarity < b.levenshteinSimilarity);
    });

    for (auto it = diff.begin(), e = diff.end(); it != e; ++it)
        cout << it->filename << " : " << it->levenshteinSimilarity << "%\n";
}
