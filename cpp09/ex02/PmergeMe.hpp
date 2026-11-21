#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <climits>
# include <algorithm>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::deque<int>  _deq;

	static void _sortVector(std::vector<int>& v);
	static void _sortDeque(std::deque<int>& d);
	static std::vector<size_t> _getJacobsthalIndices(size_t n);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& rhs);
	~PmergeMe();

	bool parseArguments(int argc, char** argv);
	void execute();
};

#endif
