#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,d;
    cin >> n >> d;
    vector<pair<long long int, long long int>> p;
    for(int i=0; i<n; i++)
    {
        pair<long long int, long long int> temp;
        cin >> temp.first >> temp.second;
        p.push_back(temp);
    }
    sort(p.begin(), p.end());
    long long int ans = 0;
    long long int curr = 0;
    for(int i=0,j=0; i<n; i++)
    {
        curr = curr + p[i].second;
        while(p[i].first - p[j].first >= d) {curr = curr-p[j].second; j = j+1;}
        ans = max(ans, curr); 
    }
    cout << ans <<  endl;
}