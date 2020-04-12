#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h> //for rand
using namespace std;

/*
The c++ index goes only from 0 to n-1.
but Note that the fibonacci numbers are from idx 0 to n (n inclusive).
so in the fibonacci for-loop/for-loops check until n+1
*/


const int PISANO_OF_10 = 60;

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

    long long int effective_fibonacci_idx = (n+2) % PISANO_OF_10 ;
    int  fib_Nplus2_lastDigit = get_fibonacci_last_digit_fast(effective_fibonacci_idx);

    int fib_sum_N_lastDigit;
    if(fib_Nplus2_lastDigit==0)
       fib_sum_N_lastDigit = 9;
    else
       fib_sum_N_lastDigit = fib_Nplus2_lastDigit -1;

    return fib_sum_N_lastDigit ;
}



int fib_partial_sum_last_digit_fast(long long from, long long to) {
    int fib_sumPartial_lastDigit,fib_sumFrom_lastDigit, fib_sumTo_lastDigit;
    if(from == 0) {
      fib_sumTo_lastDigit   = fibonacci_sum_last_digit_fast(to);
      fib_sumFrom_lastDigit = fibonacci_sum_last_digit_fast(from);
    }
    else {
      fib_sumTo_lastDigit   = fibonacci_sum_last_digit_fast(to);
      fib_sumFrom_lastDigit = fibonacci_sum_last_digit_fast(from-1);
    }

    fib_sumPartial_lastDigit = fib_sumTo_lastDigit - fib_sumFrom_lastDigit;
    //If example fib_sumTo_lastDigit = 4 & fib_sumFrom_lastDigit = 5 ; 4-5 = -1.
    //This should actually be 14-5 = 9. hence -1+10 = 9
    if(fib_sumPartial_lastDigit<0)
      fib_sumPartial_lastDigit +=10;



    return fib_sumPartial_lastDigit ;
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
