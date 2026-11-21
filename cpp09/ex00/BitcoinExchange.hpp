#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>

class BitcoinExchange {
private:
	std::map<std::string, double> _database;

	static bool        _isValidDate(const std::string& date);
	static bool        _isLeapYear(int year);
	static bool        _isValidValue(const std::string& valStr, double& value);
	static std::string _trim(const std::string& str);

public:
	BitcoinExchange();
	BitcoinExchange(const std::string& dbPath);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();

	bool loadDatabase(const std::string& dbPath);
	void processInput(const std::string& inputPath) const;
};

#endif
