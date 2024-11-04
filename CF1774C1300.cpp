#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> pre(s.size());
        int lz = -1, lo = -1;
        for(int i=0; i<n-1; i++)
        {
            if(s[i] == '1') {lo = i; pre[i] = lz; continue;}
            else {lz = i; pre[i] = lo; continue;}
        }
        for(int i=1, j=2; i<n; i++,j++)
        {
            if(s[i-1] == '0') 
            {
                if(pre[i-1] == -1) cout << 1 << " ";
                else cout << j-(i-1-pre[i-1]) << " ";
            }
            else 
            {
                if(pre[i-1] == -1) cout << 1 << " ";
                else cout << j-(i-1-pre[i-1]) << " ";
            }
        }
        cout << endl;
    }
}
