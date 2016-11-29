#include<stdio.h>
#include<math.h>
#define N 20

void juzhenjiafa()
{
    int m,n,i,j;  //mΪ������nΪ������i��j���ڿ���ѭ��
    float a[20][20],b[20][20];

    printf("���������������\n");
    scanf("%d",&m);
    printf("���������������\n");
    scanf("%d",&n);

    printf("�������һ������\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&a[i][j]);//����ѭ�������һ������

    printf("������ڶ�������\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&b[i][j]);//����ѭ������ڶ�������

    printf("������ӵĽ��Ϊ��\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%f ",a[i][j]+b[i][j]);
        printf("\n");
    }
}

void juzhenjianfa()
{
    int m,n,i,j;//mΪ������nΪ������i��j���ڿ���ѭ��
    float a[20][20],b[20][20];

    printf("���������������\n");
    scanf("%d",&m);
    printf("���������������\n");
    scanf("%d",&n);

    printf("�������һ������\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&a[i][j]);

    printf("������ڶ�������\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&b[i][j]);

    printf("��������Ľ��Ϊ��\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%f ",a[i][j]-b[i][j]);
        printf("\n");
    }
}

void juzhenchengfa()
{
    int m,n,p,q;
    float s;
    float a[20][20],b[20][20],c[20][20];
    int i,j,k;

    printf("�������һ������������");
    scanf("%d",&m);
    printf("�������һ������������");
    scanf("%d",&n);
    printf("������ڶ�������������");
    scanf("%d",&p);
    printf("������ڶ�������������");
    scanf("%d",&q);
    if(n!=p) printf("������󣡵�һ�����������Ӧ���ڵڶ��������������\n");
    else
    {
        printf("�������һ������");
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%f",&a[i][j]);

        printf("������ڶ�������");
        for(i=0; i<p; i++)
            for(j=0; j<q; j++)
                scanf("%f",&b[i][j]);
        for(i=0; i<m; i++) //����ѭ�����������ÿ��Ԫ��ֵ�������µľ���
        {
            for(j=0; j<p; j++)
            {
                s=0;
                for(k=0; k<n; k++)
                {
                    s=s+a[i][k]*b[k][j];
                }
                c[i][j]=s;
            }
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<m; j++)

                printf("%f ",c[i][j]);

            printf("\n");
        }
    }
}


void juzhenzhuanzhi()
{
    int m,n;
    float a[20][20],b[20][20];
    int i,j;

    printf("���������������");
    scanf("%d",&m);
    printf("���������������");
    scanf("%d",&n);

    printf("������һ������");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&a[i][j]);

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            b[i][j]=a[j][i];
            printf("%f ",b[i][j]);
        }
        printf("\n");
    }
}



//����ȥ������κ�����Ŀ�ʼ��
void printJZ(double a[][N],int m,int n)//��ӡ����
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%.3lf     ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void changeH(double a[][N],int i,int j,int n)//�������У�i��j��nΪ������������
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

void addH(double a[][N],int m,int n,int firstm,int firstn)//������֮��ӷ���m��nΪ������������������Ϊ��ʼ������������˲���ʹ��ÿ�������һ������Ԫ���������Ϊ�㣻
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

void addH2(double a[][N],int m,int n,int firstm,int firstn)//�����н��мӷ����������ϡ�����˲���ʹ��1�����������е�Ψһ����Ԫ��
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

int zeroL(double a[][N],int m,int n,int firstn,int firstm) //�жϴ��о�Ϊȫ��Ԫ�У�
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


int zeroPow(double a[][N],int m,int n) //�ж����Ƿ�ȫ0����������
{
    int j,t=0;
    for(j=0; j<n; j++)
    {
        if(a[m][j]!=0)
        {
            t=1;
        }
        break;
    }
    if(t=0)
        return 0;
    if(t=1)
        return 1;
}

void FIRSTNOZERO(double a[][N],int n,int firstm,int firstn)//ʹ���еķ���Ԫ����Ԫǰ��
{
    int i;
    if(a[firstm][firstn]==0)
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

void first2first(double a[][N],int m,int n)//ʹ��ÿһ�������һ������ԪΪ1��
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

void ZJX(double a[][N],int m,int n)//����εĻ��򣬺�addH2���ʹ��
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

void Dezero(double a[][N],int m,int n)//ʹ-0��Ϊ0��Ŀ����Ϊ���������
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

void zjx_qn()
{
    int i,j,m,n;
    int count=0;
    int firstm=0,firstn=0;
    double b[N][N]= {0};
    double c[N][N]= {0};
    double a[N][N]= {0},t;


    printf("���������������\n");
    scanf("%d",&m);
    printf("���������������\n");
    scanf("%d",&n);
    printf("���ľ���Ϊ��\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%lf",&b[i][j]); //��΢�޸� aΪ���� bΪԭ�� cΪ����
        }
    }


    for(i=0; i<m; i++)   //Ϊ��������������֮�������������
    {
        for(j=0; j<2*n; j++)
        {
            if (j<n)
            {
                a[i][j]=b[i][j];
            }
            else if((j-n)==i)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }

        }
    }


    while(firstm<m && firstn<n)
    {
        while(zeroL(a,m,n,firstn,firstm))//�����������Ϊ�����Թ�����
        {
            firstn+=1;
        }
        FIRSTNOZERO(a,n,firstm,firstn);
        addH(a,m,2*n,firstm,firstn);
        firstm+=1;
    }
    printf("�н�����Ϊ���𰸲�Ψһ����\n");
    printJZ(a,m,n);


    first2first(a,m,2*n);
    Dezero(a,m,2*n);

    printf("�������Ϊ��\n");
    ZJX(a,m,2*n);

    Dezero(a,m,2*n);
    printJZ(a,m,n);


    //��ӡ����󲿷�
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            c[i][j]=a[i][j+n];//ȡ�Ҳ�
        }

    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            b[i][j]=a[i][j];//ȡ��
        }

    }

    if (zeroPow(b,m,n)!=0) count=1; //�ж����һ���Ƿ�Ϊ�㣬��Ϊ����û���棻
    if(m!=n)
    {
        puts("���Ƿ����Ҳ������ (0*0) \n");
    }
    else if(count!=0)
    {
        puts("����������ɶ����Ӵ (0o0) \n");
    }

    else
    {
        puts("������������ ��������������(^o^) ");
        printJZ(c,m,n);
    }

}



void choose()
{
    int w;
    printf("1.����ӷ�\n");
    printf("2.�������\n");
    printf("3.����˷�\n");
    printf("4.����ת��\n");
    printf("5.����������κ��棨�����ڣ�\n");
    printf("6.�˳�\n");
    printf("\n");
    printf("��ѡ��Ҫ���е����㣺");
    scanf("%d",&w);

    switch(w)
    {
    case 1:
        juzhenjiafa();
        break;
    case 2:
        juzhenjianfa();
        break;
    case 3:
        juzhenchengfa();
        break;
    case 4:
        juzhenzhuanzhi();
        break;
    case 5:
        zjx_qn();
        break;
    case 6:
        exit(-1);
        break;
    }
}


int main(void)
{
    while(1)choose();
    return 0;
}
