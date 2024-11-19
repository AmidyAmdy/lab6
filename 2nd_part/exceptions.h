#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <string>
using namespace std;

class FileOpenException : public exception
{
private:
    string message;

public:
    explicit FileOpenException(const string &msg) : message(msg) {}

    virtual const char *what() const noexcept override
    {
        return message.c_str();
    }
};

#endif