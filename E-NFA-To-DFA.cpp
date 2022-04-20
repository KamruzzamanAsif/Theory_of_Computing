#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector <pair<string, vector<string>>> enfa_transitions;
string enfa_starting_state;
string enfa_final_states;

vector <pair<string, vector<string>>> dfa_transitions;
string dfa_starting_state;
string dfa_final_states;

string eclose(string str){
    for(int i=0; i<enfa_transitions.size(); i++){
        if(enfa_transitions[i].first == str){
            if(enfa_transitions[i].second[2] != "phi"){
                // cout<<str + enfa_transitions[i].second[2];
                return str + enfa_transitions[i].second[2];
            }
        }
    }
    cout<<"HI"<<endl;
    return str;
}

string findForZero(string c){
    for(int i=0; i<enfa_transitions.size(); i++){
        if(enfa_transitions[i].first == c){
            if(enfa_transitions[i].second[0] != "phi"){
                return enfa_transitions[i].second[0];
            }
        }
    }
    return "phi";
}

void make_dfa(){
    // dfa starting state is eclose of enfa starting state
    dfa_starting_state = eclose(enfa_starting_state);
    queue <string> Q;
    Q.push(dfa_starting_state);
    cout<< "\ndfa s:"<<dfa_starting_state<<endl;

    while(!Q.empty()){
        string s = Q.front();
        Q.pop();

        //for 0
        string zero_str;
        for(int i=0; i<s.length(); i++){
            string c = "";
            c += s[i];
            zero_str += findForZero(c);
            c.clear();
        }

        //for unique elements
        set<char> se;
        for(int i=0; i<zero_str.length(); i++){
            se.insert(zero_str[i]);
        }
        zero_str.clear();
        for(auto itr: se){
            zero_str += itr;
        }

        // for eclose
        string ec = "";
        for(int i=0; i<zero_str.length(); i++){
            string s = "";
            s += zero_str[i];
            ec += eclose(s);
        }
        // get unique eclose
        set<char> se1;
        for(int i=0; i<ec.length(); i++){
            se1.insert(ec[i]);
        }
        ec.clear();
        for(auto itr: se1){
            ec += itr;
        }

        cout<<ec;
    }
}

int main(void){
    freopen("enfaToDfa.txt", "r", stdin);
    /* input style is all string type
        state is string
        using 0 goes to is string(don't use any space between states)
        using 1 goes to is string(don't use any space between states)
        using e goes to is string(don't use any space between states)

        sample input:
        A B phi C     (eg. state A using 0 goes to B, using 1 goes nowhere, using e goes to C)
        B phi D phi
        C C C phi
    */
    cout<<"Enter eNfa transitions: \n";
    cout<<"[State --- Goes using 0 --- Goes using 1 --- Goes using e ]\n"; 
    cout<<"(enter stop to end input)"<<endl;
    string str;
    cin>>str;
    while(str != "stop"){
        string temp = "";
        vector<string> temp_vec;
        string left = "";
        int i=0;
        while(str[i] != ' '){
            left += str[i++];
        }

        for( ; i<str.length(); i++){
            if(str[i] == ' '){
                temp_vec.push_back(temp);
                temp.clear();
            }
            else{
                temp += str[i];
            }
        }
        temp_vec.push_back(temp);
        temp.clear();
        enfa_transitions.push_back(make_pair(left,temp_vec));

        cin>>str;
    }

    cout<<"\nEnter enfa starting state: ";
    cin>>enfa_starting_state;

    cout<<"\nEnter enfa final states: (separated by space)";
    cin>>enfa_final_states;

    for(int i=0; i<enfa_transitions.size(); i++){
        cout<<enfa_transitions[i].first<<" ";
        for(int j=0; j<enfa_transitions[i].second.size(); j++){
            cout<<enfa_transitions[i].second[j]<<" ";
        }
        cout<<endl;
    }

    //make_dfa();
}
