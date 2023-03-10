#pragma once
// ќчередь с приоритетом
#include<iostream>
using namespace std;
template <typename T>
class MyQueuePriority
{
protected:
	int maxcounter = 0;
	int counter = 0;
	T* queue = nullptr;
	int* priority = nullptr;
public:
	explicit MyQueuePriority(int maxcounter) :maxcounter{ maxcounter } {
		queue = new T[maxcounter];
		priority = new int[maxcounter] {};
	}
	~MyQueuePriority() {
		if (queue != nullptr)
			delete[] queue;
		if (priority != nullptr)
			delete[] priority;
	}
	void push(T& val, int priority = 0) {
		if (counter < maxcounter) {
			queue[counter] = val;
			this->priority[counter++] = priority;

			int k = counter - 1;
			while ((k > 0) && (this->priority[k] > this->prioriti[k - 1])) {
				swap(queue[k], queue[k - 1]);
				swap(this->priority[k], this->priority[k - 1]);
				k--;
			}

		}
		else
			cout << "Error! Queue overflow\n";
	}
	void push(T&& val, int priority = 0) {
		if (counter < maxcounter) {
			queue[counter] = val;
			this->priority[counter++] = priority;

			int k = counter - 1;
			while ((k > 0) && (this->priority[k] > this->priority[k - 1])) {
				swap(queue[k], queue[k - 1]);
				swap(this->priority[k], this->priority[k - 1]);
				k--;
			}

		}
		else
			cout << "Error! Queue overflow\n";
	}
	T& top(int& priority) const {
		if (counter) {
			priority = this->priority[0];
			return queue[0];
		}
	}
	T& top() const {
		if (counter)
			return queue[0];
	}
	void pop() {
		if (counter) {
			for (int i = 0; i < counter - 1; ++i) {
				swap(queue[i], queue[i + 1]);
				swap(priority[i], priority[i + 1]);
			}
			--counter;
		}
	}
	bool isEmpty() const {
		return !counter;
	}
};


