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
    printf("C printf is still better! %s\n", "true");

	bool result = Test();
	
	char a;
	std::cin >> a;

    return result ? 0 : 1;
}

bool Test()
{
    ARL::Object * root = new ARL::Object(nullptr, string("margarita"));
    if(root == nullptr)
    {
        printf("Test failed: root is null!\n");
        return false;
    }
	printf("The name of the root object is: %s\n", root->GetName().c_str());
    SAFEDELETE(root);
    if(root != nullptr)
    {
        printf("Test failed: root is not null!\n");
        return false;
    }

    printf("Test finished!\n");
    return true;
}