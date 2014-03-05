#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include "text_overlap.hpp"
#include "dir.hpp"
#include "printing.hpp"


using namespace std;



int main(int argc, char *argv[])
{
    if (argc > 2) {

        string fileForComparison = argv[1];


        vector<string> filenamesList;

        for (int i = 2; i < argc; ++i) {
            readDirectory(filenamesList, argv[i]);
        }


        vector<Difference> results;

        for (int i = 0; i < filenamesList.size(); ++i) {
            Difference diff;
            diff.filename = filenamesList[i];
            diff.levenshteinSimilarity = textOverlap(fileForComparison, filenamesList[i]);

            results.push_back(diff);
        }


        printAsTable(results);
    }
    else {
        cerr << "No input files" << endl;
        return 1;
    }


    return 0;
}
