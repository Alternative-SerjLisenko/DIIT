#include <iostream>

using namespace std; 

template<class T>
class Iterator {	
private:
	T element;
public:
	Iterator();
	~Iterator();
	void increment();
	void decrement();
	void pointer();
};