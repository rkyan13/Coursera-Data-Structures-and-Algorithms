#include <iostream>
#include <vector>
#include <numeric> //for accumulate function
#include <iomanip> //for cout<<setprecision

using namespace std;
const int DEBUG = 1;
const int INTERACTIVE = 1;

void swap(int i, int j, vector<int> &vec2_sort){
  int temp_variable;
  temp_variable = vec2_sort[i];
  vec2_sort[i]  = vec2_sort[j];
  vec2_sort[j]  = temp_variable;
}

//sort_vect doesn't actualy sort vect_2_sort. It creates an idx_tracker vector and puts the sorted indices there
//Indices are sorted in descending order, highest value_per_unit_weight index is first
vector <int> sort_vect(vector <double> val_per_wt){

  //Create an index tracker array whose elements are just the indices
  int num_items_in_list = val_per_wt.size();
  vector <int> idx_tracker(num_items_in_list);
  for(int i =0; i <num_items_in_list; i++){
    idx_tracker[i] =i;
  }

 //Sort the index tracker array elements based on the val_per_wt array
  for(int i = 0 ; i <num_items_in_list; i++) {
    for(int j =i; j<num_items_in_list; j++){
      if(val_per_wt[i]<val_per_wt[j])
         swap(i,j,idx_tracker);
    }//eof j loop
  }//eof i loop

  if(DEBUG ==1) {
    cout<<"idx_tracker sorted indices"<<endl;
    for(int i =0; i <num_items_in_list; i++){
      cout <<idx_tracker[i] << " ";
    }
    cout <<endl;
  }

  return idx_tracker;

}//eof sort_vector

double get_optimal_value(double bag_wt_capacity, vector<double> weights, vector<double> values) {
  double bag_value = 0.0;
  int num_items_in_list = weights.size();
  // write your code here

  //Calculate the value per unit weight. Higher the value per unit weight , more desirable is the item
  vector <double> value_per_unit_weight(num_items_in_list);
  for(int i =0; i<num_items_in_list ; i++){
    value_per_unit_weight[i]=values[i]/weights[i];
  }

  //Sort the vector in descending order of value per unit weight
  vector <int> sorted_indices = sort_vect(value_per_unit_weight);

  //Implement Fractional Knapsack
  //Find out weight of each item to be used
  vector <double> wt_in_knapsack(num_items_in_list, 0.0) ;
  vector <double> value_in_knapsack(num_items_in_list, 0.0) ;
  double remaining_bag_capacity = bag_wt_capacity;
  double wt_2add;
  int idx_concerned;
  int num_items_in_knapsack = 0;
  for(int i =0; i<num_items_in_list; i++){
      idx_concerned = sorted_indices[i];

      if(remaining_bag_capacity>0) {
          wt_2add = weights[idx_concerned];
          if(wt_2add >remaining_bag_capacity) {
              wt_2add                = remaining_bag_capacity;
          }
          wt_in_knapsack[i]      = wt_2add;
          value_in_knapsack[i]   = wt_2add*value_per_unit_weight[idx_concerned] ;
          remaining_bag_capacity -= wt_2add ;
      }//eof if(remaining_bag_capacity>0)
      else {
        if(INTERACTIVE == 1){
          cout <<"Bag Capacity Reached @ sorted index = " <<i<<endl;
        }
        num_items_in_knapsack = i;
        break;
      }
  }//eof for(int i =0; i<num_items_in_list; i++)

  bag_value = accumulate(value_in_knapsack.begin(), value_in_knapsack.end(), 0.0);

  if(INTERACTIVE == 1){
      cout<<"Item# \tValue \tWeight \tVpW \twt_knapsack  \tvalu_knapsack"<<endl;
      for(int i =0; i<num_items_in_list; i++){
        if(i==num_items_in_knapsack)
          cout<<"------------ Below Items Not in Knapsack -------------"<<endl;

        idx_concerned = sorted_indices[i];
        cout<<idx_concerned<<"\t";
        cout << fixed << showpoint;
        cout<<setprecision(2);
        cout<<values[idx_concerned]<<"\t";
        cout<<weights[idx_concerned]<<"\t";
        cout<<value_per_unit_weight[idx_concerned]<<"\t";
        cout<<wt_in_knapsack[i]<<"\t\t";
        cout<<value_in_knapsack[i]<<endl;
      }//eof for loop

      cout<<"bag_value = "<<bag_value<<endl;
  }//eof if(INTERACTIVE == 1)

  return bag_value;
}




int main() {
  int n;
  double capacity;
  cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  //cout.precision(10);
  cout << fixed << showpoint;
  cout<<setprecision(10);
  cout << optimal_value << endl;
  return 0;
}
