#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool check1 = false;
    bool check2 = false;
    vector<long long int> arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for(int i=0,j=0; i<20 && j<20; i++,j++)
    {
        string s;
        cout << arr[i] << endl;
        cin >> s;
        if(s == "yes")
        {
            if(check1) {check2 = true; break;}
            else if(arr[i]<10)
            {
                string temp;
                cout << pow(arr[i],2) << endl;
                cin >> temp;
                if(temp == "yes") {check2 = true; check1 = true; break;}
                j++;
            }
            check1 = true;
        }
    }
    if(check1 && check2) {cout << "composite" << endl;}
    else cout << "prime" << endl;
}