#include <iostream>
#include <cassert>
#include<stdlib.h>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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



void test_solution(){
  assert(gcd_naive(239,797)==gcd_euclidean(239,797));
  assert(gcd_naive(969,323)==gcd_euclidean(323,969));

  int a,b;
  for(int i=0; i<20; i++){
    a = rand()%1000;
    b = rand()%1000;
    assert(gcd_naive(a,b)==gcd_euclidean(a,b));
    cout<<"OK"<<endl;
  }
}



int main() {
  int a, b;
  cin >> a >> b;

  cout << gcd_euclidean(a, b) << std::endl;
  //cout << gcd_naive(a, b) << std::endl;
  //test_solution();
  return 0;
}
