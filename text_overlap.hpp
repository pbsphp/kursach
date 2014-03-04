
#ifndef TEXT_OVERLAP_H
#define TEXT_OVERLAP_H


#include <fstream>
#include <vector>

#include "levenshtein_distance.hpp"


using std::ifstream;
using std::vector;
using std::string;
using std::max;



int text_overlap(string filename1, string filename2)
{
    ifstream file1(filename1.c_str());
    ifstream file2(filename2.c_str());

    vector<string> fileStrings1;
    vector<string> fileStrings2;

    if (file1 && file2) {
        string line;

        while (getline(file1, line)) {
            fileStrings1.push_back(line);
        }

        while (getline(file2, line)) {
            fileStrings2.push_back(line);
        }

        int k = fileStrings1.size();
        int l = fileStrings2.size();

        float difference = levenshtein_distance(fileStrings1, fileStrings2, k, l);

        int diffInPercents = (1 - difference / max(k, l)) * 100;

        return diffInPercents;
    }
    else {

        // TODO: throw exception
        std::cout << "Error 1" << std::endl;

        return 0;
    }
}


#endif
