#include <bits/stdc++.h>
    using namespace std;
    vector <int> parent;

    int find_operation(int x)
    {
       return parent[x]==-1?x:find_operation(parent[x]);
    }

    void union_operation(int a,int b)
    {
        int xset = find_operation(a);
        int yset = find_operation(b);
        if(xset!=yset)
        {
            parent[xset]=yset;
        }
    }

    int main() {
        freopen("input2.txt","r",stdin);
        int n,edges;
        cin>>n>>edges;
        parent.resize(n+1,-1);
        for(int i=1;i<=edges;i++)
        {
            int a,b;
            cin>>a>>b;
            union_operation(a, b);
        }
        map <int,vector <int>> sets;
        for(int i=1;i<=n;i++)
        {
            int group = find_operation(i);
            sets[group].push_back(i);
        }

       cout<<"Total no of sets : "<<sets.size()<<"\n\n";
        for(auto it = sets.begin(); it != sets.end(); it ++)
        {

            cout<<"Leader of selected set is : "<<it -> first<<endl;
            cout<<"Elements are : ";
            for(int i: it -> second)
                cout<<i<<" ";
            cout<<"\n\n";
        }

    }
