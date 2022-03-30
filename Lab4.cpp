#include <iostream>
using namespace std;
string input, maching;
string production[3]={"E+E","E*E","(E)"};
int n;

int strLength(string s){
    return s.length();
}

bool check(int start)
{
    int dis=0;
    for(int i=0;i<3;i++)
    {
        if((input[start]==production[i][0])
              &&(input[start+1]==production[i][1])
              &&(input[start+2]==production[i][2]))
        {
            dis=1;
            break;
        }
    }
    if(dis==1) return true;
    else 
        return false;
   
}

void stringShortener(int start)
{
    input[start]='E';
    for(int i=start; i<n-3;i++)
    {
        input[i+1]=input[i+3];
    }
    n = n -3;
}


int main()
{
    cout<<"Enter string: ";
    cin>>input;
    n = input.length();
    
    int i, j;
    for(i=0;i<n;i++)
    {
        if((input[i]=='0')||(input[i]=='1'))
        input[i]='E';
    }

    
    for(i=0;i<(strLength(input)-1);i++)
    {
        if(check(i))
        {
            stringShortener(i);
            i=0;
        }
        if(n<2)
        {
            break;
        }
    }


    if((n==1)||(n==0))
        cout<<"Accepted!"<<endl;
    else
        cout<<"Not accepted"<<endl;
    
    return 0;
}