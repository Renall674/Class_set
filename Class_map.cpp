#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

template <typename Key, typename Value>
class map {
public:
	map(initializer_list<pair<Key, Value>> a) : container(a) {
		sort(container.begin(), container.end(), [](const auto& a, const auto& b) {return a.first < b.first; });
	}

	void insert(const pair<Key, Value>& pair) {
		auto it = Lower_bound(pair.first);
		if (it == container.end() || it->first != pair.first) {
			container.insert(it, pair);
		}
	}

	Value* find(const Key& key) {
		auto it = Lower_bound(key);
		if (it != container.end() && it->first == key) {
			return &it->second;
		}
		return nullptr;
	}

	void erase(const Key& key) {
		auto it = Lower_bound(key);
		if (it != container.end() && it->first == key) {
			container.erase(it);
		}
	}

	bool contains(const Key& key) const {
		return find(key) != nullptr;
	}

	size_t size() const {
		return container.size();
	}
	bool empty() const {
		return container.empty();
	}
	void clear() { 
		container.clear(); 
	}

	auto begin() const { 
		return container.begin(); 
	}
	auto end() const { 
		return container.end(); 
	}
private:
	vector<pair<Key, Value>> container;
	auto Lower_bound(const Key& key) {
		return lower_bound(container.begin(), container.end(), key, [](const auto& pair, const Key& k) { return pair.first < k; });
	}
};

int main() {
	map<string, int> a = { {"Kolya", 20}, {"Rinat", 19} };
	a.insert({ "Renal", 21 });
	if (auto age = a.find("Renal")) {
		cout << "Renal is " << *age << " years old." << endl;
	}
	for (const auto& pair : a) {
		cout << pair.first << ": " << pair.second << endl;
	}
}