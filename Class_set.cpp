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
	size_t size() const {
		return kontainer.size();
	}
	bool empty() const {
		return kontainer.empty();
	}
	bool count(T value) const {
		return binary_search(kontainer.begin(), kontainer.end(), value);
	}
	void print() const {
		for (int elem : kontainer) {
			cout << elem << endl;
		}
	}
        auto begin() const { return kontainer.begin(); }
        auto end() const { return kontainer.end(); }
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
	//a.print();
	for (int b : a) {
		cout << b << endl;
	}
}
