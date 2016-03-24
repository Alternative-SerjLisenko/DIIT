#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

double calculateLibrary(double x);
double calculateRow(double x, double e);
double calculateGorner(double x, double e, int ecs, double result);
void userInterface();



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

double calculateGorner(double x, double e, int ecs, double result) {
    if(e == ecs) {
        return result+8*x;
    }
    ecs*=0.1;
    result+= x*(1-(x/2)*(calculateGorner(x, e, ecs, result)));
    return 0;
}

void userInterface() {
    double x, e;
    
    /*cout << "Input x: ";
    cin >> x;
    cout << "Input e: ";
    cin >> e;*/
    x = 10;
    e = 0.00001;
    
    //Output result 3 func in nanosec
    cout << "\nResult test:\n";
    cout << "Library func: " << calculateLibrary(x) << " sec.\n";
    cout << "Row func: " << calculateRow(x,e) << " sec.\n";
    cout << "Gorner func: " << calculateGorner(x, e, 0, 0) << " sec.\n";
}