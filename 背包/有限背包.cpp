#include <iostream>
#include <string> 
using namespace std;
#include<algorithm>
#include<string.h>
typedef long long ll;

const int MAX=1e5+105;


struct r{
    int value;
    int wight;
}list[MAX];
int n,w;
int dp[MAX];
int main(){
    cin>>n>>w;
    int index=0;
    for(int i=1;i<=n;i++){
        int c=1,vi,wi,mi;
        cin>>vi>>wi>>mi;
        while(mi>c){
            mi-=c;
            list[++index].value=vi*c;
            list[index].wight=wi*c;
            c*=2;
        }
        list[++index].value=vi*mi;
        list[index].wight=wi*mi;
    }
    for(int i=1;i<=index;i++){
        for(int j=w;j>=list[i].wight;j--){
            dp[j]=max(dp[j],dp[j-list[i].wight]+list[i].value);
        }
    }
    cout<<dp[w];

}
