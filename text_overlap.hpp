
#ifndef TEXT_OVERLAP_H
#define TEXT_OVERLAP_H


#include <stdexcept>
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



class InputError : public std::runtime_error
{
public:
    InputError() : std::runtime_error("InputError") {}
};



class NotCodeFileError : public std::runtime_error
{
public:
    NotCodeFileError() : std::runtime_error("NotCodeFileError") {}
};



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



bool isCodeString(string str)
{
    string ignoredSymbols = "{} \t\n\v\f\r()[];";

    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        if (ignoredSymbols.find(*it) == string::npos) {
            return true;
        }
    }

    return false;
}



int textOverlap(vector<string> file1, vector<string> file2)
{
    int k = file1.size();
    int l = file2.size();

    float difference = levenshteinDistance(file1, file2);

    int diffInPercents = (1 - difference / max(k, l)) * 100;

    return diffInPercents;
}



void readFromFile(string filename, vector<string> &fileStrings)
{
    if (NOT_ONLY_C_AND_CPP_FILES || (isCodeFile(filename))) {
        ifstream file(filename.c_str());

        if (file) {
            string line;

            while (getline(file, line)) {
                if ((!COMPARE_ONLY_CODE) || isCodeString(line)) {
                    fileStrings.push_back(line);
                }
            }
        }
        else {
            throw InputError();
        }
    }
    else {
        throw NotCodeFileError();
    }
}



#endif
