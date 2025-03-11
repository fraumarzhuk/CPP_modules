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
return 0;

Span medium = Span(20);
medium.fillSpan(-1, 50);
medium.printSpan();
std::cout << "shortest span: " + sp.shortestSpan() << std::endl;
std::cout << "longest span: " + sp.longestSpan() << std::endl;


}