//Савин Дмитрий, ИВТ-22

#include <iostream>

template<typename T>
class List {
private:

	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		};

	};

	int size;
	Node<T> *head;

public:

	List() {
		size = 0;
		head = nullptr;
	};

	~List() {

	};

	void push_back(T data) {

		if (head == nullptr) {
			head = new Node<T>(data);
		}
		else {
			Node<T>* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}

		size++;

	}

	void pop_front() {

		Node<T> *temp = head;

		head = head->pNext;

		delete temp;

		size--;

	}

	void clear() {

		while (size) {
			pop_front();
		}

	}

	int get_size() {
		return size;
	}

	T& operator [](const int index) {

		int counter = 0;
		Node<T>* current = this->head;

		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pNext;
			counter++;
		}

	};

};

int main() {

	List<int> a;
	a.push_back(5);
	a.push_back(10);
	a.push_back(22);

	for (int i = 0; i < a.get_size(); i++) {
		std::cout << a[i] << std::endl;
	}
	
	std::cout << std::endl;

	a.pop_front();

	for (int i = 0; i < a.get_size(); i++) {
		std::cout << a[i] << std::endl;
	}

	return 0;
}