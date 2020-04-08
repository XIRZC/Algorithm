//合并果子问题可不相邻-priority_queue来解决
#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    int n,elem,min=0,max=0;
    priority_queue<int,vector<int>,less<int> > pqmax;  //大顶堆，用于求最大得分
    priority_queue<int,vector<int>,greater<int> >pqmin;  //小顶堆，用于求最小得分
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
        if(!pqmin.empty())  //若此时不为空，则要继续把合并结果推进去继续合并
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

