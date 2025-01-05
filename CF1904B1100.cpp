#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> arr(n), pre(n);
        long long int in = 0, count = 0;
        for(int i=0; i<n; i++)
        {
            cin >> in;
            arr[i] = in;
        }
        vector<long long int> temp = arr;
        sort(temp.begin(), temp.end());
        vector<long long int> ans(n);
        count = 0;
        for(int i=0;i <n; i++)
        {
            count = count + temp[i];
            pre[i] = count;
        }
        map<long long int, long long int> mp;
        if(n == 1) {cout << 0 << endl; continue;}
        vector<int> huh;
        for(int i=1; i<n; i++)
        {
            if(temp[i] > pre[i-1]) huh.push_back(i);
        }
        if(huh.empty())
        {
            for(int i=0; i<n; i++) cout << n-1 << " ";
            cout << endl; continue; 
        }
        int j = 0;
        for(auto i: huh)
        {
            for(; j<i; j++) mp[temp[j]] = i-1;
        }
        for(; j<n; j++) mp[temp[j]] = n-1;
        // for(int i=0; i<n; i++)
        // {
        //     if(mp.find(temp[i]) == mp.end())
        //     {
        //         long long int it = lower_bound(temp.begin(), temp.end(), pre[i]) - temp.begin();
        //         if(it > 0 && (it < n && temp[it] != pre[i])) it = it-1;
        //         else if(it >= n) it = it-1;
        //         mp[temp[i]] =  it;
        //     }
        //     else
        //     {
        //         long long int it = lower_bound(temp.begin(), temp.end(), pre[i]) - temp.begin();
        //         if(it > 0 && (it < n && temp[it] != pre[i])) it = it-1;
        //         else if(it>= n) it = it-1;
        //         mp[temp[i]] = max(it, mp[temp[i]]);
        //     }
        // }
        for(long long int i=0; i<n; i++)
        {
            ans[i] = mp[arr[i]];
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}