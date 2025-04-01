#include "RPN.hpp"

RPN::RPN() {
	//std::cout << "RPN Constructor called" << std::endl;
}

RPN::RPN(const RPN &other) {
	//std::cout << " RPN Copy constructor called" << std::endl;
	*this = other;
}

RPN &RPN::operator = (const RPN &other) {
	//std::cout << "RPN Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}


bool RPN::is_operator(char c) {
	return (c == PLUS || c == MINUS || c == DIVIDE || c== MULT);
}

bool RPN::is_operand(char c) {
	return (c >= '0' && c <= '9');
}

float RPN::process_expr(std::string input) {
	int a, b;
	std::string::iterator it;
	std::stack<float> _stack;

	std::cout << "STRING: " << input << std::endl;
	for (it = input.begin(); it != input.end(); it++) {
		// std::cout << "operator: " << *it << std::endl;
		if (is_operator(*it)) {
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(do_operation(a, b, *it));
		}
		else {
			_stack.push(*it - '0');
		}
	}
	return _stack.top();
}

void RPN::error(std::string msg) {
	std::cout << PINK400 << msg << RESET << std::endl;
}

bool RPN::is_correct_input(std::string input) {
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length() - 1; i++) {
		if (!isdigit(input[i]) && !is_operator(input[i]) && !isspace(input[i])) {
			std::cout << "char " << input[i] << " .";
			RPN::error("incorrect char provided");
			return false;
		}
		if ((i % 2 != 0) && !isspace(input[i])) {
			std::cout << "char " << input[i] << " .";
			RPN::error("values should be separated by spaces.");
			return false; 
		}
	}
	return true;
}

float RPN::do_operation(char op, int a, int b) {
	std::cout << "operator: " << op << std::endl;
	switch (op) {
		case PLUS:
			return b + a;
		case MINUS:
			return b - a;
		case MULT:
			return b * a;
		case DIVIDE:
			return b / a;
		default:
			RPN::error("invalid operator");
	}
	return 0;
}


RPN::~RPN() {
	std::cout << " RPN Destructor called" << std::endl;
}
