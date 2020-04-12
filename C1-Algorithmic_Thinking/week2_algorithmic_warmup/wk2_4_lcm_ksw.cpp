#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

/*
The c++ index goes only from 0 to n-1.
but Note that the fibonacci numbers are from idx 0 to n (n inclusive).
so in the fibonacci for-loop/for-loops check until n+1
*/


long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


long long int gcd_euclidean(int a, int b) {
  long long int gcd, low, high, remainder ;

  if (a > b) {
    high =  a;
    low  = b;
  }
  else {
    high = b;
    low  = a;
  }

  while(low !=0){
    remainder = high % low;
    high = low;
    low  = remainder;
  }

  gcd = high;
  return gcd;
}


long long lcm_fast(int a, int b) {
  long long int lcm;
  long long int gcd = gcd_euclidean(a, b);
  lcm = (long long)a*b/gcd ; //Note lcm = (long long)(a*b)/gcd ; causes overflow error. this syntax is wrong
  return lcm;
}


void stress_test_solution(){
  assert(lcm_naive(239,797) ==lcm_fast(239,797));
  assert(lcm_naive(969,1609)==lcm_fast(969,1609));
  for(int i =0; i<20; i++){
    int a = rand()%10000 ;
    int b = rand()%10000 ;
    assert(lcm_naive(a,b)==lcm_fast(a,b));
  }
}

int main() {
  int a, b;
  cin >> a >> b;
  cout<<lcm_fast(a,b)  << endl;
  //ksw: Comment following 2 lines before submission
  cout<<lcm_naive(a,b) << endl;
  stress_test_solution();
  return 0;
}
