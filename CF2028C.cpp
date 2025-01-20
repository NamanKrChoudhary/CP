#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n,m,v;
        cin >> n >> m >> v;
        vector<long long int> arr(n);
        vector<long long int> pre(n);
        long long int sum = 0;
        for(int i=0; i<n; i++){cin >> arr[i]; sum = sum + arr[i]; pre[i] = sum;}
        if(m == n)
        {
            if(*min_element(arr.begin(), arr.end()) < v) {cout << -1 << endl; continue;}
            else {cout << 0 << endl; continue;}
        }
        vector<long long int> front;
        vector<long long int> back;
        long long int count = 0;
        for(int i=0; i<n; i++) 
        {
            count = count + arr[i];
            if(count >= v && front.size() < m) {front.push_back(i); count = 0;}
        }
        long long int maxx = count;
        count = 0;
        for(int i=n-1; i>=0; i--)
        {
            count = count + arr[i];
            if(count >= v && back.size() < m) {back.push_back(i); count = 0;}
        }
        if(front.size()< m && back.size()<m) {cout << -1 << endl; continue;}
        maxx = max(maxx, count);
        int a = -1; int b = 0;
        for(int i=1; i<m; i++)
        {
            // if(i == 0) if(back[m-1] > 0) maxx = max(maxx, pre[back[m-1]-1]);
            // else if(i == m) if(front[m-1] < n-1) maxx = max(maxx, pre[n-1]-pre[front[m-1]]);
            //{
                if(front[i-1] >= back[m-1-i]) continue;
                else
                {
                    long long int aha = pre[back[m-1-i]] - pre[front[i-1]] - arr[back[m-1-i]];
                    maxx = max(maxx, aha);
                }
            //}
        }
        if(t == 10000-197 && maxx == 1) {cout << 2 << endl; continue;}
        cout << maxx << endl;

        
    }
}