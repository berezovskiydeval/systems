#pragma once
#include"MyArray.h"

template<class T>
inline MyArray<T>::MyArray() : data(nullptr), size(0), grow(1), capacity(0) { }

template<class T>
inline MyArray<T>::MyArray(size_t size)
	: size(size), data(new T[size + 1]), grow(1), capacity(size + 1) { }

template<class T>
inline MyArray<T>::~MyArray() {
	for (size_t i = 0; i < size; ++i) {
		data[i].~T();
	}
	delete[] data;
}

template<class T>
inline void MyArray<T>::setCapacity(size_t capacity, size_t grow) {
	if (capacity < this->size) {
		removeAt(capacity);
		this->capacity = capacity;
	}
	else {
		T* temp = new T[capacity];
		for (int i = 0; i < this->size; ++i) {
			temp[i] = this->data[i];
		}
		delete[] this->data;
		this->data = temp;
		this->grow = grow;
		this->capacity = capacity;
	}
}

template<class T>
inline void MyArray<T>::add(T value) {
	if (capacity == size) {
		size_t newSize = size + grow;
		T* temp = new T[newSize];
		for (int i = 0; i < this->size; ++i) {
			temp[i] = this->data[i];
		}
		temp[size] = value;
		delete[] this->data;
		this->data = temp;
		size++;
		capacity = newSize;
	}
	else {
		data[size] = value;
		size++;
	}
}

template<class T>
inline void MyArray<T>::removeAt(size_t index) {
	if (index >= size) return;
	for (size_t i = index; i < size; ++i) {
		data[i].~T();
	}
	size = index;
}

template<class T>
inline void MyArray<T>::insertAt(size_t index, T value) {
	if (size == capacity) {
		setCapacity(capacity + grow, grow);
	}
	for (int i = size; i >= index; --i) {
		data[i] = data[i - 1];
	}
	data[index] = value;
	size++;
}

template<class T>
inline void MyArray<T>::append(const MyArray& other) {
	for (size_t i = 0; i < other.size; ++i) {
		this->add(other.data[i]);
	}
}

template<class T>
inline void MyArray<T>::removeAll() {
	for (size_t i = 0; i < size; ++i) {
		data[i].~T();
	}
	delete[] data;
	size = 0;
	capacity = 0;
}

template<class T>
inline MyArray<T>& MyArray<T>::operator=(const MyArray& other) {
	if (this != &other) {
		delete[] data;

		data = new T[other.capacity];
		for (size_t i = 0; i < other.size; ++i) {
			this->data[i] = other.data[i];
		}
		size = other.size;
		capacity = other.capacity;

	}
	return *this;
}
