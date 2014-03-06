
#ifndef TEXT_OVERLAP_H
#define TEXT_OVERLAP_H


#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "levenshtein_distance.hpp"

#include "config.h"


using std::ifstream;
using std::vector;
using std::string;
using std::max;
using std::cerr;
using std::endl;



bool hasEnding(string str, string ending)
{
    int k = str.length();
    int l = ending.length();

    if (k >= l) {
        return (str.compare(k - l, l, ending) == 0);
    }
    else {
        return false;
    }
}



bool isCodeFile(string filename)
{
    if (hasEnding(filename, ".cpp") || hasEnding(filename, ".c") || \
        hasEnding(filename, ".hpp") || hasEnding(filename, ".h"))
        return true;
    else
        return false;
}



int textOverlap(string filename1, string filename2)
{
    if (NOT_ONLY_C_AND_CPP_FILES || (isCodeFile(filename1) && isCodeFile(filename2))) {
        ifstream file1(filename1.c_str());
        ifstream file2(filename2.c_str());

        vector<string> fileStrings1;
        vector<string> fileStrings2;

        if (file1 && file2) {
            string line;

            while (getline(file1, line)) {
                if (COMPARE_EMPTY_LINES || line != "") {
                    fileStrings1.push_back(line);
                }
            }

            while (getline(file2, line)) {
                if (COMPARE_EMPTY_LINES || line != "") {
                    fileStrings2.push_back(line);
                }
            }

            int k = fileStrings1.size();
            int l = fileStrings2.size();

            float difference = levenshteinDistance(fileStrings1, fileStrings2);

            int diffInPercents = (1 - difference / max(k, l)) * 100;

            return diffInPercents;
        }
        else {
            cerr << "Can't open " << filename1 << " or " << filename2 << endl;

            return 0;
        }
    }
    else {
        cerr << "Not C/CPP file, skipping" << endl;
        return 0;
    }
}


#endif
