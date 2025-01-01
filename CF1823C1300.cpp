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
        for(int i=0; i<n; i++)cin >> arr[i];
        map<long long int, int> mp;
        for(int i=0; i<n; i++)
        {
            long long int temp = arr[i];
            while(arr[i]%2 == 0)
            {
                mp[2] = mp[2]+1;
                arr[i] = arr[i]/2;
            }
            if(arr[i] > 0)
            {
                for(int j=3; j<= (sqrtl(temp)) && (arr[i]>0 && j <= arr[i]); j = j+2)
                {
                    //cout << arr[i] << " ";
                    while(arr[i]%j == 0)
                    {
                        mp[j] = mp[j] + 1;
                        arr[i] = arr[i]/j;
                    }
                }
            }
            if(arr[i] > 0 && arr[i] != 1) mp[arr[i]] = mp[arr[i]] + 1;
        }
        long long int ans = 0;
        long long int comp = 0;
        for(auto i: mp) {ans = ans + (i.second/2) ; comp = comp + (i.second%2); }
        ans = ans + (comp/3);
        cout << ans << endl;
    }
}