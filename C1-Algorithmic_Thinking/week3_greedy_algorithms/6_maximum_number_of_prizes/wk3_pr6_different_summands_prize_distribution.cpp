#include <iostream>
#include <vector>

using std::vector;

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int running_sum    = 0;
  for(int i = 1; running_sum <=n; i++){
     running_sum += i;
    if(running_sum <n)
    {  //cout<<"if : i ="<<i<<" ,running_sum ="<<running_sum<<endl;
       summands.push_back(i);
    }
    else if(running_sum ==n)
    {  //cout<<"else if : i ="<<i<<" ,running_sum ="<<running_sum<<endl;
       summands.push_back(i);
       break;
    }
    else
    {  //cout<<"else : i ="<<i<<" ,running_sum ="<<running_sum<<endl;
       int excess = n-(running_sum - i);
       //add the excess to the last element of summands
       summands[i-2] += excess;
       break;
     }
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }

  std::cout<<std::endl;

}
