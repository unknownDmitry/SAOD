#pragma once

/**
 * @brief Шаблонный двусвязный список.
 * @tparam T Тип элементов, хранимых в списке.
 */
template<typename T>
class DList {
private:
	/**
	 * @brief Узел двусвязного списка.
	 */
	template<typename T>
	class Node {
	public:
		Node* pNext;
		Node* pPrev;
		T data;

		/**
		 * @brief Конструктор узла.
		 * @param data значение, сохраняемое в узле.
		 * @param pNext указатель на следующий узел.
		 * @param pPrev указатель на предыдущий узел.
		 */
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	int size;
	Node<T>* head;
	Node<T>* tail;

public:

	/**
	 * @brief Конструктор по умолчанию. Создаёт пустой список.
	 */
	DList() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	/**
	 * @brief Деструктор. Очищает список.
	 */
	~DList() {
		clear();
	}

	/**
	 * @brief Возвращает текущий размер списка.
	 * @return Количество элементов в списке.
	 */
	int get_size() const {
		return size;
	}

	/**
	 * @brief Проверяет, пуст ли список.
	 * @return true, если список пуст, иначе false.
	 */
	bool empty() const {
		return size == 0;
	}

	/**
	 * @brief Добавляет элемент в конец списка.
	 * @param data значение, добавляемое в список.
	 */
	void push_back(T data) {
		if (tail == nullptr) {
			// список пуст
			head = tail = new Node<T>(data);
		}
		else {
			Node<T>* newNode = new Node<T>(data, nullptr, tail);
			tail->pNext = newNode;
			tail = newNode;
		}
		++size;
	}

	/**
	 * @brief Добавляет элемент в начало списка.
	 * @param data значение, добавляемое в список.
	 */
	void push_front(T data) {
		if (head == nullptr) {
			head = tail = new Node<T>(data);
		}
		else {
			Node<T>* newNode = new Node<T>(data, head, nullptr);
			head->pPrev = newNode;
			head = newNode;
		}
		++size;
	}

	/**
	 * @brief Удаляет первый элемент списка.
	 * 
	 * Предполагается, что список не пуст.
	 */
	void pop_front() {
		if (head == nullptr) return;

		Node<T>* temp = head;
		head = head->pNext;
		if (head != nullptr) {
			head->pPrev = nullptr;
		}
		else {
			// список стал пустым
			tail = nullptr;
		}

		delete temp;
		--size;
	}

	/**
	 * @brief Удаляет последний элемент списка.
	 * 
	 * Предполагается, что список не пуст.
	 */
	void pop_back() {
		if (tail == nullptr) return;

		Node<T>* temp = tail;
		tail = tail->pPrev;
		if (tail != nullptr) {
			tail->pNext = nullptr;
		}
		else {
			// список стал пустым
			head = nullptr;
		}

		delete temp;
		--size;
	}

	/**
	 * @brief Возвращает ссылку на первый элемент списка.
	 * @return Ссылка на данные первого узла.
	 */
	T& front() {
		return head->data;
	}

	/**
	 * @brief Возвращает ссылку на последний элемент списка.
	 * @return Ссылка на данные последнего узла.
	 */
	T& back() {
		return tail->data;
	}

	/**
	 * @brief Очищает список.
	 * Удаляет все элементы, размер становится равен нулю.
	 */
	void clear() {
		while (head != nullptr) {
			pop_front();
		}
	}
};

