#ifndef INPUT_H
#define INPUT_H


#include <string>
#include <vector>


#include <stdexcept>
class InputError : public std::runtime_error
{
public:
    InputError() : std::runtime_error("InputError") {}
};



class NotCodeFileError : public std::runtime_error
{
public:
    NotCodeFileError() : std::runtime_error("NotCodeFileError") {}
};





bool hasEnding(std::string str, std::string ending);

bool isCodeFile(std::string filename);

bool isCodeString(std::string str);

void readFromFile(std::string filename, std::vector<std::string> &fileStrings);


#endif
