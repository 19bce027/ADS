#include<bits/stdc++.h>
using namespace std;

class Hash
{
    int bucket_size;
    list<int> *table;
public:
    Hash(int b)
    {
        this->bucket_size = b;
        table = new list<int>[bucket_size];
    }

    int hashFunction(int x) {
            return (x % bucket_size);
    }

    void insertItem(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);

        list <int> :: iterator i;
        for (i = table[index].begin();
                i != table[index].end(); i++) {
            if (*i == key)
            break;
        }

        if (i != table[index].end())
            table[index].erase(i);
    }

    void displayHash() {
        for (int i = 0; i < bucket_size; i++) {
            cout << i;
            for (auto x : table[i])
            cout << " --> " << x;
            cout << endl;
        }
    }

};

int main()
{
    freopen("input.txt","r",stdin);
    int bucket_size;
    cin>>bucket_size;
    int n;
    cin>>n;
    Hash h(bucket_size);
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        h.insertItem(num);
    }
    cout<<"Displaying Hash : "<<endl;
    h.displayHash();
    cout<<endl;
    int val;
    cin>>val;
    h.deleteItem(val);
    cout<<"Displaying Hash after deleting "<<val<<" : "<<endl;
    h.displayHash();
    return 0;
}
