#include <iostream>
#include <chrono>

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

typedef std::chrono::system_clock clock_now;
typedef std::chrono::duration<double> dur_double; 

void generateArray(int n, int *arr) {
    int newValue;
    bool check = true;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        newValue = rand() % n + 1;
        for (int j = 0; j < i; j++) {
            if (newValue == arr[j])
                check = false;
        }
        if (check)
            arr[i] = newValue;
        else {
            i--;
            check = true;
        }
    }
}

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
    auto t1 = clock_now::now();
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
    auto t2 = clock_now::now();
    dur_double res = t2-t1;

    return res.count();
}

double sortSelectionRightToLeft(int n, int *arr) {
    auto t1 = clock_now::now();
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
    auto t2 = clock_now::now();
    dur_double res = t2-t1;

    return res.count();
}

double sortBubble(int n, int *arr) {
    auto t1 = clock_now::now();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    auto t2 = clock_now::now();
    dur_double res = t2-t1;

    return res.count();
}

double sortHybrid(int n, int *arr) {
    auto t1 = clock_now::now();

    bool check = true, search_check;
    int cur_value = 0, high_index_value = 0, high_value = 0,left_step = 0, 
    	temp = 0,	   low_index_value = 0,  low_value = 0, right_step = 0;
     	
    while (check) {
            check = false;
            search_check = false;
            for (int i = left_step; i < n; i++) {
                cur_value = arr[i];
                if (cur_value < low_value || i == left_step) {
                    low_value = cur_value;
                    low_index_value = i;
                    search_check = true;
                }
            }

            if (search_check) {
                temp = arr[low_index_value];
                arr[low_index_value] = arr[left_step];
                arr[left_step]= temp;
                check = true;
            }

            low_value = 0;
            low_index_value = 0;
            left_step++;

        search_check = false;
        for (int i = 0; i < n- right_step; i++) {
            cur_value = arr[i];
            if (cur_value > high_value || i == 0) {
                high_value = cur_value;
                high_index_value = i;
                search_check = true;
            }
        }

        if (search_check) {
            temp = arr[high_index_value];
            arr[high_index_value]= arr[n- right_step - 1];
            arr[n- right_step - 1] = temp;
            check = true;
        }

        high_value = 0;
        high_index_value = 0;
        right_step++;
    }
    auto t2 = clock_now::now();
    dur_double res = t2-t1;

    return res.count();
}

void IUserInterface() {

    char menu = '-';
    const int n = 58;
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
        cout << "7 | testing func" << endl;
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

            case '7':
                testing();
                break;

            case '0':
                menu = '0';
                break;

            default:
                cout << "Menu item selection error!";
                break;
        }
    }while(menu!='0');
    delete arr, delete temp_arr;
}

void testing() {
    double temp_arr[17];
    int arr[58];
    for (int i = 0; i < 6; ++i) {
        generateArray(58, arr);
        temp_arr[i] = sortSelectionLeftToRight(58, arr);
        temp_arr[i+5] = sortHybrid(58, arr);
        temp_arr[i+11] = sortBubble(58, arr);
    }
    cout << "Selection " << "     Hybrid " << "     Bubble "<< endl;
    for (int j = 1; j < 19; ++j) {
        cout << " | " << temp_arr[j];
        if (j%3 == 0)
            cout << endl;
    }
}

int main() {
    IUserInterface();
    return 0;
}