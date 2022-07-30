#include<bits/stdc++.h>
#include<queue>
using namespace std;

int32_t main()
{
    queue <int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << "\n";
    q.pop();
    cout << q.front() << "\n";
    cout << q.size() << "\n";
    cout << q.empty() << "\n";

    while (!q.empty())
    {
        cout << q.front() << "\n";
        q.pop();
    }
}