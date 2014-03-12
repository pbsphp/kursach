#include <sys/stat.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>


using namespace std;


#if defined(__unix__)
# include <dirent.h>
# define FILE_SEPARATOR '/'
#elif defined(_WIN32)
# include "vendor/dirent.h"
# define FILE_SEPARATOR '\\'
#else
# error "This OS is not supported"
#endif



bool isDirectory(string path)
{
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}



string joinPaths(string path, string postfix)
{
    if (path[path.size() - 1] == FILE_SEPARATOR)
        path.erase(path.end() - 1);

    if (postfix[0] == FILE_SEPARATOR)
        postfix.erase(postfix.begin());

    return path + FILE_SEPARATOR + postfix;
}



void readDirectory(vector<string> &listOfFiles, string path)
{
    if (isDirectory(path)) {
        DIR *directory;
        struct dirent *ent;

        if ((directory = opendir(path.c_str())) != NULL) {
            while ((ent = readdir(directory)) != NULL) {
                string item = ent->d_name;
                if (item[0] != '.') {
                    string fullItemPath = joinPaths(path, item);
                    readDirectory(listOfFiles, fullItemPath);
                }
            }
            closedir(directory);
        }
        else {
            cerr << "Can't open " << path << endl;
        }
    }
    else {
        listOfFiles.push_back(path);
    }
}
