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
        string s; cin >> s;
        map<int, int> mp;
        set<char> ss;
        for(int i=0; i<n; i++)
        {
            mp[i] = ss.size();
            ss.insert(s[i]);
        }
        long long int count = 0;
        count = count + ss.size();
        for(int i=n-1; i>=0; i--)
        {
            count = count + mp[i];
        }
        cout << count << endl;
    }
}