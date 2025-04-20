#include<bits/stdc++.h>
using namespace std;

int main()
{
    // long long int t;
    // cin >> t;
    // while(t--)
    // {
        long long int n,ss;
        cin >> n >> ss;
        vector<long long int> arr(n); 
        for(int i=0; i<n; i++) cin >> arr[i];
        long long int st = 1, e = n, mid = st + ((e-st)/2);
        long long int ans1 = 0, ans2 = 0;
        long long int ass = 0;
        while(st<=e)
        {
            ass = 0;
            mid = st + ((e-st)/2);
            multiset<long long int> s;
            for(int i=0; i<n; i++)
            {
                s.insert(arr[i]+((i+1)*mid));
            }
            long long int sum = 0, it = 0;
            for(auto i: s)
            {
                if(it>=mid) break;
                sum = sum + i;
                it = it + 1;
            }
            if(sum > ss) {e = mid-1;}
            else {ans1 = mid; ans2 = sum; st = mid+1;}
            for(auto i: s) ass = ass + i;
        }
        cout << ans1 << " " << ans2 << endl;
    //}
}