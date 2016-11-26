#include<stdio.h>
#define N 20
void printJZ(double a[][N],int m,int n)//��ӡ����
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

void changeH(double a[][N],int i,int j,int n)//�������У�i��j��nΪ������
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

void addH(double a[][N],int m,int n,int firstm,int firstn)//������֮��ӷ���m��nΪ������������������Ϊ��ʼ������������˲���ʹ����ʼ�����������Ϊ�㣻
{
    int i,j;
    double t;
    for(i=firstm+1; i<m; i++)
    {
        t=a[i][firstn]; //��Ϊ����ÿ�е�һ����Ϊ�㣻
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

int zeroL(double a[][N],int m,int n,int firstn,int firstm) //�ж��㡣
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
    if(a[firstm][firstn]==0)//�ǵ�һ�е�һ�е�����Ϊ�㣻
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

void Dezero(double a[][N],int m,int n)//ʹ-0��Ϊ0��
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
    printf("��������Ҫ�ľ�����С�������\n");
    while(~scanf("%d%d",&m,&n))
    {
        printf("���ľ���Ϊ��\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%lf",&a[i][j]);
            }
        }
        while(firstm<m && firstn<n)
        {
            while(zeroL(a,m,n,firstn,firstm))//�����������Ϊ�����Թ�����
            {
                firstn+=1;
            }
            FIRSTNOZERO(a,n,firstm,firstn);
            addH(a,m,n,firstm,firstn);
            firstm+=1;
        }
        printf("�н�����Ϊ���𰸲�Ψһ����\n");
        printJZ(a,m,n);
        first2first(a,m,n);
        Dezero(a,m,n);
        printf("�������Ϊ��\n");
        ZJX(a,m,n);
        Dezero(a,m,n);
        printJZ(a,m,n);
        printf("��������Ҫ�ľ�����С�������\n");
        firstm=0;
        firstn=0;
        double a[N][N]= {0};
    }
    getchar();
    return 0;
}
