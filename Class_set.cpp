#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class set {
public:
	set(const vector<T>& a) : kontainer(a) {
		sort(kontainer.begin(), kontainer.end());
	}
	void insert(T value) {
		if (find(kontainer.begin(), kontainer.end(), value) == kontainer.end()) {
			kontainer.push_back(value);
			sort(kontainer.begin(), kontainer.end());
		}
	}
	void erase(T value) {
		if (find(kontainer.begin(), kontainer.end(), value) != kontainer.end()) {
			auto it = lower_bound(kontainer.begin(), kontainer.end(), value);
			if (it != kontainer.end() && *it == value) {
				kontainer.erase(it);
			}
		}
	}
	size_t size() {
		return kontainer.size();
	}
	bool empty() {
		if (kontainer.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool count(T value) {
		if (find(kontainer.begin(), kontainer.end(), value) == kontainer.end()) {
			return false;
		}
		else {
			return true;
		}
	}
	void print() {
		for (int elem : kontainer) {
			cout << elem << endl;
		}
	}
private:
	vector<T> kontainer;
};

int main() {
	set<int> a({ 10, 20, 30 });
	a.insert(40);
	a.erase(10);
	cout << a.size() << endl;
	cout << a.empty() << endl;
	cout << a.count(20) << endl;
	a.print();
}