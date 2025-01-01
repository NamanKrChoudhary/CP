#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n, c, d; cin >> n >> c >> d;
        map<long long int, long long int> arr;
        for(int i=0; i<n; i++)
        {
            long long int temp; cin >> temp;
            if(arr.find(temp) == arr.end()) arr[temp] = 1;
            else arr[temp] = arr[temp] + 1;
        }
        long long int dup = 0;
        for(auto i: arr)
        {
            dup = dup + i.second;
            i.second = dup;
        }
        long long int minn = 1000000000000000000;
        if(arr.find(1) == arr.end()) minn = min(minn, (c*n)+d);
        long long int j = 1;
        for(auto i: arr)
        {
            long long int temp = ((n-j)*c) + ((i.first - j)*d);
            minn = min(minn, temp);
            j++;
        }
        cout << minn << endl;
    }
}