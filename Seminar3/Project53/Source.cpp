#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;
	srand(time(0));
	auto myrand = []() {
		return 1 + (rand() % 9999);
	};
	auto generator = [n, myrand]() {
		vector<int>ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = myrand();
		}
		return ans;
	};
	vector<int> x(n);
	x = generator();

	for (int i = 0; i < n; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;

	auto firstnum = [](int x) {
		int n1 = 0;
		while (x != 0) {
			n1 = x % 10;
			x /= 10;
		}
		return n1;
	};
	
	auto countest = [firstnum](vector<int>::iterator begin, vector<int>::iterator end) {
		map <int, int> counter;
		for (int i = 1; i < 10; i++) {
			counter[i] = count_if(begin, end, [firstnum, i](int x) {return firstnum(x) == i; });
		}
		int max = 0;
		int maxi = 0;
		for (map<int, int>::iterator it = counter.begin(); it != counter.end(); it++) {
			if (max < it->second) {
				maxi = it->first;
				max = it->second;
			}
		}
		return maxi;
	};
	cout << countest(x.begin(), x.end()) << endl;


	auto ex2 = [&x, countest, firstnum]() {
		int my_C = countest(x.begin(), x.end());
		for (vector<int>::iterator it = x.begin(); it != x.end(); it++) {
			if (firstnum(*it)==my_C) {
				cout << *it << ' ';
			}
		}
	};
	ex2();
}