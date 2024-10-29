
#pragma once

class Vector {

public:
	Vector();
	Vector(const size_t& size);
	Vector(const size_t& size,const int& value);

	Vector(const Vector& other);
	Vector& operator = (const Vector& other);

	const size_t& getSize()const { return this->size; }
	const size_t& getCapacity()const { return this->capacity; }
	void print()const;
	
	~Vector();

	int operator[](size_t index) const;
	int& operator[](size_t index);

	Vector operator()(size_t startIndex, size_t lastIndex) const;

	void pushBack(const int& value);

	Vector& operator +(const Vector& other) const;
	Vector& operator -(const Vector& other) const;
	Vector& operator *(const size_t& n) const;

	explicit operator int()const;
	explicit operator char* ()const;

	void pushFront(const int& value);
	void insert(const int& value, const size_t& index);
	void popBack();
	void popFront();

	void remove(const size_t& index);
	int find(const int& value) const;

private:
	int* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	bool isValidIndex(size_t index) const;
	void resize();

};
inline bool Vector::isValidIndex(size_t index) const
{
	return index < size;
}