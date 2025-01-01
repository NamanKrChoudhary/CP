#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
        cin >> s;
        bool check = false;
        vector<long long int> arr;
        long long int count = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'a') {count = count + 1; check = true;}
            else if(s[i] == 'b') {arr.push_back(count); count = 0;}
        }
        if(s[s.size()-1] != 'b') arr.push_back(count);
        if(check == false) {cout << 0 << endl; return 0;}
        long long int ans = 1;
        for(int i=0; i<arr.size(); i++)
        {
            ans = (ans*(arr[i]+1))%1000000007;
        }
        cout << ans-1 << endl;
}