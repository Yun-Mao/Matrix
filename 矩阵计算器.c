#include<stdio.h>
#include<math.h>
#define N 20

void juzhenjiafa()
{
    int m,n,i,j;  //m为行数，n为列数，i和j用于控制循环
    float a[20][20],b[20][20];

    printf("请输入矩阵行数：\n");
    scanf("%d",&m);
    printf("请输入矩阵列数：\n");
    scanf("%d",&n);

    printf("请输入第一个矩阵：\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&a[i][j]);//利用循环输入第一个矩阵

    printf("请输入第二个矩阵：\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&b[i][j]);//利用循环输入第二个矩阵

    printf("矩阵相加的结果为：\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%f ",a[i][j]+b[i][j]);
        printf("\n");
    }
}

void juzhenjianfa()
{
    int m,n,i,j;//m为行数，n为列数，i和j用于控制循环
    float a[20][20],b[20][20];

    printf("请输入矩阵行数：\n");
    scanf("%d",&m);
    printf("请输入矩阵列数：\n");
    scanf("%d",&n);

    printf("请输入第一个矩阵：\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&a[i][j]);

    printf("请输入第二个矩阵：\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%f",&b[i][j]);

    printf("矩阵相减的结果为：\n");
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

    printf("请输入第一个矩阵行数：");
    scanf("%d",&m);
    printf("请输入第一个矩阵列数：");
    scanf("%d",&n);
    printf("请输入第二个矩阵行数：");
    scanf("%d",&p);
    printf("请输入第二个矩阵列数：");
    scanf("%d",&q);
    if(n!=p) printf("输入错误！第一个矩阵的列数应等于第二个矩阵的行数！\n");
    else
    {
        printf("请输入第一个矩阵：");
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%f",&a[i][j]);

        printf("请输入第二个矩阵：");
        for(i=0; i<p; i++)
            for(j=0; j<q; j++)
                scanf("%f",&b[i][j]);
        for(i=0; i<m; i++) //利用循环计算矩阵中每个元的值并放入新的矩阵
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

    printf("请输入矩阵行数：");
    scanf("%d",&m);
    printf("请输入矩阵列数：");
    scanf("%d",&n);

    printf("请输入一个矩阵：");
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



//接下去是最简形和求拟的开始；
void printJZ(double a[][N],int m,int n)//打印矩阵
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

void changeH(double a[][N],int i,int j,int n)//交换两行（i和j）n为矩阵总列数；
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

void addH(double a[][N],int m,int n,int firstm,int firstn)//矩阵行之间加法，m，n为行数和列数，后两个为起始行列数。做完此步骤使得每行左起第一个非零元下面的数均为零；
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

void addH2(double a[][N],int m,int n,int firstm,int firstn)//矩阵行进行加法，从下往上。做完此步骤使得1是它们所在列的唯一非零元；
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

int zeroL(double a[][N],int m,int n,int firstn,int firstm) //判断此列均为全零元列；
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


int zeroPow(double a[][N],int m,int n) //判断行是否全0，用于求秩
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

void FIRSTNOZERO(double a[][N],int n,int firstm,int firstn)//使此列的非零元在零元前面
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

void first2first(double a[][N],int m,int n)//使得每一行左起第一个非零元为1；
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

void ZJX(double a[][N],int m,int n)//最简形的化简，和addH2配合使用
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

void Dezero(double a[][N],int m,int n)//使-0变为0；目的是为了输出美观
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


    printf("请输入矩阵行数：\n");
    scanf("%d",&m);
    printf("请输入矩阵列数：\n");
    scanf("%d",&n);
    printf("您的矩阵为：\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%lf",&b[i][j]); //稍微修改 a为增广 b为原阵 c为逆阵
        }
    }


    for(i=0; i<m; i++)   //为戴天宇构建增广矩阵，之后步骤对增广阵做
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
        while(zeroL(a,m,n,firstn,firstm))//如果此列数均为零则略过此列
        {
            firstn+=1;
        }
        FIRSTNOZERO(a,n,firstm,firstn);
        addH(a,m,2*n,firstm,firstn);
        firstm+=1;
    }
    printf("行阶梯形为（答案不唯一）：\n");
    printJZ(a,m,n);


    first2first(a,m,2*n);
    Dezero(a,m,2*n);

    printf("行最简形为：\n");
    ZJX(a,m,2*n);

    Dezero(a,m,2*n);
    printJZ(a,m,n);


    //打印逆矩阵部分
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            c[i][j]=a[i][j+n];//取右部
        }

    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            b[i][j]=a[i][j];//取左部
        }

    }

    if (zeroPow(b,m,n)!=0) count=1; //判断最后一行是否为零，若为零最没有逆；
    if(m!=n)
    {
        puts("不是方阵我不求逆哼 (0*0) \n");
    }
    else if(count!=0)
    {
        puts("都不满秩求啥子逆哟 (0o0) \n");
    }

    else
    {
        puts("这是你的逆矩阵 不，是你的逆矩阵(^o^) ");
        printJZ(c,m,n);
    }

}



void choose()
{
    int w;
    printf("1.矩阵加法\n");
    printf("2.矩阵减法\n");
    printf("3.矩阵乘法\n");
    printf("4.矩阵转置\n");
    printf("5.矩阵求最简形和逆（若存在）\n");
    printf("6.退出\n");
    printf("\n");
    printf("请选择要进行的运算：");
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
