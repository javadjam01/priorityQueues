#pragma once

template <typename T, int MAX>
class PQ5 {
private:
	int rear;
	T items[MAX];
public:
	PQ5() {
		rear = -1;
	}

	bool empty() {
		if (rear == -1)
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
		for (int i = 0; i <= rear; i++) {
			if (items[i] > items[maxI]) {
				maxI = i;
				max = items[i];
			}
		}
		items[maxI] = items[rear];
		rear--;
		return max;
	}

	bool insert(T x) {
		if (rear == MAX - 1) {
			cout << "Queue is full!";
			return false;
		}
		items[++rear] = x;
		return true;
	}

	int Qlen() {
		return rear + 1;
	}

	T atFront() {
		if (empty()) {
			cout << "Queue is empty!";
			exit(1);
		}
		int maxI = 0;
		T max = items[maxI];
		for (int i = 0; i <= rear; i++) {
			if (items[i] > items[maxI]) {
				maxI = i;
				max = items[i];
			}
		}
		return max;
	}
};
