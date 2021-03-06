#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <array>


#include "config.h"
#include "remove_comments.hpp"

#include "input_exceptions.hpp"


using namespace std;


bool hasEnding(string str, string ending)
{
    int k = str.length();
    int l = ending.length();

    if (k >= l)
        return (str.compare(k - l, l, ending) == 0);

    return false;
}



inline bool isCodeFile(string filename)
{
    std::array<string, 6> acceptedExtensions = {
        ".cpp",
        ".hpp",
        ".c",
        ".h",
        ".cxx",
        ".cc"
    };

    for (size_t i = 0; i < acceptedExtensions.size(); ++i)
        if (hasEnding(filename, acceptedExtensions[i]))
            return true;

    return false;
}



bool isCodeString(string str)
{
    string ignoredSymbols = "\t\n\v\f\r ()[]{};,\\";

    for (auto it = str.begin(), e = str.end(); it != e; ++it)
        if (ignoredSymbols.find(*it) == string::npos)
            return true;

    return false;
}



void readFromFile(string filename, vector<string> &fileStrings)
{
    if (NOT_ONLY_C_AND_CPP_FILES || (isCodeFile(filename))) {
        ifstream file(filename.c_str());

        if (file) {
            bool isMultilineCommentBody = false;

            string line;
            while (getline(file, line)) {
                if (REMOVE_COMMENTS) {
                    removeCommentsFrom(line, isMultilineCommentBody);
                }

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


void pause()
{
    cout << "Press Enter to continue... " << flush;
    cin.ignore(256,'\n');
    cin.get();
}
