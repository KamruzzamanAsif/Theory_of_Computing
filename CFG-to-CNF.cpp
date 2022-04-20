#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector < pair<char, vector<string>>> production;

void input_cfg(){
    freopen("cfgToCnf.txt", "r", stdin);
    cout<<"Enter Productions of CFG(enter xxx to stop): \n";
    string str;
    cin>>str;
    while(str != "xxx"){
        char left = str[0];
        string temp_str;
        vector<string> temp_vec;
        for(int i=2; i<str.length(); i++){
            if(str[i]=='|'){
                temp_vec.push_back(temp_str);
                temp_str.clear();
            }
            else
                temp_str += str[i];
        }
        temp_vec.push_back(temp_str);
        temp_str.clear();
        production.push_back(make_pair(left,temp_vec));

        cin>>str;
    }
}

void eliminate_epsilon_productions(){
    
}

int main(void){
    input_cfg();

    // print input cfg
    // for(int i=0; i<production.size(); i++){
    //     cout<<production[i].first<<" ";
    //     for(int j=0; j<production[i].second.size(); j++){
    //         cout<<production[i].second[j]<<" ";
    //     }
    //     cout<<endl;
    // }

    eliminate_epsilon_productions();
}