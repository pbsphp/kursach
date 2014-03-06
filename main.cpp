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

            try {
                diff.levenshteinSimilarity = textOverlap(fileForComparison, filenamesList[i]);
            }
            catch (InputError &e) {
                cerr << "Cannot read file, skipping" << endl;
                break;
            }
            catch (NotCodeFileError &e) {
                cerr << "Not c/cpp file, skipping" << endl;
                break;
            }

            results.push_back(diff);
        }


        printAsTable(results);
    }
    else {
        cerr << "No input files" << endl;
        return 1;
    }


    // string s = "sooqa";
    // string s2 = "\n{};";

    // cout << isCodeString(s2) << endl;


    return 0;
}
