#ifndef INPUT_EXCEPTIONS_H
#define INPUT_EXCEPTIONS_H


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


#endif
