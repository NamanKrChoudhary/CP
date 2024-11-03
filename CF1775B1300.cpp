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
        map<int, int> mp;
        vector<vector<int>> arr(n);
        for(int i=0; i<n; i++)
        {
            int c ;
            cin >> c;
            vector<int> temp(c);
            for(int j=0; j<c; j++)
            {
                cin >> temp[j];
                mp[temp[j]]++;
            }
            arr[i] = temp;
        }
        bool check = true;
        for(int i=0; i<n; i++)
        {
            check = true;
            for(int j=0; j<arr[i].size(); j++)
            {
                if(mp[arr[i][j]] < 2) { check = false; break;}
            }
            if(check == true) break;
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}