#include <iostream>
#include <vector>

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


int main() {
  int n;
  cout <<"\n How many numbers are there in the list? "<<endl;
  cin>>n;
  vector <long int> numbers(n);
  cout<<"Enter the numbers: "<<endl;
  for(int i =0; i<n; i++){
    cin>>numbers[i] ;
  }

  long long int max_product = MaxPairwiseProductNaive(numbers);
  cout<<"Max pairwise product = "<<max_product<<endl;

  return 0;
}
