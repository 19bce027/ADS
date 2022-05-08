#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;

    cout << "Enter string :- ";
    cin >> s;

    vector<pair<string, int>> vec;
    string temp;

    for(int i = s.size() - 1; i >= 0; i --){
        temp = s[i] + temp;
        vec.push_back({temp, i});
    }
     for(int i = s.size() - 1; i >= 0; i --){
         cout <<vec[i].first<<"\n" ;
     }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i ++){
        cout << vec[i].second << " " << vec[i].first << endl;
    }

    return 0;
}
