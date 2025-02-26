//#include "Array.hpp"

// int main() {
// 	Array<int>  *a = new Array<int>();	
// 	std::cout << a << std::endl;
// 	// Array<int>  *b = new Array<int>(3);
// 	// (*b)[1] = 42;
// 	// // int test = static_cast<int>((*b)[1]);
// 	// std::cout << "Value of b[1]: " << (*b)[1] << std::endl;
// 	delete a;
// 	return 0;
// }

#include <iostream>
#include "Array.hpp"
#include <stdlib.h>  
#include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	Array<int> empty(0);
	std::cout << "Memory address of an empty array: " << &empty << std::endl;
    return 0;
}