#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n,m,k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        vector<int> pre(s.size());
        long long int count = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '1') count = count + 1;
            pre[i] = count;
        }
        // p.first = 0;
        // for(int i=0; i<n; i++)
        // {
        //     if(check && s[i] == '1') count = count + 1;
        //     else if(check && s[i] == '0') {o.push_back(count); check = false; count = 1; p.second = i-1; oo.push_back(p); p.first = i;}
        //     else if(check == false && s[i] == '0') count = count + 1; 
        //     else if(check == false && s[i] == '1') {z.push_back(count); check = true; count = 1; p.second = i-1; zz.push_back(p); p.first = i;}
        // }
        // p.second = n-1;
        // if(check ) {o.push_back(count); oo.push_back(p);}
        // else {z.push_back(count); zz.push_back(p);}
        // long long int ans = 0;
        // if(zz.size() <= 1)
        // {
        //     for(int i=0; i<z.size(); i++)
        //     {
        //         long long int temp = z[i];
        //         if(z[i] < m) continue;
        //         while(temp>=m)
        //         {
        //             temp = (temp-(m-1+k));
        //             ans = ans + 1;
        //         }
        //     }
        //     cout << ans << endl;
        //     continue;
        // }
        // for(int i=0; i<z.size(); i++)
        // {
        //     if(z[i] < m) continue;
        //     while(temp>=m)
        //     {
        //         temp = (temp-(m-1+k));
        //         ans = ans + 1;
        //     } 
        // }
        
        long long int ans = 0;
        for(int i=0, j=m-1; i<n && j<n; i++,j++)
        { 
            if(pre[j]-pre[i] == 0 && (s[i] != '1' && s[j] != '1')) {ans = ans + 1; i = j+k-1; j = i+m-1; continue;}
        }
        cout << ans << endl;
    }
}