#pragma once

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
			head = tail = new Node<T>(data); // Создаем первый узел: он становится и головой (head), и хвостом (tail)
		}
		else {
			Node<T>* newNode = new Node<T>(data, nullptr, tail); // Создаем новый узел с данными, указателем на следующий (nullptr) и указателем на предыдущий (tail)
			tail->pNext = newNode;  // У старого хвоста указатель на следующий перенаправляем на новый узел
			tail = newNode;		  // Обновляем указатель на хвост - теперь новый узел становится последним
		}
		++size;
	}

	/**
	 * @brief Добавляет элемент в начало списка.
	 * @param data значение, добавляемое в список.
	 */
	void push_front(T data) {
		if (head == nullptr) {
			head = tail = new Node<T>(data); // Создаем первый узел: он становится и головой (head), и хвостом (tail)
		}
		else {
			Node<T>* newNode = new Node<T>(data, head, nullptr); // Создаем новый узел с данными, указателем на следующий (head) и указателем на предыдущий (nullptr)
			head->pPrev = newNode; // У старой головы указатель на предыдущий перенаправляем на новый узел
			head = newNode; // Обновляем указатель на голову - теперь новый узел становится первым
		}
		++size;
	}

	/**
	 * @brief Удаляет первый элемент списка.
	 * 
	 * Предполагается, что список не пуст.
	 */
	void pop_front() {
		if (head == nullptr) return; // Если список пуст (голова равна nullptr), выходим из функции

		Node<T>* temp = head;  // Сохраняем указатель на удаляемый узел (текущую голову) во временную переменную
		head = head->pNext;   // Перемещаем указатель головы на следующий элемент списка
		if (head != nullptr) { // Проверяем, не стал ли список пустым после удаления
			head->pPrev = nullptr; // Если список не пуст: у нового первого элемента обнуляем указатель на предыдущий
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
		if (tail == nullptr) return; // Если список пуст (хвост равен nullptr), выходим из функции

		Node<T>* temp = tail; // Сохраняем указатель на удаляемый узел (текущий хвост) во временную переменную
		tail = tail->pPrev;   // Перемещаем указатель хвоста на предыдущий элемент списка
		if (tail != nullptr) { // Проверяем, не стал ли список пустым после удаления
			tail->pNext = nullptr; // Если список не пуст: у нового последнего элемента обнуляем указатель на следующий
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

