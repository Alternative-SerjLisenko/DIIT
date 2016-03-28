#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateArray(int N, int *arr);
void outputArray(int N, int *arr);
void sortSelectionLeftToRight(int N, int *arr);
void sortSelectionRightToLeft(int N, int *arr);
void heapSort_ShiftDown(int *arr, int i, int j);
void heapSort(int N, int *arr);
void sortBubble(int N, int *arr);
void IUserInterface();

void generateArray(int N, int *arr) {
	srand (time(NULL));
	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % N + 1;
	}
}

void outputArray(int N, int *arr) {
	for (int i = 0; i < N; ++i) {
		cout << " " << arr[i];
	}
}

void sortSelectionLeftToRight(int N, int *arr) {
	for (int min = 0; min < N-1; min++) {
		int least = min;
		for (int j = min+1; j < N-1; j++) {
			if(arr[j] < arr[least]) {
				least = j;
			}
		}
		int tmp = arr[min];
		arr[min] = arr[least];
		arr[least] = tmp;
	}
}

void sortSelectionRightToLeft(int N, int *arr) {
	for (int min = 0; min < N-1; min++) {
		int least = min;
		for (int j = min+1; j < N-1; j++) {
			if(arr[j] > arr[least]) {
				least = j;
			}
		}
		int tmp = arr[min];
		arr[min] = arr[least];
		arr[least] = tmp;
	}
}

void heapSort_ShiftDown(int *arr, int i, int j) {
	bool done = false;
	int maxChild;

	while ((i * 2 + 1 < j) && (!done)) {
		if (i * 2 + 1 == j -1) {
			maxChild = i * 2 + 1;
		} else if( arr[i * 2 + 1] > arr[i * 2 + 2]) {
			maxChild = i * 2 + 1;
		} else {
			maxChild = i * 2 + 2;
		}

		if( arr[i] < arr[maxChild]) {
			swap( arr[i], arr[maxChild]);
			i = maxChild;
		} else {
			done = true;
		}
	}
}

void heapSort(int N, int *arr) {
	int i;
	for (i = N / 2 - 1; i >= 0; i--) {
		heapSort_ShiftDown(arr, i, N);
	}

	for (int i = N - 1; i >= 1; i--) {
		swap( arr[0], arr[i]);
		heapSort_ShiftDown( arr, 0, i);
	}
}

void sortBubble(int N, int *arr) {
     for (int i = 0; i < N-1; i++) {
         for (int j = 0; j < N-i-1; j++) {
             if (arr[j] > arr[j+1]) {
                 int temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
         }
     }
} 

void IUserInterface() {
	char menu = '-';
	const int N = 56;
	int *arr = new int[N];
	do {
		cout << "\n\tMenu: " << endl;
		cout << "1 | generate array" << endl;
		cout << "2 | output array" << endl;
		cout << "3 | sort selection ~ left to right" << endl;
		cout << "4 | sort selection ~ right to left" << endl;
		cout << "5 | sort heap sort" << endl;
		cout << "6 | sort bubble" << endl;
		cout << "0 | exit" << endl;
		cout << "\nChose menu item: ";
		cin >> menu;
			switch(menu) {

				case '1':
					generateArray(N, arr);
				break;

				case '2':
					outputArray(N, arr);
				break;

				case '3':
					sortSelectionLeftToRight(N, arr);
				break;

				case '4':
					sortSelectionRightToLeft(N, arr);
				break;

				case '5':
					heapSort(N, arr);
				break;

				case '6':
					sortBubble(N, arr);
				break;

				case '0':
					menu = '0';
				break;

				default: 
					cout << "Menu item selection error!";
				break;
			}
	}while(menu!='0');
	delete arr;
}

int main() {
	IUserInterface();
	return 0;
}