#pragma once
template<typename T>
struct ITEM {
	T value;
	bool isRemoved = true;
};
template <typename T, int MAX>
class PQ2 {
private:
	int size; // number of non-removed ones
	ITEM<T> items[MAX];
public:
	PQ2() {
		size = 0;
	}

	bool empty() {
		if (size == 0)
			return true;
		return false;
	}

	T remove() {
		if (empty()) {
			cout << "Queue is empty!";
			exit(1);
		}
		int maxI; bool isInitialized = false;
		for (int i = 0; i < MAX; i++) {
			if (isInitialized == false && items[i].isRemoved == false) {
				maxI = i;
				isInitialized = true;
			}
			else if (items[i].isRemoved == false && items[i].value > items[maxI].value)
				maxI = i;
		}
		items[maxI].isRemoved = true;
		size--;
		return items[maxI].value;
	}

	bool insert(T x) {
		for (int i = 0; i < MAX; i++) {
			if (items[i].isRemoved == true) {
				items[i].value = x; items[i].isRemoved = false;
				size++;
				return true;
			}
		}
		cout << "Queue is full!";
		return false;
	}

	int Qlen() {
		return size;
	}

	T atFront() {
		if (empty()) {
			cout << "Queue is empty!";
			exit(1);
		}
		T max; bool isInitialized = false;
		for (int i = 0; i < MAX; i++) {
			if (isInitialized == false && items[i].isRemoved == false) {
				max = items[i].value;
				isInitialized = true;
			}
			else if (items[i].isRemoved == false && items[i].value > max)
				max = items[i].value;
		}
		return max;
	}
};
