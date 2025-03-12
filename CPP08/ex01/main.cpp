#include "Span.hpp"
#include <iostream>
#include "colors.hpp"

int main() {
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

Span medium = Span(100);
medium.fillSpan(-520, 520);

medium.printSpan();
std::cout << BG_LIME300 PINK500 << "Normal Span: " << RESET << std::endl;
std::cout << "shortest span: " << medium.shortestSpan() << std::endl;
std::cout << "longest span: " << medium.longestSpan() << std::endl;

Span empty = Span(0);
try {
	std::cout << BG_LIME300 PINK500 << "Empty Span: " << RESET << std::endl;
	std::cout << "shortest span: " << empty.shortestSpan() << std::endl;
	std::cout << "longest span: " << empty.longestSpan() << std::endl;
} catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
}
Span empty2 = Span(2);
try {
	std::cout << BG_LIME300 PINK500 << "Span with 1 number: " << RESET << std::endl;
	std::cout << "shortest span: " << empty2.shortestSpan() << std::endl;
	std::cout << "longest span: " << empty2.longestSpan() << std::endl;
} catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
}
return 0;

}