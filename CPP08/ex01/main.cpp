#include "Span.hpp"
#include <iostream>


int main() {
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

Span medium = Span(10000);
medium.fillSpan(-520, 520);

medium.printSpan();
std::cout << "shortest span: " << medium.shortestSpan() << std::endl;
std::cout << "longest span: " << medium.longestSpan() << std::endl;

return 0;

}