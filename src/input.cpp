#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


#include "config.h"
#include "remove_comments.hpp"

// TODO: Exceptions in separate file
#include "input.hpp"


using std::ifstream;
using std::vector;
using std::string;
using std::max;
using std::endl;



bool hasEnding(string str, string ending)
{
    int k = str.length();
    int l = ending.length();

    if (k >= l)
        return (str.compare(k - l, l, ending) == 0);
    else
        return false;
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

    for (string::iterator it = str.begin(); it != str.end(); ++it)
        if (ignoredSymbols.find(*it) == string::npos)
            return true;

    return false;
}



void readFromFile(string filename, vector<string> &fileStrings)
{
    if (NOT_ONLY_C_AND_CPP_FILES || (isCodeFile(filename))) {
        ifstream file(filename.c_str());

        if (file) {
            string line;

            bool isMultilineCommentBody = false;

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
