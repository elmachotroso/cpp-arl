/// test.cpp
/// me@andreivictor.net
/// This is meant as a test case file.

#include <iostream>
#include <chrono>
#include "ARL.hpp"

bool Test();

int main(int argc, char * argv[])
{
	bool result = Test();
	
	char a;
	std::cin >> a;

    return result ? 0 : 1;
}

bool Test()
{
	auto start = std::chrono::steady_clock::now();

    ARL::Object * root = new ARL::Object(nullptr, string("margarita"));
    if(root == nullptr)
    {
        std::cout << "Test failed: root is null!\n";
        return false;
    }
#ifdef DEBUG_VERBOSE
	std::cout << root->ToString() << std::endl;
#endif //DEBUG_VERBOSE
	
    SAFEDELETE(root);
    if(root != nullptr)
    {
		std::cout << "Test failed: root is not null!\n";
        return false;
    }
	auto end = std::chrono::steady_clock::now();
	auto deltaTime = end - start;
	int64_t seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime).count();
	std::cout << "Test finished in " << seconds << "ns\n";
    return true;
}