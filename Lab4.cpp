/* Problem: Build a CFG that accepts or rejects a 
   given input based on the following grammar-
          E -> E + E
          E -> E * E
          E -> (E)
          E -> 0|1
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string input;
int n;
string production[3]={"E+E","E*E","(E)"};
string temp;


bool check(int start)
{
    for(int i=start; i<start+3; i++)
        temp += input[i];

    int flag=0;
    for(int i=0;i<3;i++)
    {
        if(production[i]==temp){
            flag = 1;
            break;
        }
    }
    temp.clear();

    if(flag==1) 
        return true;
    else 
        return false;
    
}

void subStringRemover(int start){
    string temp1, temp2;
    for(int i=0; i<start; i++)
        temp1 += input[i];
    for(int i=start+3; i<input.length(); i++)
        temp2 += input[i];
    input = temp1 + "E" + temp2;
}


int main()
{
    cout<<"Enter input as string: ";
    cin>>input;
    n = input.length();
    
    for(int i=0;i<n;i++)
    {
        if((input[i]=='0')||(input[i]=='1'))
            input[i]='E';
    }

    
    for(int i=0;i<input.length()-1; )
    {
        if(check(i))
        {
            subStringRemover(i);
            i=0; // traverse the string again!
        }
        else
            i++;

        if(input.length()<=1)
            break;
    }


    if((input.length()==1)||(input.length()==0))
        cout<<"Accepted!"<<endl;
    else
        cout<<"Not accepted!"<<endl;
    
    return 0;
}