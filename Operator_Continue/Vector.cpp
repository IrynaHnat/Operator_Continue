#include "Vector.h"
#include<iostream>
#include<string>
using namespace std;

using std::cout;
using std::endl;
using std::swap;

Vector::Vector()
	:Vector(1)
{
}

Vector::Vector(const size_t& size)
	:size(size),capacity(size)
{
	this->arr = new int [this->size] {};
}

Vector::Vector(const size_t& size, const int& value)
	:Vector(size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = value;

	}
}

Vector::Vector(const Vector& other)
	:Vector(other.size)
{
	for (size_t i = 0; i <this->size; i++)
	{
		arr[i] = other.arr[i];

	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = other.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
	return*this;
}

void Vector::print() const
{
	cout << " Array has size ==> " << size << "; capacity ==> " <<capacity << "\n\t";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

Vector::~Vector()
{
	if (arr != nullptr)
		delete[]arr;
}

int Vector::operator[](size_t index) const
{
	if (isValidIndex(index))
		return arr[index];
	cout << ">>>>>>>>>>> Error index (get) : " << index << endl;
	return INT_MIN;
}

int& Vector::operator[](size_t index)
{
	static int errVal;
	if (isValidIndex(index))
		return arr[index];
	cout << ">>>>>>>>>>> Error index (set) : " << index << endl;
	return errVal;

}

Vector Vector::operator()(size_t startIndex, size_t lastIndex) const
{
	if (startIndex > lastIndex)
		swap(startIndex, lastIndex);
	if (!isValidIndex(startIndex))
		return Vector(0);
	if (lastIndex >= size)
		lastIndex = size - 1;
	Vector tmp(lastIndex - startIndex + 1);
	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp[i] = this->arr[i + startIndex];
	}
	return tmp;

}

void Vector::pushBack(const int& value)
{
	if (size >= capacity)
		resize();
	arr[size++] = value;

}

Vector& Vector::operator+(const Vector& other) const
{
	Vector result(this->size + other.size);
	for (size_t i = 0; i < this->size; ++i) {
		result.arr[i] = this->arr[i];
	}
	for (size_t i = 0; i < other.size; ++i) {
		result.arr[i + this->size] = other.arr[i];
	}
	result.size = this->size + other.size;
	return result;
}

Vector& Vector::operator-(const Vector& other) const
{
	Vector result;
	for (size_t i = 0; i < this->size; ++i) {
		bool isUnique = true;
		for (size_t j = 0; j < other.size; ++j) {
			if (this->arr[i] == other.arr[j]) {
				isUnique = false;
				break;
			}
		}
		if (isUnique) {
			result.pushBack(this->arr[i]);
		}
	}
	return result;
}

Vector& Vector::operator*(const size_t& n) const
{
	Vector result(this->size);
	for (size_t i = 0; i < this->size; ++i) {
		result.arr[i] = this->arr[i] * n;
	}
	result.size = this->size;
	return result;
}

Vector::operator int() const
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}return sum;
}

Vector::operator char* () const
{
	if (size == 0) {
		char* emptyStr = new char[1];
		emptyStr[0] = '\0';
		return emptyStr;
	}

	string result;
	for (size_t i = 0; i < size; ++i) {
		result += to_string(arr[i]);
		if (i < size - 1) {
			result += " ";
		}
	}

	char* cstr = new char[result.size() + 1];
	strcpy_s(cstr, result.size() + 1, result.c_str()); 
	return cstr;
}


void Vector::pushFront(const int& value)
{
	if (size >= capacity) resize();
	for (size_t i = size; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
	arr[0] = value;
	++size;
}

void Vector::insert(const int& value, const size_t& index)
{
	if (index > size) return;  
	if (size >= capacity) resize();
	for (size_t i = size; i > index; --i) {
		arr[i] = arr[i - 1];
	}
	arr[index] = value;
	++size;
}

void Vector::popBack()
{
	if (size > 0) {
		arr[size - 1] = 0;
		--size;
	}
}

void Vector::popFront()
{
	if (size == 0) {
		cout << "Vector is empty, cannot pop front." <<endl;
		return;
	}
	for (size_t i = 0; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = 0;
	--size;
}

void Vector::remove(const size_t& index)
{
	if (!isValidIndex(index)) {
		cout << ">>>>>>>>>>> Error index (remove) : " << index << endl;
		return;
	}
	for (size_t i = index; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = 0; 
	--size;
}

int Vector::find(const int& value) const
{
	for (size_t i = 0; i < size; ++i) {
		if (arr[i] == value) {
			return i; 
		}
	}
	return -1;
}

void Vector::resize()
{
	this->capacity *= 2;
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i];
	}delete[]arr;
	arr = tmp;
}
