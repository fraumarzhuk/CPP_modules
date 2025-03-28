#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include "colors.hpp"
#include <stack>

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIVIDE '/'
class RPN {
private:
	std::string _input;
	std::stack<int> operands;
	RPN();
	~RPN();

	RPN(const RPN &other);
	RPN &operator= (const RPN &other);
	static void error(std::string msg);
public:
	/*members*/
	static unsigned long long evaluate();
};

#endif
