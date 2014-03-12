#ifndef INPUT_H
#define INPUT_H


#include <string>
#include <vector>


#include "input_exceptions.hpp"


void readFromFile(std::string filename, std::vector<std::string> &fileStrings);


#endif
