// Y0u_kn0w_th3_truth!
#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
const int inf=(1ll<<31)-1;
struct node{
    int to,nex;
}e[N];
int num,head[N],sum[N],lazy[N];
int n,m,root,dep[N],a[N],top[N];
int fa[N],son[N],size[N],pos[N],ch[N];
int f[N][21],tot;
int read(){
    int x=0,w=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*w;
}

void add(int from,int to){
    num++;
    e[num].to=to;
    e[num].nex=head[from];
    head[from]=num;
}

void build(int root,int left,int right){
    if(left==right){
        sum[root]=a[left];
        return ;
    }
    int mid=(left+right)>>1;
    build(root<<1,left,mid);build(root<<1|1,mid+1,right);
    sum[root]=min(sum[root<<1],sum[root<<1|1]);
}

void push(int root,int left,int right){
    lazy[root<<1]=lazy[root<<1|1]=lazy[root];
    sum[root<<1]=sum[root<<1|1]=lazy[root];
    lazy[root]=0;
}

void update(int root,int left,int right,int l,int r,int v){
    if(left>r||right<l)return ;
    if(left>=l&&right<=r){
        lazy[root]=sum[root]=v;
        return ;
    }
    if(lazy[root])push(root,left,right);
    int mid=(left+right)>>1;
    if(mid>=l) update(root<<1,left,mid,l,r,v);
    if(mid<r)  update(root<<1|1,mid+1,right,l,r,v);
    sum[root]=min(sum[root<<1],sum[root<<1|1]);
}

int query(int root,int left,int right,int l,int r){
    if(left>r||right<l)return inf;
    if(lazy[root])push(root,left,right);
    if(left>=l&&right<=r)return sum[root];
    int mid=(left+right)>>1;int ans1=inf,ans2=inf;
    if(mid>=l) ans1=query(root<<1,left,mid,l,r);
    if(mid<r)  ans2=query(root<<1|1,mid+1,right,l,r);
    return min(ans1,ans2);
}

void dfs1(int x){
    size[x]=1;
    for(int i=head[x];i;i=e[i].nex){
        int v=e[i].to;
        if(!dep[v]){
            dep[v]=dep[x]+1;fa[v]=x;
            f[v][0]=x;
            dfs1(v);size[x]+=size[v];
            if(size[son[x]]<size[v])son[x]=v;
        }
    }
}

void dfs2(int x,int tp){
    pos[x]=++tot;a[tot]=ch[x];top[x]=tp;
    if(son[x])dfs2(son[x],tp);
    for(int i=head[x];i;i=e[i].nex){
        int v=e[i].to;
        if(v!=fa[x]&&v!=son[x])dfs2(v,v);
    }
}

void init(){
    for(int i=1;i<=17;i++)
        for(int j=1;j<=n;j++)
        f[j][i]=f[f[j][i-1]][i-1];
}

void cal(int x,int y,int v){
    int fx=top[x],fy=top[y];
    while(fx!=fy){
        if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
        update(1,1,n,pos[fx],pos[x],v);
        x=fa[fx];fx=top[x];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,pos[x],pos[y],v);
}

int cal2(int x,int y){
    int fx=top[x],fy=top[y];
    while(fx!=fy){
        if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
        x=fa[fx];fx=top[x];
    }
    if(dep[x]>dep[y])return y;
    return x;
}

int find(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    if(f[x][0]==y)return x;
    for(int j=17;j>=1;j--)if(dep[f[x][j]]>=dep[y])x=f[x][j];
    if(f[x][0]==y)return x;
    for(int j=17;j>=0;j--)if(f[x][j]!=f[y][j])x=f[x][j],y=f[y][j];
    return x;
}

char s[201];

void key(){
    // char flag[30]="flag{Y0u_kn0w_th3_truth!}";
    // for(int i=0;i<25;i++){
    //     cout<<a[i]<<' ';
    // }cout<<endl;
    char b[30]={2,57,56,81,107,124,26,73,7,19,7,38,52,80,22,93,63,92,44,105,72,124,40,30,2};
    // for(int i=0;i<25;i++){
    //     b[i]=flag[i]^a[i]; 
    //     cout<<(int)(b[i])<<',';
    // }cout<<endl;

    for(int i=0;i<25;i++){ 
        if(b[i]!=(s[i]^a[i]))
            cout<<"No!"<<endl,
            exit(0);
    }cout<<"good!"<<endl;return ;
}

int main(){
    srand(1234);
    cout<<"please input the flag:"<<endl;
    cin>>s;
    cout<<"input more to find the key"<<endl;
    n=read();m=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    for(int i=1;i<=n;i++)ch[i]=read();
    root=read();
    fa[root]=root;dep[root]=1;
    dfs1(root);dfs2(root,root);build(1,1,n);init();
    for(int i=0;i<25;i++)a[i]=rand()%128;
    key();
    for(int i=1;i<=m;i++){
        int opt=read();
        if(opt==1)root=read();
        if(opt==2){int x=read(),y=read(),z=read();cal(x,y,z);}
        if(opt==3){
            int x=read();int lca=cal2(x,root);
            if(root==x){printf("%d\n",query(1,1,n,1,n));continue;}
            if(lca!=x){printf("%d\n",query(1,1,n,pos[x],pos[x]+size[x]-1));continue;}
            if(lca==x){
                int LCA=root;
                for(int i=17;i>=0;i--)
                if(dep[f[LCA][i]]>dep[x])LCA=f[LCA][i];
                int ans=min(query(1,1,n,1,pos[LCA]-1),query(1,1,n,pos[LCA]+size[LCA],n));
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}