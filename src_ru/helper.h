#ifndef HELPER_H
#define HELPER_H

#include <iostream>

typedef std::string wline;

//================================================================================
//help and error interface messages declare
void help();
void error();

class writer {
public:
    void show(void (*func)());
    ~writer() {}
};
//================================================================================

#endif // HELPER_H
