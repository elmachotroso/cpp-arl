/// test.cpp
/// me@andreivictor.net
/// This is meant as a test case file.

#include <iostream>
#include <stdio.h>
#include "ARL.hpp"

bool Test();

int main(int argc, char * argv[])
{
    std::cout << "C++ cout sucks!" << std::endl;
    printf("C printf is still better! %s", "true");

    return Test() ? 0 : 1;
}

bool Test()
{
    ARL::Object * root = new ARL::Object();
    if(root == nullptr)
    {
        printf("Test failed: root is null!");
        return false;
    }
    SAFEDELETE(root);
    if(root != nullptr)
    {
        printf("Test failed: root is not null!");
        return false;
    }

    printf("Test finished!");
    return true;
}