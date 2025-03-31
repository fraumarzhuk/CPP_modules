#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include "colors.hpp"
#include <stack>
#include <cstring>
#include <string.h>

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIVIDE '/'
class RPN {
private:
	//std::string _input;
	std::stack<double> operands;
	RPN();
	~RPN();

	RPN(const RPN &other);
	RPN &operator= (const RPN &other);
	static bool is_operator(char c);
public:
	/*members*/
	static double process_expr(std::string input);
	static void error(std::string msg);
	static bool is_correct_input(std::string input);
};

#endif
