#include <chrono>
#include <iostream>
using namespace std;

double function(double x) {
    return (4/(1+x*x));
}

double serial_pi(int n) {
    double sum = 0;
    double dn = n*1.0;
    for (auto i=1; i<=n; i++) {
        sum += function((i*1.0-0.5)/dn);
    }
    return sum/dn;
}

int main(int argc, char const *argv[]) {

    int n = 1;
    for (int i=0; i<20; i++) {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        auto pi = serial_pi(n);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << n << " take: \t" 
                  << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() 
                  << "ns\t" << "get: " << pi << std::endl;
    
        n <<= 1;
    }
    return 0;
}