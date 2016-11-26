#include<stdio.h>
#define N 20
void printJZ(double a[][N],int m,int n)//打印矩阵
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%lf ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void changeH(double a[][N],int i,int j,int n)//交换两行（i和j）n为列数；
{
    double t;
    int k;
    for(k=0; k<n; k++)
    {
        t=a[i][k];
        a[i][k]=a[j][k];
        a[j][k]=t;
    }
}

void addH(double a[][N],int m,int n,int firstm,int firstn)//矩阵行之间加法，m，n为行数和列数，后两个为起始行列数。做完此步骤使得起始数下面的数均为零；
{
    int i,j;
    double t;
    for(i=firstm+1; i<m; i++)
    {
        t=a[i][firstn]; //因为后面每行第一个变为零；
        for(j=firstn; j<n; j++)
        {
            a[i][j]=a[i][j]-(t/a[firstm][firstn])*a[firstm][j];
        }
    }
}

void addH2(double a[][N],int m,int n,int firstm,int firstn)
{
    int i,j;
    double t;
    for(i=firstm-1; i>=0; i--)
    {
        t=a[i][firstn];
        for(j=0; j<n; j++)
        {
            a[i][j]=a[i][j]-t*a[firstm][j];
        }
    }
}

int zeroL(double a[][N],int m,int n,int firstn,int firstm) //判断零。
{
    int t=0;
    int i;
    if(firstm>=m || firstn>=n) return 0;
    for(i=firstm; i<m; i++)
    {
        if(a[i][firstn]==0) t++;
    }
    if(t==m-firstm) return 1;
    else return 0;
}

void FIRSTNOZERO(double a[][N],int n,int firstm,int firstn)
{
    int i;
    if(a[firstm][firstn]==0)//是第一行第一列的数不为零；
    {
        for(i=firstm; i<n; i++)
        {
            if(a[i][firstn]!=0)
            {
                changeH(a,firstm,i,n);
                //puts("T1");
                break;
            }
        }
    }
}

void first2first(double a[][N],int m,int n)
{
    int i,j,tj;
    double t;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j]!=0)
            {
                t=a[i][j];
                tj=j;
                break;
            }
        }
        for(j=tj; j<n; j++)
        {
            a[i][j]/=t;
        }
    }
}

void ZJX(double a[][N],int m,int n)
{
    int i,j,firstm,firstn,t=0;
    for(i=m-1; i>=0; i--)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j]==1)
            {
                firstm=i;
                firstn=j;
                t=1;
                break;
            }
        }
        if(t==1)
        {
            addH2(a,m,n,firstm,firstn);
        }
    }
}

void Dezero(double a[][N],int m,int n)//使-0变为0；
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j]==-0)
                a[i][j]=0;
        }
    }
}

int main()
{
    int i,j,m,n;
    int firstm=0,firstn=0;
    double a[N][N]= {0},t;
    printf("请输入你要的矩阵的行、列数：\n");
    while(~scanf("%d%d",&m,&n))
    {
        printf("您的矩阵为：\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%lf",&a[i][j]);
            }
        }
        while(firstm<m && firstn<n)
        {
            while(zeroL(a,m,n,firstn,firstm))//如果此列数均为零则略过此列
            {
                firstn+=1;
            }
            FIRSTNOZERO(a,n,firstm,firstn);
            addH(a,m,n,firstm,firstn);
            firstm+=1;
        }
        printf("行阶梯形为（答案不唯一）：\n");
        printJZ(a,m,n);
        first2first(a,m,n);
        Dezero(a,m,n);
        printf("行最简形为：\n");
        ZJX(a,m,n);
        Dezero(a,m,n);
        printJZ(a,m,n);
        printf("请输入你要的矩阵的行、列数：\n");
        firstm=0;
        firstn=0;
        double a[N][N]= {0};
    }
    getchar();
    return 0;
}
