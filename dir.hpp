
#ifndef DIR_H
#define DIR_H


#include <sys/stat.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>


using std::string;
using std::vector;
using std::cerr;
using std::endl;


#ifdef __unix__
#include <dirent.h>
const char fileSeparator = '/';
#elif _WIN32
#include "vendor/dirent.h"
const char fileSeparator = '\\';
#else
#error This OS is not supported
#endif



bool isDirectory(string path)
{
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}



string joinPaths(string path, string postfix)
{
    if (path.at(-1) == fileSeparator)
        path.erase(path.end() - 1);

    if (postfix.at(0) == fileSeparator)
        postfix.erase(postfix.begin());

    return path + fileSeparator + postfix;
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


#endif
