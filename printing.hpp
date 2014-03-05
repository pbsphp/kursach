
#ifndef PRINTING_H
#define PRINTING_H


#include <iostream>
#include <vector>


using std::cout;
using std::endl;



struct Difference
{
    string filename;
    int levenshteinSimilarity;
    // TODO: compare variables, classes, etc
    // TODO: compare coding styles
};



inline bool compareDiffs(Difference a, Difference b)
{
    return (a.levenshteinSimilarity < b.levenshteinSimilarity);
}



void printAsTable(vector<Difference> &diff)
{
    sort(diff.begin(), diff.end(), compareDiffs);

    for (int i = 0; i < diff.size(); ++i)
    {
        cout << diff[i].filename << " : " << diff[i].levenshteinSimilarity << "%" << endl;
    }
}


#endif
