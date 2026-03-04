template<typename T>
class List {
private:

	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		/**
		@brief Конструктор узла списка.
		@param data значение, сохраняемое в узле.
		@param pNext указатель на следующий узел.
		*/
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		};

	};

	int size;
	Node<T>* head;

public:

	/**
	@brief Конструктор по умолчанию.
	Создаёт пустой список.
	*/
	List() {
		size = 0;
		head = nullptr;
	};

	/**
	@brief Деструктор списка.
	Освобождает всю динамически выделенную память.
	*/
	~List() {
		clear();
	};

	/**
	@brief Добавляет элемент в конец списка.
	@param data значение, добавляемое в список.
	*/
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

	void push_front(T data) {
		head = new Node<T>(data, head);
		size++;
	}

	/**
	@brief Удаляет первый элемент списка.
	Предполагается, что список не пуст.
	*/
	void pop_front() {

		Node<T>* temp = head;

		head = head->pNext;

		delete temp;

		size--;

	}

	/**
	@brief Ищет элемент в списке.
	@param value значение для поиска.
	@return Индекс найденного элемента или -1, если элемент не найден.
	*/
	int search(T value) {
		Node<T>* current = this->head;
		int index = 0;

		while (current != nullptr) {
			if (current->data == value) {
				return index;
			}
			current = current->pNext;
			index++;
		}

		return -1;
	}

	/**
	@brief Очищает список.
	Удаляет все элементы, размер становится равен нулю.
	*/
	void clear() {

		while (size) {
			pop_front();
		}

	}

	/**
	@brief Возвращает текущий размер списка.
	@return Количество элементов в списке.
	*/
	int get_size() {
		return size;
	}

	/**
	@brief Оператор доступа к элементу по индексу.
	@param index индекс элемента (начинается с 0).
	@return Ссылка на элемент с указанным индексом.
	*/
	T& operator [](const int index) {

		int counter = 0;                    // Счетчик для отслеживания текущей позиции
		Node<T>* current = this->head;      // Начинаем обход с головы списка

		// Проходим по всем узлам списка, пока не достигнем конца
		while (current != nullptr) {
			// Если текущий счетчик совпадает с искомым индексом
			if (counter == index) {
				return current->data;        // Возвращаем ссылку на данные узла
			}
			current = current->pNext;        // Переходим к следующему узлу
			counter++;                       // Увеличиваем счетчик позиции
		}

	};

};