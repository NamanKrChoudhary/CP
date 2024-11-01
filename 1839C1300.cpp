#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {cin >> arr[i];}
        bool check = arr[0];
        if(arr[arr.size()-1] == 1) {cout << "NO" << endl; continue;}
        else cout << "YES" << endl;
        vector<int> gaps;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(check == arr[i]) count++;
            else {gaps.push_back(count); check = arr[i]; count = 1;}
            if(i == n-1) gaps.push_back(count);
        }
        reverse(gaps.begin(), gaps.end());
        for(int i=0; i<gaps.size(); i++)
        {
            int no = gaps[i];
            if(i%2 == 0) no--;
            while(no--)
            {
                cout << 0 << " ";
            }
            if(i%2 == 1) cout << gaps[i] << " ";
        }
        if(gaps.size()%2 == 1) cout << 0 <<  " ";
        cout << endl;
    }
    
}