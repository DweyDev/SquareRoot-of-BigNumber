#include "DynamicVector.h"

using namespace std;

DynamicVector::DynamicVector() {
		
	this->capacity = 5;
	this->lenght = 0;
	this->vector = new int[this->capacity];

}


DynamicVector::DynamicVector(const DynamicVector &other) {
	
	this->capacity = other.capacity;
	this->lenght = other.lenght;
	this->vector = new int[this->capacity];
	int i;
	for ( i = 0; i < this->lenght; ++i) {
		this->vector[i] = other.vector[i];
	}

}

void DynamicVector::doCapacity() {
	
	if (lenght == capacity) {
		capacity *= 2;
		int *newVector = new int[capacity];
		int i;
		for (i = 0; i < lenght; ++i) {
			newVector[i] = vector[i];
		}
		delete[] vector;
		vector = newVector;
	}
}


void DynamicVector::resize(int newLenght) {

	int *temp = new int[newLenght];
	int i;
	//copy(this->vector, this->vector + this->lenght, temp);
	for ( i = 0; i < this->lenght; ++i) {
		temp[i] = vector[i];
	}
	delete[] vector;
	this->vector = temp;


}

void DynamicVector::pushBack(const int &e) {

	doCapacity();
	this->vector[this->lenght++] = e;
}

void DynamicVector::popBack() {


	// aici s-ar putea sa trebuiasca doCapacity()
	int *temp = new int[lenght - 1];
	int i;
	for ( i = 0; i < this->lenght-1; ++i) {
		temp[i] = vector[i];
	}
	delete[] vector;
	this->vector = temp;


}
int DynamicVector::getLenght() {

	return lenght;
}

DynamicVector::~DynamicVector() {

	delete[] vector;
}

int &DynamicVector::operator[](int position) {
	
	return this->vector[position];
}

DynamicVector &DynamicVector::operator=(const DynamicVector &other) {

	if (this != &other) {

		delete[] this->vector;
		this->capacity = other.capacity;
		this->lenght = other.lenght;
		this->vector = new int[this->capacity];
		for (int i = 0; i < this->lenght; ++i) {
			this->vector[i] = other.vector[i];
		}
	}


	return *this;
}