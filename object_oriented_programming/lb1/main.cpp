#include "Set.cpp"
#include "Iterator.cpp"

int main() {
	Set<char> mySet;

	mySet.print();

	mySet.inEnd('s');
	mySet.inEnd('y');
	mySet.inEnd('k');
	mySet.inEnd('a');

	mySet.print();
	
	mySet.clearMultiply();

	return 0;
}