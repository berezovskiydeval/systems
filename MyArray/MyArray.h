#pragma once

template<class T>
class MyArray
{
public:
	MyArray();
	MyArray(size_t size);
	~MyArray();

	size_t getSize() { return size; }
	size_t getCapacity() { return capacity; }
	T& getAt(size_t index) { return data[index]; }
	void setAt(T value, size_t index) { data[index] = value; }
	bool isEmpty() { return size == 0; }
	T* getData() { return data; }
	size_t getUpperBound() { return capacity - 1; }
	void setCapacity(size_t capacity, size_t grow = 1);
	void add(T value);
	void removeAt(size_t index);
	void freeExtra() { capacity = size; }
	void insertAt(size_t index, T value);
	void append(const MyArray& other);
	void removeAll();

	T& operator[](int index) { return data[index]; }
	MyArray<T>& operator=(const MyArray& other);
private:
	T* data;
	size_t size;
	size_t capacity;
	size_t grow;
};

#include"MyArray_impl.h"
