#include <iostream>
#include <string.h>

using namespace std;

template <class T>
class Set {
private:
	struct Data
	{
		T sElem;
	};
	struct ListSet {
		Data lElem;
		ListSet *next; 
	};
	ListSet *u = NULL;
	ListSet *last = NULL;
	bool isEmpty();
	bool first;
public:


	Set();
	~Set();
	void inBegin(T const & element);
	void inEnd(T const & element);
	void print();
	void clearMultiply();
};