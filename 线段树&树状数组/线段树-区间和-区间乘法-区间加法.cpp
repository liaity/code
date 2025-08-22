#include <iostream>
#include <string> 
using namespace std;
#include<algorithm>
#include<string.h>
#include<vector>
typedef long long ll;
const int MAX=1e5+2;
int m;
struct Node{
    ll sum;
    ll mul;
    ll add;
    ll end;
    ll sta=0;
}tress[4*MAX];

vector<ll> arr;

void built(int node,int l,int r){
    tress[node].sta=l;
    tress[node].end=r;
    tress[node].mul=1;
    tress[node].add=0;
    if(r==l){
        tress[node].sum=arr[r]%m;
        return;
    }
    int mid=(r+l)/2;
    built(2*node,l,mid);
    built(2*node+1,mid+1,r);
    tress[node].sum=(tress[node*2].sum+tress[2*node+1].sum)%m;
}
void push_down(int node){
    if(tress[node].mul!=1 || tress[node].add!=0){
        int l=node*2;
        int r=node*2+1;
        tress[l].sum=(tress[node].add*(tress[l].end-tress[l].sta+1)+tress[node].mul*tress[l].sum)%m;
        tress[l].mul=(tress[node].mul*tress[l].mul)%m;
        tress[l].add=(tress[node].mul*tress[l].add+tress[node].add)%m;
        tress[r].sum=(tress[node].add*(tress[r].end-tress[r].sta+1)+tress[node].mul*tress[r].sum)%m;
        tress[r].mul=(tress[node].mul*tress[r].mul)%m;
        tress[r].add=(tress[node].mul*tress[r].add+tress[node].add)%m;
        tress[node].mul = 1;
        tress[node].add = 0;
    }
}
void update_mul(int node,int l,int r,int k){
    int nowl=tress[node].sta;
    int nowr=tress[node].end;
    if(nowl>r||nowr<l) return;
    if(nowl>=l&&nowr<=r){
        tress[node].sum=tress[node].sum*k%m;
        tress[node].mul=tress[node].mul*k%m;
        tress[node].add=tress[node].add*k%m;
        return;
    }
    push_down(node);
    update_mul(2*node,l,r,k);
    update_mul(2*node+1,l,r,k);
    tress[node].sum=(tress[2*node].sum+tress[2*node+1].sum)%m;
}
void update_add(int node,int l,int r,int k){
    int nowl=tress[node].sta;
    int nowr=tress[node].end;
    if(nowl>r||nowr<l) return;
    if(nowl>=l&&nowr<=r){
        tress[node].sum=(tress[node].sum+(nowr-nowl+1)*k)%m;
        tress[node].add=(tress[node].add+k)%m;
        return;
    }
    push_down(node);
    update_add(2*node,l,r,k);
    update_add(2*node+1,l,r,k);
    tress[node].sum=(tress[2*node].sum+tress[2*node+1].sum)%m;
}
ll query(int node,int l,int r){
    int nowl=tress[node].sta;
    int nowr=tress[node].end;
    if(nowl>r || nowr<l)   return 0;
    if(nowl>=l&&nowr<=r){
        return tress[node].sum%m;
    }
    push_down(node);
    return (query(2*node,l,r)+query(2*node+1,l,r))%m;
}
int main(){
    int n,q;
    cin>>n>>q>>m;
    arr.resize(n+2);
    for(int i=1;i<=n;i++) cin>>arr[i];
    built(1,1,n);

    while(q--){
        int cmd;
        cin>>cmd;
        if(cmd==1){
            int r,l,k;
            cin>>l>>r>>k;
            update_mul(1,l,r,k);
        }else if(cmd==2){
            int r,l,k;
            cin>>l>>r>>k;
            update_add(1,l,r,k);           
        }else{
            int a,b;
            cin>>a>>b;
            int ans=query(1,a,b);
            cout<<ans<<endl;
        }
    }
}
