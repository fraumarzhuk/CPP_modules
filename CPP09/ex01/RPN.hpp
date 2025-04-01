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
	//static std::stack<float> _stack;
	RPN();
	~RPN();

	RPN(const RPN &other);
	RPN &operator= (const RPN &other);
	static bool is_operator(char c);
	static bool is_operand(char c);
	static float do_operation(char op, int a, int b);
public:
	/*members*/
	static float process_expr(std::string input);
	static void error(std::string msg);
	static bool is_correct_input(std::string input);
};

#endif
