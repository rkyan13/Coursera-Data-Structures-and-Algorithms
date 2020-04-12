#include <iostream>
#include <cassert>
#include <vector>
#include <stdlib.h>
using namespace std;

/*
The c++ index goes only from 0 to n-1.
but Note that the fibonacci numbers are from idx 0 to n (n inclusive).
so in the fibonacci for-loop/for-loops check until n+1
*/

const int PISANO_OF_10 = 60;

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


/*
The c++ index goes only from 0 to n-1.
but Note that the fibonacci numbers are from idx 0 to n (n inclusive).
so in the for loop check until n+1
*/
vector<int> fibonacci_fast_last_digits_3vector(int n) {
    vector <int> fibResultVect(3);
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

    int a_mod10 = 0;
    int b_mod10 = 1;
    int curr_mod10 ;
    curr_mod10 = (a_mod10 + b_mod10)%10;
    for(int i = 3; i < n+1; i++) {
        a_mod10    = b_mod10;
        b_mod10    = curr_mod10;
        curr_mod10 = (a_mod10 + b_mod10)%10;
    }
    fibResultVect[0] = a_mod10;     //n-2
    fibResultVect[1] = b_mod10;     //n-1
    fibResultVect[2] = curr_mod10;  //n

    return fibResultVect;

}


int fibonacci_sum_squares_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    long long int effective_fibonacci_idx = n % PISANO_OF_10 ;

    vector <int> fib_vect = fibonacci_fast_last_digits_3vector(effective_fibonacci_idx);
    int Fn_2_mod10 = fib_vect[0];
    int Fn_1_mod10 = fib_vect[1];
    int Fn_mod10   = fib_vect[2];
    int Fn_squareSum;

    Fn_squareSum = (Fn_2_mod10 + Fn_1_mod10)*(Fn_1_mod10 + Fn_mod10);
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
    //cout << fibonacci_sum_squares_last_digit_naive(n)<<endl;
    //stress_test_solution();

    return 0;
}
