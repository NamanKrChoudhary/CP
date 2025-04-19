#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    long long int sum = 0;
    long long int ans = 0;
    for(int i=0,j=0; i<n; i++)
    {
        sum = sum + arr[i];
        while(sum > k && j<=i)
        {
            sum = sum - arr[j];
            j = j+1;
        }
        long long int comp = i-j+1;
        ans = max(ans,comp);
    }
    cout << ans << endl;
}