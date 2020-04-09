#include <iostream>
#include <cassert>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long int previous = 0;
    long long int current  = 1;

    for (int i = 2; i < n+1 ; i++) {
        long long int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return (int)(current%10);
}


int get_fibonacci_last_digit_fast(int n){
  if(n<=1)
     return n;

  int a_mod10 = 0;
  int b_mod10 = 1;
  int curr_mod10 ;

  for(int i = 2; i < n+1; i++) {
      curr_mod10 = (a_mod10 + b_mod10)%10;
      a_mod10 = b_mod10;
      b_mod10 = curr_mod10;
  }

  return curr_mod10;
}


void test_solution(){
  assert(get_fibonacci_last_digit_naive(3)==2);
  assert(get_fibonacci_last_digit_fast(5) ==5);
  for(int i =0; i<=20; i++) {
    assert(get_fibonacci_last_digit_naive(i)==get_fibonacci_last_digit_fast(i));
  }
}


int main() {
    int n;
    std::cin >> n;

    //cout << get_fibonacci_last_digit_naive(n) << '\n';
    cout << get_fibonacci_last_digit_fast(n) << '\n';
    //test_solution();

    return 0;

    }
