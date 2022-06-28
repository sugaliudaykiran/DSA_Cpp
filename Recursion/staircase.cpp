/*

    Ref :-  https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/

    Staircase
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 
    3 steps at a time. Implement a method to count how many possible ways the child can
     run up to the stairs. You need to return number of possible ways W.

    Input : 4
    Output : 7
    Explanation:
    Below are the seven ways
    1 step + 1 step + 1 step + 1 step
    1 step + 2 step + 1 step
    2 step + 1 step + 1 step 
    1 step + 1 step + 2 step
    2 step + 2 step
    3 step + 1 step
    1 step + 3 step

    Complexity Analysis: 

Time Complexity: O(3^n). 
The time complexity of the above solution is exponential, a close upper bound will be O(3^n). From each state, 3 recursive function are called. So the upperbound for n states is O(3n).
Space Complexity:O(1). 
As no extra space is required..

*/

#include<bits/stdc++.h>
using namespace std;

int staircase(int n){
    if (n == 0)
    {
        return 1;
    }
    
    if (n < 0)
    {
        return 0;
    }
    
    int res = staircase(n-1) + staircase(n-2) + staircase(n-3); 
    return res;
}

int stair(int n)        //  Dp approach..   TC -> O(n).. SC -> O(n)..
{
    int res[n+1];   
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;

    for (int i=3; i<=n; i++)
    {
        res[i] = res[i-1] + res[i-2] + res[i-3];
    }

    return res[n];
}

int32_t main()
{
    int n;
    cin >> n;

    cout << staircase(n) << "\n";
    cout << stair(n) << "\n";


}