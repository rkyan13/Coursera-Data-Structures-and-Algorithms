#include <iostream>
#include <vector>

using namespace std;


long long int MaxPairwiseProductFast(vector <long int> numbers){
  int n = numbers.size();
  long long int max_product;
  int max1_idx = 0;
  int max2_idx = 0;
  //
  for (int i = 0; i<n ; i++){
    if(numbers[i]>numbers[max1_idx])
       max1_idx = i;
  }

  if(max1_idx == 0)
     max2_idx = 1;
  else
     max2_idx = 0;

  for (int i = 0; i<n ; i++){
    if(numbers[i]>numbers[max2_idx] && i!=max1_idx)
       max2_idx = i;
  }

  max_product = numbers[max1_idx]*numbers[max2_idx];
  return max_product;
}



int main() {
  int n;
  //cout <<"\n How many numbers are there in the list? "<<endl;
  cin>>n;
  vector <long int> numbers(n);
  //cout<<"Enter the numbers: "<<endl;
  for(int i =0; i<n; i++){
    cin>>numbers[i] ;
  }

  long long int max_product = MaxPairwiseProductFast(numbers);
  //cout<<"Max pairwise product = ";
  cout<<max_product<<endl;

  return 0;
}
