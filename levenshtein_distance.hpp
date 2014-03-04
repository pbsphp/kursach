
#ifndef LEVENSHTEIN_DISTANCE_H
#define LEVENSHTEIN_DISTANCE_H


#include <vector>
#include <string>
#include <algorithm>


using std::string;
using std::vector;
using std::min;



int levenshtein_distance(vector<string> &file1, vector<string> &file2, int i, int j)
{
    if ((i == 0) && (j == 0)) {
        return 0;
    }
    else if ((j == 0) && (i > 0)) {
        return i;
    }
    else if ((i == 0) && (j > 0)) {
        return j;
    }
    else if (file1[i - 1] == file2[j - 1]) {
        return levenshtein_distance(file1, file2, i - 1, j - 1);
    }
    else if ((j > 0) && (i > 0) && (file1[i - 1] != file2[j - 1])) {
        return min(
                        levenshtein_distance(file1, file2, i, j - 1) + 1,
                    min(
                        levenshtein_distance(file1, file2, i - 1, j    ) + 1,
                        levenshtein_distance(file1, file2, i - 1, j - 1) + 1
                    )
                );
    }

    // TODO: Throw exception
    std::cout << "fail" << std::endl;
    return -1;
}


#endif
