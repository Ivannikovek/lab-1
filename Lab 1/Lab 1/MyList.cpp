#include "MyList.h"

MyList::MyList() :head(nullptr), tail(nullptr), size(0u) {}

MyList::MyList(const MyList& from) : size(from.size) {
	if (size != 0u) {
		//head coping
		head = new elem(from.head->value);

		elem* last_added = head;
		elem* current = from.head->next;

		//all other elements coping
		while (current != nullptr) {
			last_added->next = new elem(current->value);
			last_added = last_added->next;

			current = current->next;
		}

		tail = last_added;
	}
	else
		head = tail = nullptr;
}

MyList::~MyList() {
	clear();
}

void MyList::push_back(const int value) {
	if (size == 0u)
		head = tail = new elem(value);
	else {
		tail->next = new elem(value);
		tail = tail->next;
	}

	size++;
}

void MyList::push_front(const int value) {
	if (size == 0u)
		head = tail = new elem(value);
	else
		head = new elem(value, head);

	size++;
}

void MyList::pop_back() {
	if (size == 0u)
		throw std::range_error("List is empty.");

	if (size == 1u) {
		head = tail = nullptr;
		delete tail;
	}
	else {
		elem* pre_tail = get_previous(tail);
		delete tail;
		tail = pre_tail;
		tail->next = nullptr;
	}

	size--;
}

void MyList::pop_front() {
	if (size == 0u)
		throw std::range_error("List is empty.");

	elem* popping = head;
	head = head->next;

	delete popping;

	size--;
}

void MyList::insert(const int value, const size_t index) {
	if (index >= size)
		throw std::range_error("Index is incorrect.");

	if (index == 0u)
		push_front(value);
	else {
		elem* pre_current = get_by_index(index - 1);

		//inserting before element
		pre_current->next = new elem(value, pre_current->next);

		size++;
	}
}

int MyList::at(const size_t index) const {
	if (index >= size)
		throw std::range_error("Index is incorrect.");

	return get_by_index(index)->value;
}

void MyList::remove(const size_t index) {
	if (index >= size)
		throw std::range_error("Index is incorrect.");

	if (index == 0u)
		pop_front();
	else if (index == size - 1u)
		pop_back();
	else { //if removing is not head or tail
		elem* pre_deleting = get_by_index(index - 1);

		//inserting element
		elem* deleting = pre_deleting->next;
		pre_deleting->next = deleting->next;

		delete deleting;

		size--;
	}
}

size_t MyList::get_size() const {
	return size;
}

void MyList::clear() {
	elem* current = head;

	while (current != nullptr) {
		elem* deleting = current;
		current = current->next;
		delete deleting;
	}

	head = tail = nullptr;
	size = 0u;
}

void MyList::set(const size_t index, const int value) {
	if (index >= size)
		throw std::range_error("Index is incorrect.");

	if (index == size - 1u)
		tail->value = value;
	else { //if removing is no tail than start searching
		elem* current = head;
		for (size_t i = 0u; i != index; i++)
			current = current->next;

		current->value = value; //set the value
	}
}

bool MyList::isEmpty() const {
	return (size == 0);
}

void MyList::push_front(const MyList& other) {
	if (other.size == 0u)
		return;

	MyList list_copy(other);

	if (size == 0u) {
		//taking recources from list_copy

		head = list_copy.head;
		tail = list_copy.tail;
		size = list_copy.size;
	}
	else
	{
		//linking end & start
		list_copy.tail->next = head;

		//updating the head
		head = list_copy.head;

		//updating the size
		size += list_copy.size;
	}

	//list_copy losts connection with data
	list_copy.head = list_copy.tail = nullptr;
	list_copy.size = 0;
}

std::ostream& operator<<(std::ostream& out, const MyList& list) {
	MyList::elem* current = list.head;

	while (current != nullptr) {
		out << current->value << ' ';
		current = current->next;
	}

	out << std::endl;

	return out;
}

MyList::elem* MyList::get_previous(const  MyList::elem* const before) const {
	elem* previous = head;
	while (previous->next != before)
		previous = previous->next;

	return previous;
}

MyList::elem* MyList::get_by_index(const size_t index) const {
	//if index is last then return tail
	if (index == size - 1u)
		return tail;

	//else return founded
	elem* current = head;
	for (size_t i = 0u; i != index; i++)
		current = current->next;

	return current;
}

