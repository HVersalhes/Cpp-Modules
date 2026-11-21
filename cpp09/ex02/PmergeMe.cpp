#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

bool PmergeMe::parseArguments(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg.empty())
			return false;
		for (size_t j = 0; j < arg.length(); j++) {
			if (!std::isdigit(arg[j]))
				return false;
		}
		char* endPtr = NULL;
		long val = std::strtol(arg.c_str(), &endPtr, 10);
		if (val <= 0 || val > INT_MAX || *endPtr != '\0')
			return false;
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
	return true;
}

std::vector<size_t> PmergeMe::_getJacobsthalIndices(size_t n) {
	std::vector<size_t> jacob;
	if (n <= 1)
		return jacob;

	std::vector<size_t> dp;
	dp.push_back(0);
	dp.push_back(1);
	while (dp.back() < n) {
		size_t next = dp.back() + 2 * dp[dp.size() - 2];
		dp.push_back(next);
	}

	std::vector<bool> visited(n + 1, false);
	for (size_t i = 3; i < dp.size(); i++) {
		size_t curr = dp[i];
		size_t prev = dp[i - 1];
		if (curr > n)
			curr = n;
		for (size_t j = curr; j > prev; j--) {
			if (!visited[j]) {
				jacob.push_back(j);
				visited[j] = true;
			}
		}
	}
	for (size_t j = 1; j <= n; j++) {
		if (!visited[j]) {
			jacob.push_back(j);
			visited[j] = true;
		}
	}
	return jacob;
}

void PmergeMe::_sortVector(std::vector<int>& v) {
	if (v.size() <= 1)
		return;

	bool hasStraggler = (v.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler) {
		straggler = v.back();
		v.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < v.size(); i += 2) {
		if (v[i] >= v[i + 1])
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
		else
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
	}

	std::vector<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);

	_sortVector(largerElements);

	std::vector<int> mainChain = largerElements;
	std::vector<int> pend(pairs.size());

	for (size_t i = 0; i < largerElements.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (largerElements[i] == pairs[j].first) {
				pend[i] = pairs[j].second;
				break;
			}
		}
	}

	mainChain.insert(mainChain.begin(), pend[0]);

	std::vector<size_t> order = _getJacobsthalIndices(pend.size());
	for (size_t i = 0; i < order.size(); i++) {
		size_t idx = order[i] - 1;
		if (idx == 0)
			continue;
		int val = pend[idx];
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(pos, val);
	}

	if (hasStraggler) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	v = mainChain;
}

void PmergeMe::_sortDeque(std::deque<int>& d) {
	if (d.size() <= 1)
		return;

	bool hasStraggler = (d.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler) {
		straggler = d.back();
		d.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < d.size(); i += 2) {
		if (d[i] >= d[i + 1])
			pairs.push_back(std::make_pair(d[i], d[i + 1]));
		else
			pairs.push_back(std::make_pair(d[i + 1], d[i]));
	}

	std::deque<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);

	_sortDeque(largerElements);

	std::deque<int> mainChain = largerElements;
	std::deque<int> pend(pairs.size());

	for (size_t i = 0; i < largerElements.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (largerElements[i] == pairs[j].first) {
				pend[i] = pairs[j].second;
				break;
			}
		}
	}

	mainChain.push_front(pend[0]);

	std::vector<size_t> order = _getJacobsthalIndices(pend.size());
	for (size_t i = 0; i < order.size(); i++) {
		size_t idx = order[i] - 1;
		if (idx == 0)
			continue;
		int val = pend[idx];
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(pos, val);
	}

	if (hasStraggler) {
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	d = mainChain;
}

void PmergeMe::execute() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i] << (i + 1 < _vec.size() ? " " : "");
	}
	std::cout << std::endl;

	// Sort vector and measure time
	std::clock_t startVec = std::clock();
	_sortVector(_vec);
	std::clock_t endVec = std::clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	// Sort deque and measure time
	std::clock_t startDeq = std::clock();
	_sortDeque(_deq);
	std::clock_t endDeq = std::clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i] << (i + 1 < _vec.size() ? " " : "");
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size() 
	          << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() 
	          << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
