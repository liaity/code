#include <iostream>
#include <string> 
using namespace std;
#include<algorithm>
#include<string.h>
typedef long long ll;

const int MAX=1e5+105;

int list[350];
ll dp[1050][1050];
int arr[350];
int main(){
    string s;
    cin>>s;
    int n=s.length();
    for(int len=2;len<=n;len++){
        for(int l=0;l<=n-len;l++){
            int r=l+len-1;
            if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1];
            else{
                dp[l][r]=min(dp[l+1][r],dp[l][r-1])+1;
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