//#include "MyList.h"
//
//MyList::MyList() :head(nullptr), tail(nullptr), size(0u) {}
//
//MyList::MyList(const MyList& from) : size(from.size) {
//	if (size != 0u) {
//		//head coping
//		head = new elem(from.head->value);
//
//		elem* last_added = head;
//		elem* current = from.head->next;
//
//		//all other elements coping
//		while (current != nullptr) {
//			last_added = new elem(current->value, last_added, nullptr);
//
//			current = current->next;
//		}
//
//		tail = last_added;
//	}
//	else
//		head = tail = nullptr;
//}
//
//MyList::~MyList() {
//	clear();
//}
//
//void MyList::push_back(const int value) {
//	if (size == 0u)
//		head = tail = new elem(value);
//	else {
//		tail->next = new elem(value, tail, nullptr);
//		tail = tail->next;
//	}
//
//	size++;
//}
//
//void MyList::push_front(const int value) {
//	if (size == 0u)
//		head = tail = new elem(value);
//	else {
//		head->previous = new elem(value, nullptr, head);
//		head = head->previous;
//	}
//
//	size++;
//}
//
//void MyList::pop_back() {
//	if (size == 0u)
//		throw std::range_error("List is empty.");
//
//	elem* popping = tail;
//
//	tail = tail->previous;
//	tail->next = nullptr;
//
//	delete popping;
//
//	size--;
//}
//
//void MyList::pop_front() {
//	if (size == 0u)
//		throw std::range_error("List is empty.");
//
//	elem* popping = head;
//
//	head = head->next;
//	head->previous = nullptr;
//
//	delete popping;
//
//	size--;
//}
//
//void MyList::insert(const int value, const size_t index) {
//	if (index > size)
//		throw std::range_error("Index is incorrect.");
//
//	if (index == 0u)
//		push_front(value);
//	else {
//		elem* current;
//
//		//searching element by index
//		if (index == size - 1u)
//			current = tail;
//		else {
//			current = head;
//
//			for (size_t i = 0u; i != index; i++)
//				current = current->next;
//		}
//
//		//inserting before founded element
//		elem* inserting = new elem(value, current->previous, current);
//		current->previous->next = inserting;
//		current->previous = inserting;
//
//		size++;
//	}
//}
//
//int MyList::at(const size_t index) {
//	if (index > size)
//		throw std::range_error("Index is incorrect.");
//
//	//if index is last then return value of tail
//	if (index == size - 1u)
//		return tail->value;
//
//	//else return value of founded
//	elem* current = head;
//	for (size_t i = 0u; i != index; i++)
//		current = current->next;
//
//	return current->value;
//}
//
//void MyList::remove(const size_t index) {
//	if (index > size)
//		throw std::range_error("Index is incorrect.");
//
//	if (index == 0u)
//		pop_front();
//	else if (index == size - 1u)
//		pop_back();
//	else { //if removing is not head or tail
//		elem* current = head;
//		for (size_t i = 0u; i != index; i++)
//			current = current->next;
//
//		current->previous->next = current->next;
//		current->next->previous = current->previous;
//
//		delete current;
//
//		size--;
//	}
//}
//
//size_t MyList::get_size() {
//	return size;
//}
//
//void MyList::clear() {
//	elem* current = head;
//
//	while (current != nullptr) {
//		elem* deleting = current;
//		current = current->next;
//		delete deleting;
//	}
//
//	head = tail = nullptr;
//	size = 0u;
//}
//
//void MyList::set(const size_t index, const int value) {
//	if (index > size)
//		throw std::range_error("Index is incorrect.");
//
//	if (index == size - 1u)
//		tail->value = value;
//	else { //if removing is no tail than start searching
//		elem* current = head;
//		for (size_t i = 0u; i != index; i++)
//			current = current->next;
//
//		current->value = value; //set the value
//	}
//}
//
//bool MyList::isEmpty() {
//	return size == 0;
//}
//
//void MyList::push_front(const MyList& other) {
//	MyList list_copy(other);
//
//	if (size == 0u) {
//		//taking recources from list_copy
//
//		head = list_copy.head;
//		tail = list_copy.tail;
//		size = list_copy.size;
//	}
//	else {
//		//linking end & start
//		list_copy.tail->next = head;
//		head->previous = list_copy.tail;
//
//		//updating the head
//		head = list_copy.head;
//	}
//
//	//list_copy losts connection with data
//	list_copy.head = list_copy.tail = nullptr;
//	list_copy.size = 0;
//}
//
//std::ostream& operator<<(std::ostream& out, const MyList& list) {
//	MyList::elem* current = list.head;
//
//	while (current != nullptr) {
//		out << current->value << ' ';
//		current = current->next;
//	}
//	
//	out << std::endl;
//
//	return out;
//}
