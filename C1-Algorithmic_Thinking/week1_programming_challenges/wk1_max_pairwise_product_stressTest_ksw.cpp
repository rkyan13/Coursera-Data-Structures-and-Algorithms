#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


long long int MaxPairwiseProductNaive(vector <long int> numbers){
            int           n = numbers.size();
  long long int max_product = numbers[0]*numbers[1];

  for (int i = 0; i<n ; i++){
    for(int j =i+1; j<n; j++){
      if(max_product<numbers[i]*numbers[j])
          max_product=numbers[i]*numbers[j];
    }
  }

  return max_product;
}

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

  int error = 0;

  while(error == 0){
      int n = rand() % 5+ 2;
      cout <<"\n Length of the list ="<<n << endl;
      vector <long int> numbers(n);
      for(int i =0; i<n; i++){
        //cin>>numbers[i];
        numbers[i] = rand() % 10+1;
        cout<<numbers[i] <<endl;
      }

      long long int max_product_naive     = MaxPairwiseProductNaive(numbers);
      long long int max_product_fast = MaxPairwiseProductFast(numbers);
      if(max_product_naive==max_product_fast) {
        cout<<"OK"<<endl;
      }
      else {
        cout<<"Error"<<endl;
        cout<<"max_product_naive     = "<<max_product_naive<<endl;
        cout<<"max_product_fast = "<<max_product_fast<<endl;
        error = 1;
      }

  }


  return 0;
}
