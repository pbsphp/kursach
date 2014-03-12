#ifndef DIR_H
#define DIR_H

#include <string>
#include <vector>


bool isDirectory(std::string path);

std::string joinPaths(std::string path, std::string postfix);

void readDirectory(std::vector<std::string> &listOfFiles, std::string path);


#endif
