/*
The goal in this problem is to find the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.
*/

#include <iostream>
#include <cassert>
using namespace std;

const int INTERACTIVE = 0;

int get_change(int m) {
  //write your code here
  int ten_count, five_count, one_count, total_count;
  int mod10;

  ten_count  = m/10;
  mod10      = m%10;
  five_count = mod10/5;
  one_count  = mod10%5;

  total_count = ten_count + five_count + one_count;
  if(INTERACTIVE == 1) {
    cout <<" #of 10s =" << ten_count <<endl;
    cout <<" #of  5s =" << five_count <<endl;
    cout <<" #of  1s =" << one_count <<endl;
    cout <<" total #of coins =" << total_count <<endl;
  }

  return total_count;
}


void stress_test_solution() {
  assert(get_change(2)==2);
  cout<<"Stress test 1-OK"<<endl;
  assert(get_change(28)==6);
  cout<<"Stress test 2-OK"<<endl;
}



int main() {
  int m;

  if(INTERACTIVE == 1)
    cout <<"\nEnter the amount of money for which you need change : ";
  cin >> m;

  if(INTERACTIVE == 1)
    cout <<"\nAnswer : ";
  cout << get_change(m) << '\n';

  if(INTERACTIVE == 1)
    stress_test_solution();

  return 0;
}
