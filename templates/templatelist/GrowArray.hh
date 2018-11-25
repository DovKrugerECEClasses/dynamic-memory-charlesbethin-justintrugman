#pragma once

#include <iostream>

template<typename T>
class GrowArray {
private:
	int used;
	int capacity;
	T* data;
	void checkGrow() {
		if (used != capacity)
			return; // don't grow unless you have to
		T* old = data;

		//TODO: every time the list grows, double it!!!
		data = new T[2*used+1]; // calls T::T()
		for (int i = 0; i < used; i++)
			data[i] = old[i];
		capacity = capacity*2 + 1;

		delete[] old;
	}
public:
	GrowArray() : used(0), capacity(0), data(nullptr) { }
	GrowArray(int  initialCapacity) : used(0), capacity(initialCapacity), data(new T[capacity]) /*TODO: fix!*/ { }
	GrowArray(const GrowArray<T>& g) : used(g.used), capacity(g.capacity), data(new T[capacity]) {
		for (int i = 0; i < capacity; i++)
			data[i] = g[i];
	}
	~GrowArray() { delete[] data; }
	
	void addEnd(const T& v) {
		checkGrow();
		data[used] = v;
		used++;
	}

	T removeEnd() {
    	used--;
		return data[used];
	}

	T operator [](int i) const {
		return data[i];
	}

	T& operator [](int i) {
		return data[i];
	}

	GrowArray<T>& operator =(const GrowArray<T>& g) {
		GrowArray<T> copy(g);
		used = g.used;
		capacity = g.capacity;
		
		std::swap(data, copy.data);
		return *this;
	}

	friend std::ostream& operator <<(std::ostream& s, const GrowArray<T>& list) {
    for (int i = 0; i < list.used; i++)
			s << list[i] << ' ';
		return s;
	}
};
