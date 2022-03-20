#include <bits/stdc++.h>
using namespace std;
#define N 100

int nfa_numberOfStates;
char nfa_states[N];
char nfa_starting_state;
int nfa_numberOfFinalStates;
char nfa_final_states[N];
string nfa_transitions[N][N]; // indexing(states) according to the order of nfa_states

char dfa_starting_state;
string dfa_states[N];
string dfa_transitions[N][N];

queue <string> done, to_be_done; 

int findIndex(char c){
    for(int i=0; i<nfa_numberOfStates; i++){
        if(c==nfa_states[i])
            return i;
    }
    return -1;
}

void generateDFA(){
    dfa_starting_state = nfa_starting_state;
    dfa_states[0] = dfa_starting_state;
    done.push(dfa_states[0]);
    int index = findIndex(dfa_starting_state);
    to_be_done.push(nfa_transitions[index][0]);
    to_be_done.push(nfa_transitions[index][1]);

    int dfa_state_index = 1;
    while(!to_be_done.empty()){
        string temp = to_be_done.front();
        to_be_done.pop();
        done.push(temp);
        dfa_states[dfa_state_index++] = temp;

        
    }
}

int main(void){
    freopen("nfaToDfa.txt", "r", stdin);
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

    // transitions of nfa
    cout<<"Enter the transitions: "<<endl;
    for(int i=0; i<nfa_numberOfStates; i++){
        cout<<nfa_states[i]<<" using 0 goes to: ";
        cout<<"(enter the states (enter 'x' to stop))";
        char c;
        string s;
        cin>>c;
        while(c!='x'){
            s += c;
            s += ' ';
            cin>>c;
        }
        nfa_transitions[i][0] = s;
        cout<<endl;

        cout<<nfa_states[i]<<" using 1 goes to: ";
        cout<<"(enter the states (enter 'x' to stop))";
        char ch;
        string t;
        cin>>ch;
        while(ch!='x'){
            t += ch;
            t += ' ';
            cin>>ch;
        }
        nfa_transitions[i][1] = t;
        cout<<endl;
    }

    generateDFA();

    return 0;
}