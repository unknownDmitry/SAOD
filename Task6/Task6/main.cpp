//Савин Дмитрий, ИВТ-22

#include <iostream>

template<typename T>
class VECTOR {

private:

	T* data;
	size_t size;
	size_t capacity;

	void resize(size_t new_capacity) {
		T* new_data = new T[new_capacity];
		for (size_t i = 0; i < size; i++) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}

public:

	VECTOR() {
		this->data = nullptr;
		this->size = 0;
		this->capacity = 0;
	};

	~VECTOR() {
		delete[] data;
	}

	void push_back(const T& value){
		if(size == capacity){
			size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
			resize(new_capacity);
		}
		data[size] = value;
		size++;
	}

	void pop_back(){
		if(size > 0){
			size--;
		}
	}

};

int main() {



	return 0;
}