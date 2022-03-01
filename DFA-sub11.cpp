// Here I have implemented a DFA (that contains 11 as substring) using c++ 
// that takes an string input and checks if it is accepted or not.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void){

    // Our DFA has 5 touples (Q, Σ, δ, q0, F)
    // Q -> states are {q0, q1, q2}
    // Σ -> inputs are {0,1}
    // δ -> transition function which input and output is shown in trans_table
    // q0 -> our starting state
    // F -> finishig sate {q2}

    int inputs[2]={0,1};  // Σ={0,1}
    int trans_table[3][2]={{0,1},          // here index i=0 is q0, i=1 is q1, i=2 is q2
                           {0,2},          //        and j=0 is 0 and j=1 is 1
                           {2,2}};         // a[i][j]=x means i-th state goes to x-th sate 
                                           //          using input j
    int current_state = 0; // starting state q0
    int fstate = 2; // finishing/accepting state q2 

    string str;
    cout<<"Enter input as string: ";
    cin>>str;

    cout<<"\nTransition Diagram given below: "<<endl;
    cout<<"From\t using_input\t\tTo"<<endl;
    cout<<"----\t -----------\t\t--"<<endl;
    for(int i=0; i<str.length(); i++){
        int x = str[i]-'0';
        if(x!=inputs[0] && x!=inputs[1]){
            cout<<"\nInvalid input symbol."<<endl;
            return 0;
        }
        else{
            cout<<"q"<<current_state<<"\t->\t"<<x<<"\t->\tq";
            current_state = trans_table[current_state][x];
            cout<<current_state<<endl;
        }
    }
    
    string result = (current_state == fstate)? "Accepted!" : "Not accepted!"; 
    cout<<result;

    return 0;
}