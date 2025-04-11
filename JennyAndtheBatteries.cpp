#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k;
    cin >> n >> k;
    vector<vector<long long int>> arr;
    long long int sum = 0;
    for(int i=0; i<n; i++)
    {
        vector<long long int> temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        arr.push_back(temp);
        sum = sum + temp[0];
    }
    sort(arr.begin(), arr.end());
    vector<vector<long long int>> carr = arr;
    for(int i=0; i<n; i++) swap(carr[i][0], carr[i][2]);
    sort(carr.begin(), carr.end());
    long long int s = sum/n, e = arr[n-1][0], mid = s+((e-s)/2);
    if(sum%n != 0) s = s+1;
    long long int ans = 0;
    while(s<=e)
    {
        mid = s + ((e-s)/2);
        vector<vector<long long int>> smol,big;
        for(int i=0; i<n; i++)
        {
            if(carr[i][2] > mid) big.push_back(carr[i]);
            else smol.push_back(carr[i]);
        }
        long long int sum = 0;
        for(int i=0, j=0; i<smol.size() && j<big.size();)
        {
            long long int left = mid - smol[i][2], right = big[j][2] - mid;
            if(left > right)
            {
                smol[i][2] = smol[i][2]+right;
                big[j][2] = mid;
                sum = sum + (right*smol[i][0])+ (right*big[j][1]);
                j = j+1;
            }
            else if(right > left)
            {
                smol[i][2] = mid;
                big[j][2] = big[j][2]-left;
                sum = sum + (left*smol[i][0]) + (right*big[j][1]);
                i = i+1;
            }
            else
            {
                smol[i][2] = mid; big[j][2] = mid;
                sum = sum + (left*smol[i][0]) + (left*big[j][1]);
                i = i+1; j = j+1;
            }
        }
        if(sum > k) {s = mid+1;}
        else if(sum <= k){e = mid-1; ans = mid;}
    }
    cout << ans << endl;
}