#include <iostream>
#include <string> 
using namespace std;
#include<algorithm>
#include<string.h>
typedef long long ll;

int C[505][505];
int h[505],t[505],c[505];

int H,T,num;

int main(){
    cin>>H>>T>>num;
    for(int i=1;i<=num;i++) cin>>h[i]>>t[i]>>c[i];
    for(int i=1;i<=num;i++){
        for(int j=T;j>=t[i];j--){
            for(int o=H;o>=h[i];o--){
                C[o][j]=max(C[o][j],C[o-h[i]][j-t[i]]+c[i]);
            }
        }
    }
    cout<<C[H][T];
    return 0;
}
