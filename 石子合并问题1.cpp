//�ϲ���������ɲ�����-priority_queue�����
#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    int n,elem,min=0,max=0;
    priority_queue<int,vector<int>,less<int> > pqmax;  //�󶥶ѣ����������÷�
    priority_queue<int,vector<int>,greater<int> >pqmin;  //С���ѣ���������С�÷�
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>elem;
        pqmin.push(elem);
        pqmax.push(elem);
    }
    while(!pqmin.empty())
    {
        int min1=pqmin.top();
        pqmin.pop();
        int min2=pqmin.top();
        pqmin.pop();
        min+=min1+min2;
        if(!pqmin.empty())  //����ʱ��Ϊ�գ���Ҫ�����Ѻϲ�����ƽ�ȥ�����ϲ�
            pqmin.push(min1+min2);
    }
    while(!pqmax.empty())
    {
        int max1=pqmax.top();
        pqmax.pop();
        int max2=pqmax.top();
        pqmax.pop();
        max+=max1+max2;
        if(!pqmax.empty())
            pqmax.push(max1+max2);
    }
    cout <<min <<endl <<max;
    return 0;
}

