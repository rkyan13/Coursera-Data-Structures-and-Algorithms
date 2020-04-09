#include <iostream>
#include <cassert>
#include <stdlib.h>


using namespace std;


long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


int gcd_euclidean(int a, int b) {
  int gcd, low, high, remainder ;

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
  lcm = (long long int)(a*b)/gcd_euclidean(a, b);
  return lcm;
}

void test_solution(){
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
  cout<<lcm_naive(a,b) << endl;
  cout<<lcm_fast(a,b)  << endl;
  test_solution();
  return 0;
}
