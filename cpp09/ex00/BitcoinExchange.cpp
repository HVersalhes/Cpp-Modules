#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
	loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs) {
		this->_database = rhs._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::_trim(const std::string& str) {
	size_t start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(" \t");
	return str.substr(start, end - start + 1);
}

bool BitcoinExchange::_isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::_isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2008 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && _isLeapYear(year))
		daysInMonth[1] = 29;

	return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::_isValidValue(const std::string& valStr, double& value) {
	if (valStr.empty())
		return false;

	char* endPtr = NULL;
	value = std::strtod(valStr.c_str(), &endPtr);
	if (endPtr == valStr.c_str() || *endPtr != '\0')
		return false;
	return true;
}

bool BitcoinExchange::loadDatabase(const std::string& dbPath) {
	std::ifstream file(dbPath.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file " << dbPath << std::endl;
		return false;
	}

	std::string line;
	// Skip header line (date,exchange_rate)
	if (std::getline(file, line)) {
		while (std::getline(file, line)) {
			size_t commaPos = line.find(',');
			if (commaPos != std::string::npos) {
				std::string date = _trim(line.substr(0, commaPos));
				std::string rateStr = _trim(line.substr(commaPos + 1));
				double rate = std::strtod(rateStr.c_str(), NULL);
				_database[date] = rate;
			}
		}
	}
	file.close();
	return true;
}

void BitcoinExchange::processInput(const std::string& inputPath) const {
	std::ifstream file(inputPath.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool isFirstLine = true;
	while (std::getline(file, line)) {
		std::string trimmedLine = _trim(line);
		if (trimmedLine.empty())
			continue;

		if (isFirstLine) {
			isFirstLine = false;
			if (trimmedLine == "date | value")
				continue;
		}

		size_t pipePos = trimmedLine.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << trimmedLine << std::endl;
			continue;
		}

		std::string date = _trim(trimmedLine.substr(0, pipePos));
		std::string valStr = _trim(trimmedLine.substr(pipePos + 1));

		if (!_isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value = 0.0;
		if (!_isValidValue(valStr, value)) {
			std::cout << "Error: bad input => " << valStr << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		if (_database.empty()) {
			std::cout << "Error: database is empty." << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
		if (it == _database.begin()) {
			std::cout << "Error: date before bitcoin inception => " << date << std::endl;
			continue;
		}
		--it;

		double result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	file.close();
}
