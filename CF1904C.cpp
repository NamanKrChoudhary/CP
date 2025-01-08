#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n,k;
        cin >> n >> k;
        vector<long long int> arr(n);
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        vector<long long int> temp = arr;
        sort(temp.begin(), temp.end());
        set<long long int> s;
        if(k == 1)
        {
            long long int minn = temp[0];
            for(int i=1; i<n; i++) minn = min(minn, (llabs(temp[i]-temp[i-1])));
            cout << minn << endl;
            continue;
        }
        else if(k>2)
        {
            cout << 0 << endl; continue;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++) s.insert(llabs(arr[i] - arr[j]));
        }
        long long int minn = min(*s.begin(), temp[0]);
        if(*(--s.end()) <= temp[0]) {s.insert(temp[0]-(*(--s.end()))); cout << *s.begin() << endl; continue;}
        else if(*s.begin() >= temp[n-1]) {cout << min(temp[0], (*s.begin()-temp[n-1])) << endl; continue;}
        for(auto i: s)
        {
            int it = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
            if(it < n) minn = min(minn, (temp[it]-i));
            if(it >0 ) minn = min(minn, (i-temp[it-1]));
        }
        // for(int i=0; i<n; i++)
        // {
        //     auto it = s.lower_bound(arr[i]);
        //     if(it != s.begin())
        //     {
        //         auto tt = it;
        //         tt--;
        //         minn = min(minn, (llabs(arr[i]-(*tt))));
        //     }
        //      minn = min(minn, llabs(arr[i] - (*it)));

        // }
        cout << minn << endl;
    }
}