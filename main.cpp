#include <iostream>
#include <string>
#include <vector>
#include <cstring>


#include "text_overlap.hpp"
#include "dir.hpp"


using namespace std;





int main(int argc, char *argv[])
{
    if (argc > 2) {

        string fileForComparison = argv[1];

        vector<string> filenamesList;

        for (int i = 2; i < argc; ++i) {
            readDirectory(filenamesList, argv[i]);
        }

        for (int i = 0; i < filenamesList.size(); ++i) {
            int diff = text_overlap(fileForComparison, filenamesList[i]);
            cout << "Compare with " << filenamesList[i] << " : " \
                << diff << "%" << endl;
        }

    }
    else {
        // TODO: Pretty error messsage and exit(1)
        cout << "No files" << endl;
    }


    return 0;
}
