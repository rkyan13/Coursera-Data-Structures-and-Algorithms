#include <iostream>
#include <cassert>
#include <vector>
#include <stdlib.h>
using namespace std;


int fibonacci_sum_squares_last_digit_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}



vector<long long int> fibonacci_fast_vector(int n) {
    vector <long long int> fibResultVect(3);
    // write your code here
    if (n == 0) {
      fibResultVect[0] = 0;
      fibResultVect[1] = 0;
      fibResultVect[2] = 0;
      return fibResultVect;
    }
    else if (n == 1) {
      fibResultVect[0] = 0;
      fibResultVect[1] = 0;
      fibResultVect[2] = 1;
      return fibResultVect;
    }


    vector <long long int> fibVect(n+1);
    fibVect[0] = 0;
    fibVect[1] = 1;
    for(int i=2; i<n+1; i++) {
      fibVect[i]= fibVect[i-1]+fibVect[i-2];
    }

    fibResultVect[0] = fibVect[n-2];
    fibResultVect[1] = fibVect[n-1];
    fibResultVect[2] = fibVect[n];

    return fibResultVect;
}


int fibonacci_sum_squares_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    vector <long long int> fib_vect = fibonacci_fast_vector(n);
    long long Fn_2 = fib_vect[0];
    long long Fn_1 = fib_vect[1];
    long long Fn   = fib_vect[2];
    long long Fn_squareSum;

    Fn_squareSum = (Fn_2 + Fn_1)*(Fn_1 + Fn);
    return Fn_squareSum % 10;
}


void stress_test_solution() {
    long long n;
    assert(fibonacci_sum_squares_last_digit_fast(0) == 0);
    assert(fibonacci_sum_squares_last_digit_fast(1) == 1);
    assert(fibonacci_sum_squares_last_digit_fast(2) == 2);
    assert(fibonacci_sum_squares_last_digit_fast(10) == 5);
    for (int i = 0; i < 10; ++i){
        n = rand()%30;
        assert(fibonacci_sum_squares_last_digit_naive(n) == fibonacci_sum_squares_last_digit_fast(n));
        cout<<"OK"<<endl;
    }
}





int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares_last_digit_fast(n) <<endl;
    cout << fibonacci_sum_squares_last_digit_naive(n)<<endl;
    stress_test_solution();

    return 0;
}
