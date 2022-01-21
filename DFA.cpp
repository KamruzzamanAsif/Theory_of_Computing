// Here I have implemented a DFA (that ends with 11) using c++ 
// that takes an string input and checks if it is accepted or not.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void){

    // Our DFA has 5 touples (Q, Σ, δ, q0, F)
    // Q -> states are {q0, q1, q2}
    // Σ -> inputs are {0,1}
    // δ -> transition function which input and output is shown as trans_table
    // q0 -> our starting state
    // F -> finishig sate {q2}

    int trans_table[3][2]={{0,1},
                           {0,2},
                           {0,2}};
    
    int state = 0; // starting state q0
    int fstate = 2; // finishing/accepting state q2 

    string str;
    cout<<"Enter input as string: ";
    cin>>str;

    cout<<"\nTransitions are: "<<endl;
    for(int i=0; i<str.length(); i++){
        cout<<"(q"<<state<<","<<str[i]<<") -> q";
        state = trans_table[state][str[i]-'0'];
        cout<<state<<endl;
    }

    if(state == fstate)
        cout<<"Accepted!"<<endl;
    else        
        cout<<"Not accepted!"<<endl;

    return 0;
}