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
        vector<long long int> arr(n); 
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n == 1) {for(int i=0; i<n; i++) cout << 1 << endl; continue;}
        vector<pair<int,int>> mp;
        pair<int, int> p ;
        for(int i=1; i<n; i++)
        {
            if(arr[i] < arr[i-1]) {p.first = arr[i-1]-arr[i]; p.second = i; mp.push_back(p);}
        }
        int curr = 1;
        vector<int> ans;
        sort(mp.begin(), mp.end());
        for(auto i: mp)
        {
            int sub = i.first;
            while(sub > 0 && curr <= n)
            {
                sub = sub - curr;
                curr = curr + 1;
                ans.push_back(i.second + 1);
            }
            if(curr > n) break;
        }
        while(curr <= n)
        {
            ans.push_back(1);
            curr = curr + 1;
        }
        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
}