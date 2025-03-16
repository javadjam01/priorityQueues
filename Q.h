#pragma once

template <typename T, int MAX>
class Q {
private:
	int front, rear;
	T items[MAX + 1];
public:
	Q() {
		front = rear = MAX;
	}

	bool empty() {
		if (front == rear)
			return true;
		return false;
	}

	T remove() {
		if (empty()) {
			cout << "Queue is empty!\n";
			exit(1);
		}
		if (front == MAX)
			front = 0;
		else
			front++;
		return items[front];
	}

	bool insert(T x) {
		int t = rear;
		if (t == MAX)
			t = 0;
		else
			t++;
		if (t == front) {
			cout << "queue is full";
			return false;
		}
		rear = t;
		items[rear] = x;
		return true;
	}
};
