// ʯ�Ӻϲ�����-�������ںϲ�-��̬�滮�㷨
// ʹ������ԭ�������������ķ�ʽ��ģ�⻷�Σ�ע��ת��Ϊ�˳���Ϊl����������i��j 
#include<iostream>
#include<cstring>
#include<climits>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

using namespace std;

const int N=1010;  //ʯ�ӵ�������
int a[N];   //��ʯ�Ӷ����ݵ�Դ����
int dpmax[2*N][N];   //��̬�滮����ֵ����-����ת��Ϊ�ӵ�i�ѿ�ʼ˳ʱ��ϲ�����Ϊj��������
int dpmin[2*N][N];  //��̬�滮����ֵ����-����ת��Ϊ�ӵ�i�ѿ�ʼ˳ʱ��ϲ�����Ϊj�����ٻ���
int merge[2*N][2*N];   //�������ϲ���֮��ĺϲ�����Ϊ���ѵ���ʯ����
//��Ϊ�ӵ�i�ѵ���j��֮��ʯ�����ܺ�
int main(void)
{
    int n;
    cin >>n;
    for(int i=1;i<=2*n;i++)
    {
        if(i<=n)
            cin >>a[i];
        else
            a[i]=a[i-n];
    }
    memset(dpmax,0,sizeof(dpmax));
    memset(dpmin,0,sizeof(dpmin));
    memset(merge,0,sizeof(merge));
    for(int i=1;i<=2*n;i++)
    {
        for(int j=i;j<=2*n;j++)
        {
            if(i==j)
                merge[i][j]=a[i];
            else if(i>n)
                merge[i][j]=merge[i][j-1]+a[j];
            else
                merge[i][j]=merge[i][j-1]+a[j];
        }
    }
    for(int l=2;l<=n;l++)  //����
    {
        for(int i=1;i<=2*n-l+1;i++)  //���
        {
            dpmax[i][l]=INT_MIN;
            dpmin[i][l]=INT_MAX;
            for(int k=1;k<l;k++)  //���ȷָ�λ�ã�������ֽ�
            {
                dpmin[i][l]=min(dpmin[i][l],dpmin[i][k]+dpmin[i+k][l-k]+merge[i][i+l-1]);
                dpmax[i][l]=max(dpmax[i][l],dpmax[i][k]+dpmax[i+k][l-k]+merge[i][i+l-1]);
            }
        }
    }
      //merge�������
    for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=2*n;j++)
            cout <<merge[i][j] <<" ";
        cout <<endl;
    }
    cout <<"-------------------" <<endl;
    //  dpmin�������   ע�ⳤ��Ϊl��Ҳ������Ϊl��Ԫ��ֻ��ǰ2*n-l+1����ֵ����ΪiΪ�����г���l
    for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=n;j++)
            cout <<dpmin[i][j] <<" ";
        cout <<endl;
    }
    cout <<"---------------" <<endl;
    //  dpmax�������
    for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=n;j++)
            cout <<dpmax[i][j] <<" ";
        cout <<endl;
    }
    cout <<"----------------------" <<endl;

    int minv=INT_MAX,maxv=INT_MIN;
    for(int i=1;i<=n+1;i++)  //n+1��Ϊ��n��ֻ��ǰ2*n-n+1��ֵ�������о�Ϊ0��Ӱ��Ƚϣ�����Ҫ��n+1��ʼ
    {
        minv=min(minv,dpmin[i][n]);
        maxv=max(maxv,dpmax[i][n]);
    }
    cout <<minv <<endl <<maxv;
    return 0;
}

