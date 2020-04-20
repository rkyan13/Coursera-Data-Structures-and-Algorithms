/*
Problem Introduction
You have n ads to place on a popular Internet page. For each ad, you know how
much is the advertiser willing to pay for one click on this ad. You have set up n
slots on your page and estimated the expected number of clicks per day for each
slot. Now, your goal is to distribute the ads among the slots to maximize the
total revenue.

Problem Description
Task.
Given two sequences a1 , a2 , . . . , an (ai is the profit per click of the i-th ad) and b 1 , b 2 , . . . , bn (bi is
the average number of clicks per day of the i-th slot), we need to partition them into n pairs (ai, bj)
such that the sum of their products is maximized.

Input Format. The first line contains an integer n, the second one contains a sequence of integers
a1 , a2 , . . . , an , the third one contains a sequence of integers b1 , b2 , . . . , bn .

Constraints. 1 ≤ n ≤ 10^3 ; −10^5 ≤ a i , b i ≤ 10^5 for all 1 ≤ i ≤ n.

Output Format. Output the maximum value of

∑︀ai*ci , where c1 , c2 , . . . , cn is a permutation of b1 , b2 , . . . , bn .

--------------------------------------------
Sample 1.

Input:
1
23
39

Output:
897

897 = 23 · 39.
--------------------------------------------
Sample 2.

Input:
3
1 3 -5
-2 4 1

Output:
23

23 = 3 · 4 + 1 · 1 + (−5) · (−2).
--------------------------------------------
*/

/*
Intuition: (that I found online @ https://math.stackexchange.com/questions/2215935/choosing-the-permutation-which-maximizes-a-weighted-sum)
Nice way to think about it Geometrically that you are directionally aligning the vectors
Algebraically, to maximize a weighted sum, we want to put the heaviest weights 𝑥𝑘 on the heaviest values of 𝑦𝜎(𝑘).
The easiest way to do that is to order them in the same way. In other words,

𝑚𝑎𝑥{∑𝑘=1𝑛𝑥𝑘𝑦𝜎(𝑘)}=∑𝑘=1𝑛𝑥𝑘𝑦𝑘
Geometrically, the permutation of 𝑦𝜎(𝑘) which satisfies this condition would be the one which is ordered in the same direction as 𝑥𝑘.
To maximize the dot product, we maximize the cosine or minimize the angle between these two vectors.
Since permutations would only change the direction of the vector, not its length, we pick the permutation which points in the same increasing direction as 𝑥𝑘.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INTERACTIVE = 0;

vector<int> sort_vect(vector<int> x) {
  int temp_variable;
  //sort in ascending order
  for(int i =0; i <x.size(); i++)
  { for(int j = i; j < x.size(); j++)
    { if(x[j]<x[i]) //keep swapping until  subsequent x[i] is smallest
      { temp_variable = x[i];
        x[i] = x[j];
        x[j] = temp_variable;
      }
    } //eof for j
  }//eof for i

  return x;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  vector<int> a_sorted = sort_vect(a);
  vector<int> b_sorted = sort_vect(b);
  if(INTERACTIVE == 1){
    cout<<"a_sorted"<<endl;
    for(int i = 0; i < a_sorted.size(); i++)
        cout<<a_sorted[i]<<" ";
    cout<<endl;

    cout<<"b_sorted"<<endl;
    for(int i = 0; i < a_sorted.size(); i++)
        cout<<b_sorted[i]<<" ";
    cout<<endl;
  }

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a_sorted[i]) * b_sorted[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
