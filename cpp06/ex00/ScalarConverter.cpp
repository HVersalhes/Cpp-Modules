#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	// Handle single char literal (not a digit)
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}

	// Handle pseudo-literals
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}

	char* endPtr = NULL;
	double val = std::strtod(literal.c_str(), &endPtr);

	// Check if string had a valid conversion or unexpected chars (except trailing 'f')
	if (endPtr == literal.c_str() || (*endPtr != '\0' && !(*endPtr == 'f' && *(endPtr + 1) == '\0'))) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// 1. char conversion
	std::cout << "char: ";
	if (val < 0 || val > 127 || std::isnan(val)) {
		std::cout << "impossible" << std::endl;
	} else if (!std::isprint(static_cast<int>(val))) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
	}

	// 2. int conversion
	std::cout << "int: ";
	if (val < INT_MIN || val > INT_MAX || std::isnan(val)) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(val) << std::endl;
	}

	// 3. float conversion
	std::cout << "float: ";
	float fVal = static_cast<float>(val);
	if (std::floor(val) == val && val >= -1000000 && val <= 1000000) {
		std::cout << fVal << ".0f" << std::endl;
	} else {
		std::cout << fVal << "f" << std::endl;
	}

	// 4. double conversion
	std::cout << "double: ";
	if (std::floor(val) == val && val >= -1000000 && val <= 1000000) {
		std::cout << val << ".0" << std::endl;
	} else {
		std::cout << val << std::endl;
	}
}
