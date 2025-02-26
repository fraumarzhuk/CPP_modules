#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>


template <typename T> 
class Array
{
	private:
		unsigned int _len;
		T *_arr;
	public:
	Array();
    Array(unsigned int len);
    Array(const Array<T> &other);
    Array& operator=(const Array<T>&);
	
    ~Array();
    T& operator[](int index);
	size_t size();
};


template <typename T>
T& Array<T>::operator[](int index)
{
	if (!_arr[index])
		throw std::exception();
    return _arr[index];
}

// template <typename T>
// std::ostream &operator<<(std::ostream& ostream, const Array<T> &arr) {
// 	for (size_t i = 0; i < arr.size(); ++i) {
// 		ostream << arr[i];
// 	}
// 	return ostream;
// }

// template <typename T>
// std::ostream &operator<<(std::ostream& ostream, const T &element) {
// 		ostream << element;
// 	return ostream;
// }


template <typename T>
Array<T>::Array(): _len(0)
{
	std::cout << "Array Constructor called" << std::endl;
	_arr = new T[_len];
}

template <typename T>
Array<T>::Array(unsigned int len): _len(len) {
	std::cout << "Array Constructor called" << std::endl;
	_arr = new T[len];
}

template <typename T>
Array<T>::Array(const Array<T> &other) {
	std::cout << " Array Copy constructor called" << std::endl;
	delete _arr;
	_arr = NULL;
	_arr = new T[other._len];
	for (unsigned int i = 0; i < other._len; i++) {
		_arr[_len] = other._arr[_len];
	}
}

template <typename T>
Array<T> &Array<T>::operator = (const Array<T> &other)
{
	std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (unsigned int i = 0; i < other._len; i++) {
			_arr[_len] = other._arr[_len];
		}
		_len = other._len;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << " Array Destructor called" << std::endl;
}

template <typename T>
size_t Array<T>::size() {
	return (_len);
}

#endif
