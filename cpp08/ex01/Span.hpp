#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <climits>

class Span {
private:
	unsigned int     _maxSize;
	std::vector<int> _numbers;

public:
	class FullSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& rhs);
	~Span();

	void addNumber(int number);

	template <typename InputIterator>
	void addRange(InputIterator begin, InputIterator end) {
		for (InputIterator it = begin; it != end; ++it) {
			if (_numbers.size() >= _maxSize)
				throw FullSpanException();
			_numbers.push_back(*it);
		}
	}

	int shortestSpan() const;
	int longestSpan() const;
};

#endif
