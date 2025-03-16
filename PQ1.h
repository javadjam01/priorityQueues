#pragma once

template <typename T, int MAX>
class PQ1 {
private:
	int size;
	T items[MAX];
public:
	PQ1() {
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
		int maxI = 0;
		T max = items[maxI];
		for (int i = 0; i < size; i++) {
			if (items[i] > items[maxI]) {
				maxI = i;
				max = items[i];
			}
		}
		for (int i = maxI; i < size - 1; i++) //shifting
			items[i] = items[i + 1];
		size--;
		return max;
	}

	bool insert(T x) {
		if (size == MAX) {
			cout << "Queue is full!";
			return false;
		}
		items[size++] = x;
		return true;
	}

	int Qlen() {
		return size;
	}

	T atFront() {
		if (empty()) {
			cout << "Queue is empty!";
			exit(1);
		}
		int maxI = 0;
		T max = items[maxI];
		for (int i = 0; i < size; i++) {
			if (items[i] > items[maxI]) {
				maxI = i;
				max = items[i];
			}
		}
		return max;
	}
};
