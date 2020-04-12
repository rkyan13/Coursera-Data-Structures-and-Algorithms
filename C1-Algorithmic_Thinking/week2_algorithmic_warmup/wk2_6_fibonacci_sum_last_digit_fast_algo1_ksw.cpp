#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

/*
The c++ index goes only from 0 to n-1.
but Note that the fibonacci numbers are from idx 0 to n (n inclusive).
so in the fibonacci for-loop/for-loops check until n+1
*/


int fibonacci_sum_last_digit_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}



long long int fibonacci_fast(int n) {
    // write your code here
    if (n <= 1)
        return (long long)n;

    vector <long long int> fibVect(n+1);
    fibVect[0] = 0;
    fibVect[1] = 1;
    for(int i=2; i<n+1; i++) {
      fibVect[i]= fibVect[i-1]+fibVect[i-2];
    }

    return fibVect[n];
}


int fibonacci_sum_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    long long fib_sum_n = fibonacci_fast(n+2) -1;
    return fib_sum_n % 10;
}


void stress_test_solution() {
    assert(fibonacci_sum_last_digit_fast(8) == 4);
    assert(fibonacci_sum_last_digit_fast(2) == 2);
    for (int n = 0; n < 20; ++n){
        assert(fibonacci_sum_last_digit_naive(n) == fibonacci_sum_last_digit_fast(n));
        cout<<"OK"<<endl;
    }
}


int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_last_digit_fast(n) <<endl;
    cout << fibonacci_sum_last_digit_naive(n)<<endl;
    stress_test_solution();
    return 0;
}
