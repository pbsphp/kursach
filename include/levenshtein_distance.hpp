
#ifndef LEVENSHTEIN_DISTANCE_H
#define LEVENSHTEIN_DISTANCE_H


#include <vector>
#include <string>
#include <algorithm>
#include <cstring>


#include "config.h"


using namespace std;



void removeTabs(string &str);

int stringSimilarityPercent(string first, string second);

template <typename T>
int levenshteinDistance(T &file1, T &file2);

template <typename T>
inline int costOfReplacement(T first, T second);

inline bool areSimilar(string first, string second);

inline bool areSimilar(char first, char second);



void removeTabs(string &str)
{
    int c = 0;
    while (isspace(str[c]))
        ++c;

    str.erase(0, c);
}



int stringSimilarityPercent(string first, string second)
{
    removeTabs(first);
    removeTabs(second);

    float distance = levenshteinDistance(first, second);
    int k = first.length();
    int l = second.length();

    int difference = (distance / max(k, l)) * 100;

    return 100 - difference;
}



inline bool areSimilar(string first, string second)
{
    if (SIMILAR_STRINGS_EQUALITY)
        return (stringSimilarityPercent(first, second) >= PERCENT_OF_SIMILARITY);
    else
        return (first == second);
}



inline bool areSimilar(char first, char second)
{
    return (first == second);
}



template <typename T>
inline int costOfReplacement(T first, T second)
{
    if (areSimilar(first, second))
        return 0;
    else
        return 1;
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
            int cost = costOfReplacement(file1[i - 1], file2[j - 1]);

            matrix[i][j] = min(
                                    matrix[i - 1][  j  ] + 1,
                                min(
                                    matrix[  i  ][j - 1] + 1,
                                    matrix[i - 1][j - 1] + cost
                                )
                            );


            if (i > 1 && j > 1
                && areSimilar(file1[i - 1], file2[j - 2])
                && areSimilar(file1[i - 2], file2[j - 1])) {

                matrix[i][j] = min(
                    matrix[i][j],
                    matrix[i - 2][j - 2] + cost
                );
            }
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
