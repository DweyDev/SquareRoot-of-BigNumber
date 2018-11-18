#pragma once


class DynamicVector {
private:
	int *vector;
	int capacity;
	int lenght;
	void doCapacity();
public:
	DynamicVector();
	DynamicVector(const DynamicVector &other);
	~DynamicVector();
	void resize(int newLenght);
	int getLenght();
	void pushBack(const int &e);
	void popBack();
	int &operator[](int position);
	DynamicVector &operator=(const DynamicVector &other);


};