#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

/*
Note maximum fibonacci number than can be dealt with is n = 92
n = 92. fibonacci(92) =  7540113804746346429 : no overflow
n = 93. fibonacci(93) = -6246583658587674878 : overflow
*/


long long int fibonacci_naive(int n) {
    if (n <= 1)
        return (long long)n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long int fibonacci_fast(int n) {
    // write your code here
    if (n <= 1)
        return (long long)n;

    vector <long long int> fibVect(n+1);
    fibVect[0] = 0;
    fibVect[1] = 1;
    for(int i=2; i<n+1; i++) {
      fibVect[i]= fibVect[i-1]+fibVect[i-2];
    }

    return fibVect[n];
}

void stress_test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    cin >> n;
    cout << fibonacci_fast(n) << '\n';
    //ksw: Comment following 2 lines before submission
    cout << fibonacci_naive(n) << '\n';
    stress_test_solution();
    return 0;
}
