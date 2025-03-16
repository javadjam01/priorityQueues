#pragma once
/*template <typename T>
struct ITEM {
	T value;
	bool isRemoved = true;
};*/
template <typename T, int MAX>
class PQ3 {
private:
	int rear; // the index to insert
	int size; // number of non-removed ones
	ITEM<T> items[MAX];
public:
	PQ3() {
		size = 0;
		rear = -1;
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
		for (int i = 0; i <= rear; i++) {
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
		if (rear == MAX - 1) {
			if (size == MAX) { // it is really full
				cout << "Queue is full";
				return false;
			}
			else { // it is not really full
				if (items[rear].isRemoved == true) { // check if we have empty space at the rear
					items[rear].value = x;
					items[rear].isRemoved = false;
					size++;
					return true;
				}
				else {
					for (int i = 0; i < rear; i++) { // compressing
						if (items[i].isRemoved == true) {
							items[i].value = items[rear].value;
							items[i].isRemoved = false;
							items[rear].isRemoved = true;
							rear--;
						}
					} 
					// inserting
					rear++;
					items[rear].value = x;
					items[rear].isRemoved = false;
					size++;
					return true;
				}
			}
		}
		else {
			rear++;
			items[rear].value = x;
			items[rear].isRemoved = false;
			size++;
			return true;
		}
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
		for (int i = 0; i <= rear; i++) {
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
