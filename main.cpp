#include <iostream>
#include <string>
#include <vector>


#include "levenshtein_distance.hpp"

using namespace std;



int main()
{

    vector<string> file1;
    vector<string> file2;


    file1.push_back("first");
    file1.push_back("second");
    file1.push_back("third");

    file2.push_back("first");
    file2.push_back("sooqa");
    file2.push_back("second");
    file2.push_back("sooqa");
    file2.push_back("third");
    file2.push_back("sooqa");

    cout << levenshtein_distance(file1, file2, 3, 6) << endl;

    return 0;
}
