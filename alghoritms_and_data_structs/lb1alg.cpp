#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

double calculateLibrary(double x);
double calculateRow(double x, double e);
double calculateGorner(double x, double e, double ecs, double result);
double calculateGornerTime(double x, double e, double ecs, double result);
int userInterface();

int main() {
	userInterface();
	return 0;
}

double calculateLibrary(double x) {
    auto t1 = std::chrono::system_clock::now();
    
    double result = 8*x + log(x);
    
    auto t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> res = t2-t1;
    
    return res.count();
}

double calculateRow(double x, double e) {
    
    auto t1 = std::chrono::system_clock::now();
    //variable block
    double stx = x -1;
    int fakt = 1;
    int lnt = 0;
    int i = 1;
    int z = 1;
    
    //algorithm
    while(stx/fakt >= e) {
        lnt = lnt+z * (stx/fakt);
        i++;
        stx= stx*(x-1);
        fakt = i;
        z = z*(i-1);
    }
    
    auto t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> res = t2-t1;

    return res.count();
}

double calculateGorner(double x, double e, double ecs, double result) {
	if(ecs <= e) {
		return result+8*x;
	}
	return result+= x*(0.5*(calculateGorner(x, e, ecs*0.1, result)));
}

double calculateGornerTime(double x, double e, double ecs, double result) {
    auto t1 = std::chrono::system_clock::now();
    calculateGorner(x, e, ecs, result);
    auto t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> res = t2-t1;             

    return res.count();
}

int userInterface() {
    double x, e;
    double ecs = 1;

    bool condition = false;
    while(!condition) {
        cout << "Input x: ";
        cin >> x;
        if((x < -1) || (x > 1)) {
            cout << "Warning x is out of range!";   
        } else {
            condition = true;
        }
    }
    
    cout << "Input e: ";
    cin >> e;
    if(x == 1) {
        cout << "Result = " << 8*x;
        return 8*x;
    }
    if(x == 0) {
        cout << "Result " << 0;
        return 0;
    }
    //Output result 3 func in nanosec
    cout << "\nResult test:\n";
    cout << "Library func: " << calculateLibrary(x) << " sec.\n";
    cout << "Row func: " << calculateRow(x,e) << " sec.\n";
    cout << "Gorner func: " << calculateGornerTime(x, e, ecs, 0) << " sec.\n";

    return 0;
}