#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const LL mod = 1e9+7LL;

struct Matrix
{
    Matrix() { memset(m,0,sizeof(m)); }
    void display()
    {
        puts("--------------");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                cout<<m[i][j]<<" ";
            cout<<endl;
        }
        puts("--------------");
    }
    LL m[3][3];
};


Matrix mul(Matrix &a,Matrix &b)
{
    Matrix ret;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                ret.m[i][j] = (ret.m[i][j] + (a.m[i][k]*b.m[k][j])%mod)%mod; 
            }
        }
    }
    return ret;
}

Matrix QuickPower(Matrix &a,LL n)
{
    Matrix E;
    for(int i=0;i<3;i++) E.m[i][i]=1;
    Matrix p = a;

    while(n)
    {
        if((n&1LL)==1LL)
        {
            E = mul(E,p);
        }
        p = mul(p,p);
        n = n>>1LL;
    }

    return E;
}

Matrix Setvalue()
{
    int a[3][3];
    memset(a,0,sizeof(a));
    a[0][0]=1; a[0][1]=1; a[0][2]=1;
    a[1][0]=1; a[1][2]=1;
    a[2][0]=1;

    Matrix ret;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ret.m[i][j]=a[i][j];
    return ret;
}

LL getSum(Matrix M,int* w)
{
    LL sum=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum = (sum + w[i]*M.m[j][i])%mod;
        }
    }
    return sum;
}

LL n;

int main()
{
    /*
    Matrix a;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a.m[i][j]=(i+1)*(1+j);
    a.display();
    Matrix r = QuickPower(a,6);
    r.display();
    */  
    int T_T;
    scanf("%d",&T_T);
while(T_T--)
{
    //scanf("%lld",&n);
    cin>>n;

    if(n%2LL==0LL)
    {
        LL p = n/2-1; 
        Matrix A = Setvalue();
        A = QuickPower(A,p);
        //A.display();
        int w[3] = {1,1,1};
        //printf("%lld\n",getSum(A,w));
        cout<<getSum(A,w)<<endl;
    }
    else if(n%2LL==1LL)
    {

        LL p = (n-1)/2-1;
        Matrix A = Setvalue();
        A = QuickPower(A,p);
        int w[3] = {2,1,1};
        //printf("%lld\n",getSum(A,w));
        cout<<getSum(A,w)<<endl;
    }
}
    return 0;
}
