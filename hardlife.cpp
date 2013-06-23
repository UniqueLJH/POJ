#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
double c[1100][1100]={0};
double w[1100]={0};
int n,m;
double maxflow=0;
double mincut(int start,int ends)
{

   int  pre[1100];
    while (1)
    {
        queue<int> p;
        double minflow=9999999.0;
        p.push(0);
        int oo;
        for (oo=0;oo<=n+m+1;oo++)
        {
            pre[oo]=-1;
        }
        while (!p.empty())
        {
            int u=p.front();
            printf("\n pop <- %d",p.front());
            p.pop();

            if (u==ends)
                break;
            int ii;
            for (ii=0;ii<=ends;ii++)
            {
                if (c[u][ii]>0&&pre[ii]==-1&&ii>0)
                {
                    pre[ii]=u;
                    p.push(ii);
                    printf("push ->%d",ii);
                }

            }

        }


            if (pre[ends]==-1)
            {
                printf("break");break;
            }
            else
            {
                int o=ends;
                int ii;
                for (ii=0;ii<=n+m+1;ii++)
                {
                    printf("%d ",pre[ii]);
                }
                for (o=ends;o!=start;o=pre[o])
                {

                    if (minflow>c[pre[o]][o]) {minflow=c[pre[o]][o];}
                    printf(" \\ %d->%d min=%0.2lf \\ ",pre[o],o,c[pre[o]][o]);
                }
                for (o=ends;o!=start;o=pre[o])
                {

                    c[pre[o]][o]-=minflow;
                    c[o][pre[o]]+=minflow;
                }
                maxflow+=minflow;
                printf("\nmaxflow=%lf\n",maxflow);
                }
        }
   printf("---AA-----");
        return maxflow;
    }

double  h( double g)
{
        int ii;
        for (ii=1;ii<=n;ii++)
        {
            w[ii]=-g;
            c[ii][n+m+1]=g;
        }
            for (int ii=0;ii<=n+m+1;ii++)
    {
        for (int jj=0;jj<=n+m+1;jj++)
        {
            printf("%6.1lf",c[ii][jj]);
        }
        printf("\n");
    }
        return m-mincut(0,n+m+1);
}
int main()
{

    scanf("%d%d",&n,&m);
    int i; int j;
    for (i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        w[n+i]=1;
        c[n+i][a]=999999;
        c[n+i][b]=999999;
        c[0][n+i]=1;
    }
    double g;
    scanf("%lf",&g);
    printf("%lf",h(g));
    printf("\n");




}
