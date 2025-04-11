#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n; cin >> n;
    vector<string> ins(n);
    for(int i=0; i<n; i++) cin >> ins[i];
    vector<pair<long long int, long long int>> starts,ends;
    long long int zero = 0;
    for(int i=0; i<n; i++)
    {
        if(ins[i].size() > s.size()) continue;
        for(int j=0; j<=s.size()-ins[i].size(); j++)
        {
            bool check = true;
            for(int k=0; k<ins[i].size(); k++)
            {
                if(s[j+k] != ins[i][k]) {check =false; break;}
            }
            if(check)
            {
                pair<long long int, long long int> p1 = {j,i}, p2 = {j+ins[i].size()-1,j};
                starts.push_back(p1);
                ends.push_back(p2);
            }
        }
    }
    if(ends.empty())
    {
        cout << s.size() << " " << 0 << endl;
        return 0;
    }
    sort(ends.begin(), ends.end());
    vector<pair<long long int, long long int>> endf;
    if(ends.size()>1)
    {
        for(int i=1; i<ends.size(); i++)
        {
            if(ends[i].first == ends[i-1].first) ends[i].second = max(ends[i].second, ends[i-1].second);
            else endf.push_back(ends[i-1]);
        }
        endf.push_back(ends[ends.size()-1]);
    }
    else endf.push_back(ends[0]);
    sort(endf.begin(),endf.end());
    long long int ans = 0;
    long long int mxst = -1;
    long long int indi = 0;
    for(int i=0; i<endf.size(); i++)
    {
        long long int curr = max(zero,(endf[i].first - mxst-1));
        if(ans < curr)
        {
            indi = mxst+1;
        }
        ans = max(ans,curr);
        mxst = max(mxst,endf[i].second);
    }
    sort(starts.begin(), starts.end());

    long long int curr = s.size() - starts[starts.size()-1].first -1;
    if(ans < curr)
    {
        indi = mxst + 1;
    }
    ans = max (ans,curr);
    cout << ans << " " << indi << endl;
}