#include "Set.h"

template <class T>
Set<T>::Set() {
	first = true;
}

template <class T>
Set<T>::~Set() {

}

template <class T>
void Set<T>::inBegin(T const & element) {
	if(first) {
		u = new ListSet;
		u->lElem.sElem = element;
		u->next = NULL;
		first = false;
	} else {
		ListSet *t = new ListSet;
		t -> lElem.sElem = element;
		t -> next = u;
		u = t;
	}
}

template <class T>
void Set<T>::inEnd(T const & element) { // Реализовать вставку в конец списка
	if(first) {
		u = new ListSet;
		u->lElem.sElem = element;
		u->next = NULL;
		first = false;
	} 
	else {	
		last = u;
		while (!(last->next == NULL))
			last = last->next;
		
		ListSet *n = new ListSet;
		last-> next = n;
		n->next = NULL;
		n->lElem.sElem=element;
	}
}

template <class T>
void Set<T>::print() {
	if(!isEmpty()) {
		ListSet *p = u;
		cout << "Multiply: ";
		while(p) {
			cout << p->lElem.sElem << " ";
			p = p->next;
		}
	}
}

template <class T>
bool Set<T>::isEmpty() {
	if(u == NULL) {
		cout << "\nMultiply is empty!" << endl;
		return true;
	}
	return false;
}

template <class T>
void Set<T>::clearMultiply() {
	if(u = NULL)
		return;

	ListSet *p = u;
	ListSet *t;
	while(p) {
		t = p;
		p = p -> next;
		delete t;
	}
	u = NULL;
}