#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main(void)
{
    int n,flag;
    stack<char> s;
    char ch;
    cin >> n;
    getchar();
    for(int i=0;i<n;i++)
    {
        flag=1;
        ch=getchar();
        while(ch!='\n')
        {
            if(ch=='('||ch=='['||ch=='{')
                s.push(ch);
            else if((ch==')'&&s.top()=='(')||(ch==']'&&s.top()=='[')||(ch=='}'&&s.top()=='{'))  //ÓÒÀ¨ºÅÆ¥Åä×óÀ¨ºÅµÄÇé¿ö
                s.pop();
            else
                flag=0;
            ch=getchar();
        }
        if(!s.empty())
            flag=0;
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No"  << endl;
    }
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define STACK_INIT_SIZE 200005
#define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
typedef char ElemType;
typedef int Status;
typedef struct SqStack{
	ElemType *base;
	ElemType *top;
	int stackSize;
}SqStack;
Status InitStack(SqStack &S);
Status Pop(SqStack &S,ElemType &del);
Status Push(SqStack &S,ElemType add);
Status StackEmpty(SqStack &S);
ElemType GetTop(SqStack &S);
Status bracketsMatch(char *str);
Status match(char x,char y);
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char str[200005];
        scanf("%s",str);
        if(bracketsMatch(str))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
Status match(char x,char y)
{
    if(x=='{'&&y=='}') return TRUE;
    if(x=='['&&y==']') return TRUE;
    if(x=='('&&y==')') return TRUE;
    return FALSE;
}
Status bracketsMatch(char *str)
{
	int i,len;
	SqStack S;
	ElemType del,top;
	InitStack(S);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')
			Push(S,str[i]);
		else if(str[i]==')'||str[i]==']'||str[i]=='}')
		{
            top=GetTop(S);
			if(match(top,str[i]))
                Pop(S,del);
            else
                return FALSE;
		}
	}
	return StackEmpty(S);
}
Status InitStack(SqStack &S)
{
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)  exit(ERROR);
	S.stackSize=STACK_INIT_SIZE;
	S.top=S.base;
	return OK;
}
Status Pop(SqStack &S,ElemType &del)
{
	if(S.top==S.base)  exit(ERROR);
	del=*--S.top;
	return OK;
}
Status Push(SqStack &S,ElemType add)
{
	if(S.top-S.base>=S.stackSize)
	{
		S.base=(ElemType *)realloc(S.base,(S.stackSize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.base)  exit(OVERFLOW);
		S.stackSize+=STACKINCREMENT;
		S.top=S.base+STACKINCREMENT;
	}
	*S.top++=add;
	return OK;
}
Status StackEmpty(SqStack &S)
{
	return S.top==S.base;
}
ElemType GetTop(SqStack &S)
{
	return *(S.top-1);
}

*/ 
