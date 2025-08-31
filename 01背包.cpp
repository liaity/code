#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
typedef long long ll;

int n,num;
int v[1005],w[1005],number[105];
int t=0;
int lable[1005][1005];
int dp[1005];
int main(){
    cin>>n>>num;
    for(int i=1;i<=num;i++){
        int x;
        cin>>w[i]>>v[i]>>x;
        number[x]++;
        t=max(t,x);
        lable[x][number[x]]=i;
    }
    for(int i=1;i<=t;i++){
        for(int j=n;j>=1;j--){
            for(int p=1;p<=number[i];p++){
                if(j>=w[lable[i][p]])
                dp[j]=max(dp[j],dp[j-w[lable[i][p]]]+v[lable[i][p]]);
            }

            }
        }
    
    cout<<dp[n];
}
