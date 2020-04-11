#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h> //for rand
using namespace std;

long long fib_partial_sum_last_digit_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

/*------------ START: helper functions and functions for partial fibonacci sum fast ----------- */
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


long long int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    long long fib_sum_n = fibonacci_fast(n+2) -1;
    return fib_sum_n;
}

long long int fib_partial_sum_last_digit_fast(long long from, long long to) {
    long long fib_sum_partial;
    if(from == 0)
      fib_sum_partial = fibonacci_sum_fast(to)-fibonacci_sum_fast(from);
    else
      fib_sum_partial = fibonacci_sum_fast(to)-fibonacci_sum_fast(from-1);

    return fib_sum_partial%10;
}

/*------------ END: helper functions and functions for partial fibonacci sum fast ----------- */

void stress_test_solution() {
    long long from , to;
    for (int i = 0; i < 20; ++i){
        from = rand()%30;
        to   = rand()%30+30;
        cout<<"from = "<<from<<", to ="<<to<<" : ";
        assert(fib_partial_sum_last_digit_naive(from, to) == fib_partial_sum_last_digit_fast(from,to));
        cout<<"OK"<<endl;
    }
}

int main() {
    long long from, to;
    cin >> from >> to;
    cout << fib_partial_sum_last_digit_fast(from, to) << '\n';
    //cout << fib_partial_sum_last_digit_naive(from, to) << '\n';
    //stress_test_solution();
    return 0;
}
