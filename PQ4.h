#pragma once

template <typename T, int MAX>
class PQ4 {
private:
	int rear;
	T items[MAX];
public:
	PQ4() {
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
		return items[rear--]; // first return items[rear] then rear = rear - 1
	}

	bool insert(T x) {
		if (rear == MAX - 1) { // note that the rear was initialized to 0
			cout << "Queue is full!";
			return false;
		}
		for (int i = 0; i <= rear; i++) {
			if (items[i] >= x) {
				for (int j = rear + 1; j > i; j--) {
					items[j] = items[j - 1];
				}
				items[i] = x;
				rear++;
				return true;
			}
		}
		// if x is greater than all of existing items
		items[++rear] = x;
		return true;
	}

	int Qlen() {
		return rear + 1; // note that the rear was initialized to 0
	}

	T atFront() {
		return items[rear];
	}
};
