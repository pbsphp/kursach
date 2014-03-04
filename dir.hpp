
#ifndef DIR_H
#define DIR_H


#include <sys/stat.h>
#include <cstdlib>
#include <string>


#if __posix__ || __linux__
#include <dirent.h>
#elif _WIN32
#include "vendor/dirent.h"
#else
#error "Sosi, not supported"
#endif


// TODO: to separate file
// TODO: __unix__

#if __posix__ || __linux__
const char fileSeparator = '/';
#elif _WIN32
const char fileSeparator = '\\';
#else
#error "Sosi, not supported"
#endif



bool isDirectory(string path) {
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}



string joinPaths(string path, string postfix)
{
    char pathEnd = path[path.size() - 1];
    if (pathEnd == fileSeparator)
        path.erase(path.size() - 1, 1);

    char postfixBegin = postfix[postfix.size() - 1];
    if (postfixBegin == fileSeparator)
        postfix.erase(0, 1);

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
            // TODO: Throw exception
            std::cout << "Cant open " << path << std::endl;
        }
    }
    else {
        listOfFiles.push_back(path);
        // std::cout << "Compare with " << path << " " << isDirectory(path) << std::endl;
    }
}


#endif
