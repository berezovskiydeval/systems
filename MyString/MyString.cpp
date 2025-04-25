#pragma once
#include "MyString.h"

unsigned MyString::string_counter = 0;

MyString::MyString() {
	lenght = 80;
	str = new char[lenght];
	++string_counter;
}

MyString::MyString(const char* string) {
	lenght = strlen(string);
	str = new char[lenght + 1];
	strcpy_s(str, lenght + 1, string);
	++string_counter;
}

MyString::MyString(size_t n, char c) {
	lenght = n;
	str = new char[lenght + 1];
	for (int i = 0; i < n; i++)
		str[i] = c;
	str[n] = '\0';
	++string_counter;
}

MyString::MyString(const MyString& other) {
	if (other.str) {
		str = new char[lenght + 1];
		strcpy_s(str, lenght + 1, other.str);
	}
	else {
		str = nullptr;
	}
	++string_counter;
}

MyString::~MyString() {
	delete[] str;
	--string_counter;
}

void MyString::input() {
	std::cout << "Enter a string: "; initString(str, lenght);
}

void MyString::output() {
	for (int i = 0; i < lenght; std::cout << str[i++]);
	std::cout << '\n';
}

bool MyString::MyStrStr(const char* str) {
	for (int i = 0; i < lenght; ++i) {
		if (this->str[i] == str[0]) {
			int counterI = i;
			int j = 0;
			for (; j < strlen(str); ++j) {
				if (this->str[counterI] != str[j]) { break; }
				++counterI;
			}
			if (j == strlen(str)) { return true; }
		}
	}
	return false;
}

int MyString::MyChr(const char value) {
	char* res = strchr(str, value);
	if (res != nullptr) { return res - str; }
	return -1;
}

void MyString::MyStrCat(const MyString& other) {
	char* temp = new char[lenght + 1];
	strcpy_s(temp, lenght + 1, str);
	delete[] str;

	str = new char[lenght + other.lenght + 1];
	strcpy_s(str, lenght + 1, temp);
	strcat_s(str, other.lenght + lenght + 1, other.str);

	this->lenght = strlen(str);
	delete[] temp;
}

void MyString::MyDelChr(const char c) {
	int index = MyChr(c);
	if (lenght != 0 && index != -1) {
		for (int i = index; i < lenght; ++i)
			str[i] = str[i + 1];
		lenght--;
	}
}

int MyString::MyStrCmp(const MyString& other) {
	if (lenght < other.lenght) return -1;
	if (lenght > other.lenght) return  1;
	return  0;
}

void MyString::MyStrcpy(const MyString& other)
{
	if (this != &other) {
		delete[] str;
		lenght = other.lenght;
		str = new char[lenght + 1];
		strcpy_s(str, lenght + 1, other.str);
	}

}

void MyString::setString(const char* string) {
	if (str != nullptr) { delete[] str; }
	lenght = strlen(string);
	str = new char[lenght + 1];
	strcpy_s(str, lenght + 1, string);
}

char MyString::operator[](int index) {
	if (index >= 0 && index < lenght)
		return str[index];
	return -1;
}

void initString(char*& str, int& size) {
	if (str != nullptr) {
		delete[] str;
	}

	int capacity = 10;
	str = new char[capacity + 1];
	int i = 0; char ch;

	while (std::cin.get(ch)) {
		if (ch == '\n') break;

		if (i + 1 == capacity) {
			capacity += 10;
			char* temp = new char[capacity + 1];
			strncpy_s(temp, capacity + 1, str, i);
			delete[] str;
			str = temp;
		}

		str[i++] = ch;
	}
	str[i] = '\0';
	size = i;
}