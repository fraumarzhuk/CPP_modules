#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl complainer;
	complainer.complain("debug");
	complainer.complain("info");
	complainer.complain("warning");
	complainer.complain("error");
	return (0);
}