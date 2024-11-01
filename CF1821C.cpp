#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        long long int minn = LONG_MAX;
        for(int i=0; i<26; i++)
        {
            long long int maxx = LONG_MIN;
            long long int count = 0; 
            bool check = false;
            for(int j=0; j<s.size(); j++)
            {
                if(check)
                {
                    if(s[j] == 'a'+i) {maxx = max(maxx, count); count = 0; check = false;}
                    else count = count + 1;
                }
                else 
                {
                    if(s[j] != 'a'+i) {count = count + 1; check = true;}
                }
                maxx = max(maxx, count);
            }
            minn = min(minn, maxx);
        }
        long long int ans = 0;
        while(minn)
        {
            ans++;
            minn = minn/2;
        }
        cout << ans << endl;
    }
}