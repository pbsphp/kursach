#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include "text_overlap.hpp"
#include "dir.hpp"

#include "input.hpp"
#include "output.hpp"

#include "config.h"


using namespace std;



int main(int argc, char *argv[])
{
    if (argc > 2 || FRIENDLY_MODE) {

        string fileForComparisonName;
        vector<string> filenamesList;

        if (argc > 2) {
            fileForComparisonName = argv[1];

            for (int i = 2; i < argc; ++i) {
                readDirectory(filenamesList, argv[i]);
            }
        }
        else {
            if (VERBOSE_MODE)
                cout << "Filename (full path): ";
            cin >> fileForComparisonName;

            if (VERBOSE_MODE)
                cout << "Compare with (file or directory): ";
            string compareWith;
            cin >> compareWith;
            readDirectory(filenamesList, compareWith);
        }


        vector<string> fileForComparison;

        try {
            readFromFile(fileForComparisonName, fileForComparison);
        }
        catch (InputError &e) {
            if (VERBOSE_MODE)
                cerr << "Cannot read " << fileForComparisonName << endl;
            return 1;
        }
        catch (NotCodeFileError &e) {
            if (VERBOSE_MODE)
                cerr << fileForComparisonName << " is not c/cpp file" << endl;
            return 1;
        }


        vector<Difference> results;

        for (vector<string>::iterator filenameIt = filenamesList.begin(),
            e = filenamesList.end(); filenameIt != e; ++filenameIt) {

            vector<string> exampleFile;

            try {
                readFromFile(*filenameIt, exampleFile);
            }
            catch (InputError &e) {
                if (VERBOSE_MODE)
                    cerr << "Skipping " << *filenameIt << endl;
                continue;
            }
            catch (NotCodeFileError &e) {
                if (VERBOSE_MODE)
                    cerr << "Skipping " << *filenameIt << endl;
                continue;
            }


            Difference diff;

            diff.filename = *filenameIt;
            diff.levenshteinSimilarity = textOverlap(fileForComparison, exampleFile);
            // diff.tabStyles = ...

            results.push_back(diff);
        }

        printAsTable(results);

        if (FRIENDLY_MODE)
            pause();
    }
    else {
        if (VERBOSE_MODE)
            cerr << "No input files" << endl;
        return 1;
    }


    return 0;
}
