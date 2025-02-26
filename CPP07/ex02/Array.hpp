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
    T& operator[](unsigned int index);
	size_t size();
};


template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _len )
		throw std::exception();
    return _arr[index];
}

template <typename T>
Array<T>::Array(): _len(0)
{	_arr = NULL;
	std::cout << "Array Constructor called" << std::endl;

}

template <typename T>
Array<T>::Array(unsigned int len): _len(len) {
	_arr = NULL;
	if (len > 0){
		std::cout << "Array Constructor called" << std::endl;
		_arr = new T[len];
	}
}

template <typename T>
Array<T>::Array(const Array<T> &other): _len(other._len), _arr(NULL) {
	std::cout << " Array Copy constructor called" << std::endl;
	if (_len > 0) {
		if (_arr !=NULL)
			delete[] _arr;
		_arr = new T[_len];
		for (unsigned int i = 0; i < _len; i++) {
			_arr[i] = other._arr[i];
		}
	}
}
template <typename T>
Array<T> &Array<T>::operator = (const Array<T> &other)
{
	std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		if (_arr != NULL)
			delete[] _arr;
		_arr = new T[other._len];
		_len = other._len;
		for (unsigned int i = 0; i < other._len; i++) {
			_arr[i] = other._arr[i];
		}
		delete []other._arr;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (_arr)
		delete [] _arr; 
	std::cout << " Array Destructor called" << std::endl;
}

template <typename T>
size_t Array<T>::size() {
	return (_len);
}

#endif
