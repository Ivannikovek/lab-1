#ifndef _MY_LIST_

#define _MY_LIST_

#include <iostream>
#include <stdexcept>

class MyList
{
public:
	MyList();
	MyList(const MyList& from);
	~MyList();

	void push_back(const int value);
	void push_front(const int value);
	void pop_back();
	void pop_front();
	void insert(const int value, const size_t index);
	int at(const size_t index) const;
	void remove(const size_t index);
	size_t get_size() const;
	void clear();
	void set(const size_t index, const int value);
	bool isEmpty() const;

	void push_front(const MyList& other);

	friend std::ostream& operator<<(std::ostream& out, const MyList& list);

private:
	struct elem;

	elem* head, * tail;

	size_t size;

	elem* get_previous(const elem* const before) const;
	elem* get_by_index(const size_t index) const;
};

struct MyList::elem {
	elem(int value, elem* next = nullptr) :value(value), next(next) {};

	int value;
	elem* next;
};

#endif



//#ifndef _MY_LIST_
//
//#define _MY_LIST_
//
//#include <iostream>
//#include <stdexcept>
//
//
//class MyList
//{
//public:
//	MyList();
//	MyList(const MyList& from);
//	~ MyList();
//
//	void push_back(const int value); 
//	void push_front(const int value);
//	void pop_back();
//	void pop_front();
//	void insert(const int value, const size_t index); 
//	int at(const size_t index);
//	void remove(const size_t index); 
//	size_t get_size();
//	void clear(); 
//	void set(const size_t index, const int value); 
//	bool isEmpty();
//
//	void push_front(const MyList& other);
//
//	friend std::ostream& operator<<(std::ostream& out, const MyList& list);
//
//private:
//	struct elem;
//
//	elem* head, * tail;
//
//	size_t size;
//};
//
//struct MyList::elem {
//	elem(int value) :value(value), previous(nullptr), next(nullptr) {};
//	elem(int value, elem* previous, elem* next) :value(value), previous(previous), next(next) {};
//
//	int value;
//	elem* next;
//	elem* previous;
//};
//
//#endif
