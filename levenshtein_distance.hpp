
#ifndef LEVENSHTEIN_DISTANCE_H
#define LEVENSHTEIN_DISTANCE_H


#include <vector>
#include <string>
#include <algorithm>
#include <cstring>


#include "config.h"


using std::string;
using std::vector;
using std::min;
using std::max;



void removeWhitespaces(string &str);

int stringSimilarity(string first, string second);

template <typename T>
int levenshteinDistance(T &file1, T &file2);

inline int costOfReplacement(string first, string second);

inline int costOfReplacement(char first, char second);



void removeWhitespaces(string &str)
{
    int c = 0;
    while (isspace(str[c]))
        ++c;

    str.erase(0, c);
}



int stringSimilarity(string first, string second)
{
    removeWhitespaces(first);
    removeWhitespaces(second);

    float distance = levenshteinDistance(first, second);
    int k = first.length();
    int l = second.length();

    int difference = (distance / max(k, l)) * 100;

    return 100 - difference;
}



inline int costOfReplacement(string first, string second)
{
    if (SIMILAR_STRINGS_EQUALITY && \
        stringSimilarity(first, second) <= PERCENT_OF_SIMILARITY) {
        return 1;
    }
    else if ((!SIMILAR_STRINGS_EQUALITY) && first != second) {
        return 1;
    }
    else {
        return 0;
    }
}


inline int costOfReplacement(char first, char second)
{
    return (first != second) ? 1 : 0;
}



template <typename T>
int levenshteinDistance(T &file1, T &file2)
{
    const int m = file1.size();
    const int n = file2.size();


    int **matrix = new int *[m + 1];

    for (int i = 0; i <= m; ++i) {
        matrix[i] = new int [n + 1];
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


    int distance = matrix[m][n];
    for (int i = 0; i <= m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;


    return distance;
}


#endif
