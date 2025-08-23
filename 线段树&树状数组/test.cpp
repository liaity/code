#include <iostream>
#include <string> 
using namespace std;
#include<algorithm>
#include<string.h>

typedef long long ll;
const int maxis = 2e5+2; 
int arr[maxis];  
int tree[maxis*4];

int n,num;
void built(int node,int l,int r){
    if(l==r){ 
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    built(2*node+1,l,mid);
    built(2*node+2,mid+1,r);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}
int query(int node,int sta,int end,int l,int r){
    if(r<sta || l>end) return -2e9;
    if(sta>=l&&end<=r) return tree[node];
    int mid=(sta+end)/2;
    int leftnode=query(2*node+1,sta,mid,l,r);
    int rightnode=query(2*node+2,mid+1,end,l,r);
    return max(leftnode,rightnode);
}
void update(int node,int l,int r,int index,int value){
    if(l==r){
        arr[index]=value;
        tree[node]=value;
        return;
    }
    int mid=(l+r)/2;
    if(index>=l&&index<=mid){
        update(node*2+1,l,mid,index,value);
    }else{
        update(node*2+2,mid+1,r,index,value);
    }
    tree[node]=max(tree[2*node+1],tree[2*node+2]);

}
int main(){
    while(cin>>num>>n){
    memset(tree,0,sizeof(tree));
    memset(arr,0,sizeof(arr));
    for(int i=0;i<num;i++) cin>>arr[i];
    built(0,0,num-1);
    while(n--){
        char cmd;
        int l,r;
        cin>>cmd>>l>>r;
        if(cmd=='Q'){ 
            if(l>r) swap(l,r);
            cout<<query(0,0,num-1,l-1,r-1)<<endl;
        }else{
            update(0,0,num-1,l-1,r);
        }
    }
}
}
