#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m,n;
    cin >> n >> m;
    vector<long long int> arr(n), brr(m);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<m; i++) cin >> brr[i];
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    long long int s = 0, e = max(arr[n-1],brr[m-1]) - min(arr[0],brr[0]), mid = s + ((e-s)/2);
    long long int ans = e;
    while(s<=e)
    {
        mid = s + ((e-s)/2);
        bool check = true;
        for(int i=0; i<n; i++)
        {
            long long int req = arr[i]-mid;
            long long int present = *lower_bound(brr.begin(), brr.end(), req);
            if(present >= req && present <= arr[i]+mid) check = true;
            else {check = false; break;}
        }
        if(check) {ans = min(mid,ans); e = mid-1;}
        else s = mid+1;
    }
    cout << ans << endl;
}