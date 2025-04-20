#include<bits/stdc++.h>
using namespace std;
// first see that the negative values will work only if their positive values work. 
// place -y in place of y or -x in place of x either the values will be swapped or remain same.
// this means that you can shift all the elements from the left side of the number line to the right and then solve which will give the same answer.
// IMPORTAHT- as if an element  "a" works with some element "b" then "-a" will also work with element "b".
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) arr[i] = abs(arr[i]);
    sort(arr.begin(), arr.end());
    long long int ans = 0;
    for(int i=1; i<n; i++)
    {
        long long int s=0, e = i-1, mid = s+ ((e-s)/2);
        long long int temp = 0;
        while(s<=e)
        {
            mid = s + ((e-s)/2);
            if(arr[i]-arr[mid] > arr[mid]) {s = mid+1;}
            else {temp = i-mid; e = mid-1;}
        }
        ans = ans + temp;
    }
    cout << ans << endl;
}