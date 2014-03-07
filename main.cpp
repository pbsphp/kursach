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
        string fileForComparisonName = argv[1];

        vector<string> filenamesList;

        for (int i = 2; i < argc; ++i) {
            readDirectory(filenamesList, argv[i]);
        }


        vector<string> fileForComparison;

        try {
            readFromFile(fileForComparisonName, fileForComparison);
        }
        catch (InputError &e) {
            cerr << "Cannot read " << fileForComparisonName << endl;
            return 1;
        }
        catch (NotCodeFileError &e) {
            cerr << fileForComparisonName << " is not c/cpp file" << endl;
            return 1;
        }


        vector<Difference> results;

        for (size_t i = 0; i < filenamesList.size(); ++i) {

            vector<string> exampleFile;

            try {
                readFromFile(filenamesList[i], exampleFile);
            }
            catch (InputError &e) {
                cerr << "Skipping " << filenamesList[i] << endl;
                break;
            }
            catch (NotCodeFileError &e) {
                cerr << "Skipping " << filenamesList[i] << endl;
                break;
            }


            Difference diff;

            diff.filename = filenamesList[i];
            diff.levenshteinSimilarity = textOverlap(fileForComparison, exampleFile);
            // diff.tabStyles = ...

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
