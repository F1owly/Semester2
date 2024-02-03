#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct comp {
	template <typename T>

	bool operator()(T a, T b) {
		return a.length() > b.length();
	}
};

int main() {
	int n;
	cin >> n;
	vector<string> s, s0;
	string b;
	for (int i = 0; i < n; i++) {
		cin >> b;
		s0.push_back(b);
	};
	s = s0;

	//std::sort
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	};
	cout << endl;
	s = s0;

	//функтор
	sort(s.begin(), s.end(), comp());
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	};
	cout << endl;
	s = s0;

	//лямбда-функция
	sort(s.begin(), s.end(), [](string s1, string s2) {return s1.length() > s2.length(); });
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	};
	return 0;
}