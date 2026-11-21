#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>
# include <iostream>

template <typename T>
class Array {
private:
	T*           _data;
	unsigned int _size;

public:
	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Index out of bounds!";
		}
	};

	Array() : _data(NULL), _size(0) {}

	Array(unsigned int n) : _data(new T[n]()), _size(n) {}

	Array(const Array& other) : _data(NULL), _size(0) {
		*this = other;
	}

	Array& operator=(const Array& rhs) {
		if (this != &rhs) {
			if (this->_data)
				delete[] this->_data;
			this->_size = rhs._size;
			if (rhs._size > 0) {
				this->_data = new T[rhs._size]();
				for (unsigned int i = 0; i < rhs._size; ++i)
					this->_data[i] = rhs._data[i];
			} else {
				this->_data = NULL;
			}
		}
		return *this;
	}

	~Array() {
		if (_data)
			delete[] _data;
	}

	T& operator[](unsigned int index) {
		if (index >= _size || !_data)
			throw OutOfBoundsException();
		return _data[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= _size || !_data)
			throw OutOfBoundsException();
		return _data[index];
	}

	unsigned int size() const {
		return _size;
	}
};

#endif
