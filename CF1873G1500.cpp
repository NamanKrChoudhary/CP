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
        long long int count = 0;
        long long int maxx = 0;
        bool check = false;
        for(int i=0; i<s.size(); i++)
        {
            if(check == false)
            {
                if(s[i] == 'B') {check = true; count = count + 1;}
            }
            else 
            {
                if(s[i] == 'A') {check = false; maxx = max(maxx, count); count = 0;}
                else count = count + 1;
            }
        }
        if(check) maxx = max(maxx, count);
        check = false;
        count = 0;
        long long int minn = s.size();
        for(int i=0; i<s.size(); i++)
        {
            if(check == false)
            {
                if(s[i] == 'A') {check = true; count = count + 1;}
            }
            else 
            {
                if(s[i] == 'B') {check = false; minn = min(minn, count); count = 0;}
                else count = count + 1;
            }
        }
        if(check) minn = min(minn, count);
        count = 0;
        for(int i=0; i<s.size(); i++) if(s[i] == 'A') count = count + 1;
        if(count == s.size()){cout << 0 << endl; continue;}
        if(s[0] == 'B' || s[s.size()-1] == 'B') {cout << count << endl; continue;}
        else if(maxx >1) {cout << count << endl; continue;} 
        else {cout << count - minn << endl; continue;}
    }
}