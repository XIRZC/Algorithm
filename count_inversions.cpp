
#include<iostream>
using namespace std;
int a[1005],temp[1005];
int ans=0;
void merge(int * src,int * temp,int left,int right);
void merge_sort(int * src,int * temp,int left,int right);
int main(void)
{
    int n,m;
    cin >> n;
    for(int j=0;j<n;j++)
        cin >> a[j];
    merge_sort(a,temp,0,n-1);
    cout << ans << endl;
	return 0;
}
void merge(int * src,int * temp,int left,int mid,int right)
{
    int i,j,k;
    if(left>=right)  return;
	for(i=left,j=mid+1,k=0;i<=mid&&j<=right;k++)
	{
		if(src[i]<=src[j])
        {
            temp[k]=src[i++];
            ans+=j-mid-1;
        }
        else
            temp[k]=src[j++];
	}
	while(i<=mid)
    {
		temp[k++]=src[i++];
		ans+=right-mid;
	} 
    while(j<=right)
        temp[k++]=src[j++];
    for(i=0;i!=k;++i)  //temp����ʵ��0��ʼ����0��ʼ��a��left��ʼ��right��ֵ
        a[left+i]=temp[i];
}
void merge_sort(int * src,int * temp,int left,int right)
{
    if(left>=right)  return;
	int mid=(left+right)/2;
	merge_sort(src,temp,left,mid);
	merge_sort(src,temp,mid+1,right);
	merge(src,temp,left,mid,right);
}



/*  ö��ѡ�����������������С�������� 
#include<iostream>

using namespace std;

int main(void)
{
	int n,a[1005];
	cin >> n;
	for(int j=0;j<n;j++)
		cin >> a[j];
	int ans=0;
	for(int j=0;j<n;j++)
	{
		for(int k=j+1;k<n;k++)
		{
			if(a[j]>a[k])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
} */
