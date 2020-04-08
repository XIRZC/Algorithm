#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int main(void)
{
    int n;
    queue<string> names;
    string request,name;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> request;
        if(request=="in")
        {
            cin >> name;
            names.push(name);
        }
        else if(request=="out")
        {
            names.pop();
        }
        else if(request=="q")
        {
            if(names.empty())  cout << "NULL" << endl;
            else cout << names.front() << endl;
        }
    }
    return 0;
}

