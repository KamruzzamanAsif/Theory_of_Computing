// This is a general DFA for Binary input only.
// User have to give input of sates, starting state, final states, and 
// transitions for the states and give an input string w
// This program will check and show whether the input string is 
// accepted or not by the dfa

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 100

int numberOfStates;
char states[N];
char starting_state;
int numberOfFinalStates;
char final_states[N];
int transition_table[N][2];
string w;

// to find the index of a state
int find_index(char ch){ 
    for(int i=0; i<numberOfStates; i++){
        if(states[i]==ch){
            return i;
        }
    }
}

void solve(){
    cout<<"\nTransition Diagram given below: "<<endl;
    cout<<"From\t using_input\t\tTo"<<endl;
    cout<<"----\t -----------\t\t--"<<endl;
    int current_state = find_index(starting_state);
    for(int i=0; i<w.length(); i++){
        int x = w[i]-'0';
        if(x!=0 && x!=1){    // checking correct input or not
            cout<<"\nInvalid input symbol."<<endl;
            return;
        }
        else{
            cout<<states[current_state]<<"\t->\t"<<x<<"\t->\t";
            current_state = transition_table[current_state][x];
            cout<<states[current_state]<<endl;
        }
    }

    // now check accepted or not
    for(int i=0; i<numberOfFinalStates; i++){
        if(states[current_state]==final_states[i]){
            cout<<"\nAccepted!";
            return;
        }
    }
    cout<<"\nRejected!";
    return;
}

int main(void){
    // the txt file holds the dfa that ends with 11
    freopen("general-dfa.txt", "r", stdin);

    //taking total number of states
    cout<<"Enter number of states: ";
    cin>>numberOfStates;
    cout<<endl;

    // taking states
    cout<<"Enter the states: ";
    for(int i=0; i<numberOfStates; i++){
        cin>>states[i];
    }
    cout<<endl;

    // taking starting state
    cout<<"Enter the starting state: ";
    cin>>starting_state;
    cout<<endl;

    // taking number of final state
    cout<<"Enter the number of final states: ";
    cin>>numberOfFinalStates;
    cout<<endl;

    // taking final states
    cout<<"Enter the final states: ";
    for(int i=0; i<numberOfFinalStates; i++){
        cin>>final_states[i];
    }
    cout<<endl;

    // making the transition table from given inputs
    cout<<"Enter the transitions: \n";
    for(int i=0; i<numberOfStates; i++){
        char ch1;
        cout<<states[i]<<" >>>> using 0 goes to >>> ";
        cin>>ch1;
        transition_table[i][0]= find_index(ch1);
        cout<<endl;

        char ch2;
        cout<<states[i]<<" >>>> using 1 goes to >>> ";
        cin>>ch2;
        transition_table[i][1]= find_index(ch2);
        cout<<endl;
    }

    // taking any string of (0,1) as input
    cout<<"\nEnter input as string: ";
    cin>>w;

    // passing to solve function
    solve();

    return 0;
}