#include <iostream>
#define usi unsigned usi
using namespace std;
usi divizor(usi x[], usi n2)
{
    usi i=1, j=1;
    while(j<=n2)
    {
        x[j++]=i;
        for(usi div=2; div<i; div++)
            if(i%div==0)
                x[j++]=div;
        i++;
    }
}
usi prima_cifra(usi n)
{
    if(n<9)
        return n;
    else
    {
        while(n>9)
            n=n/10;
    }
    return n;
}
usi ultima_cifra(usi n)
{
    return n%10;
}
usi cifra_maxima(usi n)
{
    usi maxim=-1;
    while(n>0)
    {
        if(n%10>maxim)
            maxim=n%10;
        n=n/10;
    }
    return maxim;
}
usi construirea_matricei(usi ma[9][9], usi x[], usi n)
{
    for(usi i=1;i<=n;i++)
    {
        for(usi j=1;j<=n;j++)
        {
            if(i+j<n+1)
                ma[i][j]=ultima_cifra(x[n*n+i+j]);
            if(i+j>n+1)
                ma[i][j]=prima_cifra(x[n*n+i+j]);
            if(i+j==n+1)
                ma[i][j]=cifra_maxima(x[n*n+i*i]);
        }
    }
}
usi construire_nr(usi ma[9][9], usi n)
{
    usi freq[10]={0};
    for(usi i=1;i<=n;i++)
    {
        for(usi j=1;j<=n;j++)
            freq[ma[j][i]]++;
        for(usi i=9;i>=1;i--)
        {
           if(freq[i]>0)
           {
               while(freq[i]>0)
               {
               cout<<i;
               freq[i]--;
               }
           }
        }
        cout<<" ";
    }
}
usi main()
{
    usi n, n2, ma[9][9];
    cin>>n;
    n2=2*(n*n);
    usi x[n2+1];
    divizor(x,n2);
    construirea_matricei(ma,x,n);
    construire_nr(ma,n);
}
