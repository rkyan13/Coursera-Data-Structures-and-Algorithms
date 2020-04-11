#include <iostream>
#include <cassert>
#include <vector>
#include <stdlib.h>
using namespace std;


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



int get_fibonacci_last_digit_fast(long long n){
  if(n<=1)
     return n;

  int a_mod10 = 0;
  int b_mod10 = 1;
  int curr_mod10 ;

  for(long long i = 2; i < n+1; i++) {
      curr_mod10 = (a_mod10 + b_mod10)%10;
      a_mod10 = b_mod10;
      b_mod10 = curr_mod10;
  }

  return curr_mod10;
}


int fibonacci_sum_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    int fib_Nplus2_lastDigit = get_fibonacci_last_digit_fast(n+2);
    int fib_sum_N_lastDigit;
    if(fib_Nplus2_lastDigit==0)
       fib_sum_N_lastDigit = 9;
    else
       fib_sum_N_lastDigit = fib_Nplus2_lastDigit -1;

    return fib_sum_N_lastDigit ;
}


void stress_test_solution() {
    assert(fibonacci_sum_last_digit_fast(8) == 4);//the sum of the Fibonacci numbers from F(0) to F(8) is 54 (last digit 4)
    assert(fibonacci_sum_last_digit_fast(2) == 2);//the sum of the Fibonacci numbers from F(0) to F(2) is = 0+1+1 = 2 (last digit 2)
    assert(fibonacci_sum_last_digit_fast(239) == 0);//the sum of the Fibonacci numbers from F(0) to F(239) , last digit is 0 says coursera .
    for (int i = 0; i < 10; ++i){
      //keeping rand at 20 because fibonacci_sum_last_digit_naive can handle only small numbers. Beyond that it will spew junk due to over flow
      //but fibonacci_sum_last_digit_fast can handle even big numbers of the order long long
      int n = rand()%20;
      assert(fibonacci_sum_last_digit_naive(n) == fibonacci_sum_last_digit_fast(n));
      cout<<"OK"<<endl;
    }
}


int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_last_digit_fast(n) <<endl;
    //cout << fibonacci_sum_last_digit_naive(n)<<endl;
    //stress_test_solution();
    return 0;
}
//832564823476
