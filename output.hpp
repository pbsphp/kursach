
#ifndef OUTPUT_H
#define OUTPUT_H


#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;



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

    for (size_t i = 0; i < diff.size(); ++i)
    {
        cout << diff[i].filename << " : " << diff[i].levenshteinSimilarity << "%" << endl;
    }
}


#endif
