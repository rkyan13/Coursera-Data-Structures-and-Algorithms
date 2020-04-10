/*
This code isnt meant to calculate really a huge fibonacci number (the name of the code is a misnomer)
This code is meant to calculate the remainder when the huge fibonacci number 'n' is divided by a number 'm'
Coursera's naive function is get_fibonacci_huge_naive

The faster algorithm get_fibonacci_remainder_fast
i)   calculates the pisano_period of denominator 'm'
ii)  effective_fibonacci_idx = n%get_pisano_period
iii) effectiive_fibonacci = fib(effective_fibonacci_idx)
iv)  n%m = effectiive_fibonacci%m


/*
Note maximum fibonacci number than can be dealt with is n = 92
n = 92. fibonacci(92) =  7540113804746346429 : no overflow
n = 93. fibonacci(93) = -6246583658587674878 : overflow


Also this code will only work for 'm' that have a pisano period of less than 92.
It will not work for m=45 which has a pisano period >92
*/


#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h>

using namespace std;

int DEBUG = 0;



long long get_fibonacci_huge_naive(int n, int m) {
    if (n <= 1)
        return (long long)n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}//eof get_fibonacci_huge_naive


/*---------------------- All the functions and helper functions for get_fibonacci_remainder_fast ----------------------*/

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
}//eof fibonacci_fast


int get_pisano_period(int m){
  if(m<=2)
    return 3;

  long long int a = 0;
  long long int b = 1;
  long long int c = 1;
  long long int i = 3;
  int period_repeat = 0;

  while(period_repeat == 0){
      a = b;
      b = c;
      c = fibonacci_fast(i)%m;

      if(DEBUG ==1) {
        if(i >85 && i <95)
            cout<<"i ="<<i<<", fib = "<<fibonacci_fast(i)<<", a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
      }

      i++;
      if (a==0 && b==1 && c==1)
          period_repeat = 1;
  }//eof while loop

  int pisano_period = (int)i-3;
  return pisano_period ;

}//eof get_pisano_period


long long int get_fibonacci_remainder_fast(long long n, long long m){
  long long pisano_of_m                 = get_pisano_period(m);
  if(DEBUG ==1) {
      cout <<"Pisano Period of "<<m<<" = "<<pisano_of_m<<endl;
  }

  long long int effective_fibonacci_idx = n % pisano_of_m ;
  long long int effective_fibonacci     = fibonacci_fast(effective_fibonacci_idx);
  long long int           remainder     = effective_fibonacci%m;

  return remainder;
}

/*---------------------------------------------------------------------------------------------------------*/

void stress_test_solution(){

  assert(get_pisano_period(2)==3);
  assert(get_pisano_period(3)==8);
  assert(get_pisano_period(10946)==84);
  assert(get_pisano_period(1597)==68);

  assert(get_fibonacci_huge_naive(13, 55)== get_fibonacci_remainder_fast(13, 55));
  assert(get_fibonacci_huge_naive(7, 2)   == get_fibonacci_remainder_fast(7, 2));

  for(int i =0; i<10; i++){
    int n = rand()%90; //note max value of n is 92
    int m = rand()%20;
    assert(get_fibonacci_huge_naive(n, m)== get_fibonacci_remainder_fast(n, m));
    cout<<"OK"<<endl;
  }

}//eof void test_solution()


int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_remainder_fast(n, m) << '\n';
    //ksw: Comment following 2 lines before submission
    cout << get_fibonacci_huge_naive(n, m)     << '\n';
    stress_test_solution();
    return 0;
}
