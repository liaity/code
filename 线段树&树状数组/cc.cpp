#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
typedef long long ll;
const int maxis=5e4+2;
int n,num;
int tree[maxis];
int lowbit(int index){
    return index & -index;
}
void add(int i,int vaule){
    while(i<=n){
        tree[i]+=vaule;
        i+=lowbit(i);
    }
}
int query(int i){
    int sum=0;
    while(i>0){
        sum+=tree[i];
        i-=lowbit(i);
    }
    return sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        add(i,t);
    }
    string s;
    while(cin>>s&&s!="End"){
        int l,r;
        cin>>l>>r;
        if(s=="Query") cout<<query(r)-query(l-1)<<endl;
        else if(s=="Add") add(l,r);
        else if(s=="Sub") add(l,-r);
    }
}