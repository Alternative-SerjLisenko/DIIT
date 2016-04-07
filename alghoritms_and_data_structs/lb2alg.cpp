#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;

void generateArray(int n, int *arr);
void outputArray(int n, int *arr);
void copyArray(int n, int *arr);
double sortSelectionLeftToRight(int n, int *arr);
double sortSelectionRightToLeft(int n, int *arr);
double sortHybrid(int n, int *arr);
double sortBubble(int n, int *arr);
void IUserInterface();
void testing();

void generateArray(int n, int *arr) {
	srand (time(NULL));
	int j = 0;
	bool check = false;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		arr[i] = rand() % n + 1;
		while(i != j) {
			if(arr[i] == arr[j]) {
				arr[i] = rand() % n + 1;
			} else {
				j++;
			}
		}
	}
}


/*void generateArray(int N, int *arr) {
	srand (time(NULL));
	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % N + 1;
	}
}*/

void outputArray(int n, int *arr) {
	for (int i = 0; i < n; ++i) {
		cout << " " << arr[i];
	}
}

void copyArray(int n, int *arr, int *&copy_arr) {
	for (int i = 0; i < n; i++) {
		copy_arr[i] = arr[i];
	}
}

double sortSelectionLeftToRight(int n, int *arr) {
	auto t1 = std::chrono::system_clock::now();
	for (int min = 0; min < n-1; min++) {
		int least = min;
		for (int j = min+1; j < n; j++) {
			if(arr[j] < arr[least]) {
				least = j;
			}
		}
		int tmp = arr[min];
		arr[min] = arr[least];
		arr[least] = tmp;
	}
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> res = t2-t1;
	return res.count();
}

double sortSelectionRightToLeft(int n, int *arr) {
	auto t1 = std::chrono::system_clock::now();
	for (int min = 0; min < n-1; min++) {
		int least = min;
		for (int j = min+1; j < n; j++) {
			if(arr[j] > arr[least]) {
				least = j;
			}
		}
		int tmp = arr[min];
		arr[min] = arr[least];
		arr[least] = tmp;
	}
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> res = t2-t1;
	return res.count();
}

double sortBubble(int n, int *arr) {
	auto t1 = std::chrono::system_clock::now();
     for (int i = 0; i < n-1; i++) {
         for (int j = 0; j < n-i-1; j++) {
             if (arr[j] > arr[j+1]) {
                 int temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
         }
     }
    auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> res = t2-t1;
	return res.count();
} 

//refactor hybrid

double sortHybrid(int n, int *arr) {
	auto t1 = std::chrono::system_clock::now();

	bool check = true;
	bool searchCheck = 0;
	int currentValue = 0;
	int highestValueIndex = 0;
	int lowestValueIndex = 0;
	int highestValue = 0;
	int lowestValue = 0;
	int leftStep = 0;
	int rightStep = 0;
	int temp = 0;
	bool hybrid = false;

	while (check != false)
	{
		if (hybrid == false)
		{
			check = false;
			searchCheck = false;
			for (int i = leftStep; i < n; i++)
			{
				currentValue = arr[i];
				if (currentValue < lowestValue || i == leftStep)
				{
					lowestValue = currentValue;
					lowestValueIndex = i;
					searchCheck = true;
				}
			}

			if (searchCheck == true)
			{
				temp = arr[lowestValueIndex];
				arr[lowestValueIndex] = arr[leftStep];
				arr[leftStep]= temp;
				check = true;
			}

			currentValue = 0;
			lowestValue = 0;
			lowestValueIndex = 0;
			leftStep++;
			hybrid = true;
		}
		if (hybrid == true)
		{
			check = false;
			searchCheck = false;
			for (int i = 0; i < n- rightStep; i++)
			{
				currentValue = arr[i];
				if (currentValue > highestValue || i == 0)
				{
					highestValue = currentValue;
					highestValueIndex = i;
					searchCheck = true;
				}
			}

			if (searchCheck == true)
			{
				temp = arr[highestValueIndex];
				arr[highestValueIndex]= arr[n- rightStep - 1];
				arr[n- rightStep - 1] = temp;
				check = true;
			}

			currentValue = 0;
			highestValue = 0;
			highestValueIndex = 0;
			rightStep++;
			hybrid = false;
		}
	}
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> res = t2-t1;
	return res.count();
}

void IUserInterface() {

	char menu = '-';
	const int n = 56;
	int *arr = new int[n];
	int *temp_arr = new int[n];
	do {
		cout << "\n\tMenu: " << endl;
		cout << "1 | generate array" << endl;
		cout << "2 | output array" << endl;
		cout << "3 | sort selection ~ left to right" << endl;
		cout << "4 | sort selection ~ right to left" << endl;
		cout << "5 | sort hybrid" << endl;
		cout << "6 | sort bubble" << endl;
		cout << "0 | exit" << endl;
		cout << "\nChose menu item: ";
		cin >> menu;
			switch(menu) {

				case '1':
					generateArray(n, arr);
				break;

				case '2':
					outputArray(n, arr);
				break;

				case '3':
					copyArray(n, arr, temp_arr);
					sortSelectionLeftToRight(n, temp_arr);
					outputArray(n, temp_arr);
				break;

				case '4':
					copyArray(n, arr, temp_arr);
					sortSelectionRightToLeft(n, temp_arr);
					outputArray(n, temp_arr);
				break;

				case '5':
					copyArray(n, arr, temp_arr);
					sortHybrid(n, temp_arr);
					outputArray(n, temp_arr);
				break;

				case '6':
					copyArray(n, arr, temp_arr);
					sortBubble(n, temp_arr);
					outputArray(n, temp_arr);
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