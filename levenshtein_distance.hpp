
#ifndef LEVENSHTEIN_DISTANCE_H
#define LEVENSHTEIN_DISTANCE_H


#include <vector>
#include <string>
#include <algorithm>


using std::string;
using std::vector;
using std::min;



inline int costOfReplacement(string first, string second)
{
    return (first != second) ? 1 : 0;
}



int levenshteinDistance(vector<string> &file1, vector<string> &file2)
{
    const int m = file1.size();
    const int n = file2.size();


    int matrix[m + 1][n + 1];

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            matrix[i][j] = 0;
        }
    }


    for (int j = 1; j <= n; ++j) {
        matrix[0][j] = matrix[0][j - 1] + 1;
    }


    for (int i = 1; i <= m; ++i) {
        matrix[i][0] = matrix[i - 1][0] + 1;

        for (int j = 1; j <= n; ++j) {
            matrix[i][j] = min(
                                    matrix[i - 1][  j  ] + 1,
                                min(
                                    matrix[  i  ][j - 1] + 1,
                                    matrix[i - 1][j - 1] + \
                                        costOfReplacement(file1[i - 1], file2[j - 1])
                                )
            );
        }
    }


    return matrix[m][n];
}



#endif
