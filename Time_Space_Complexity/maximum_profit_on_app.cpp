#include<bits/stdc++.h>
using namespace std;

//  Ref :- https://www.geeksforgeeks.org/maximize-profit-that-can-be-earned-by-selling-an-item-among-n-buyers/

int maximumProfit2(int budget[], int n) {		//	TC -> O(n^2).. 	SC -> O(1)..	
    int max_profit = INT_MIN, price = 0;
    
    for (int i=0; i<n; i++)
    {
        price = budget[i];
        int count = 0;
        
        for (int j=0; j<n; j++)
        {
            if (price <= budget[j])
            {
                count++;
            }
        }
        
        max_profit = max(max_profit, price*count);
    }
    return max_profit;
}


int maximumProfit(int budget[], int n) {
													//	TC -> O(nlogn)..	SC -> O(1)..
    sort(budget, budget+n);
    
    int max_profit = INT_MIN, price = 0;
    
    for (int i=0; i<n; i++)
    {
    	price = budget[i];
        
        int count = n - i;
        
        max_profit = max(max_profit, price * count);
    }
    
    return max_profit;
}



int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
