#include <bits/stdc++.h>
using namespace std;
#define N 100

int nfa_numberOfStates;
char nfa_states[N];
char nfa_starting_state;
int nfa_numberOfFinalStates;
char nfa_final_states[N];
//int nfa_transition_table[N][2];
// we may use map

int main(void){

    cout<<"Enter number of states of NFA: ";
    cin>>nfa_numberOfStates;
    cout<<endl;

    // taking states
    cout<<"Enter the states of NFA: ";
    for(int i=0; i<nfa_numberOfStates; i++){
        cin>>nfa_states[i];
    }
    cout<<endl;

    // taking starting state
    cout<<"Enter the starting state of NFA: ";
    cin>>nfa_starting_state;
    cout<<endl;

    // taking number of final state
    cout<<"Enter the number of final states of NFA: ";
    cin>>nfa_numberOfFinalStates;
    cout<<endl;

    // taking final states
    cout<<"Enter the final states of NFA: ";
    for(int i=0; i<nfa_numberOfFinalStates; i++){
        cin>>nfa_final_states[i];
    }
    cout<<endl;


    return 0;
}