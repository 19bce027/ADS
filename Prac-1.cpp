#include<bits/stdc++.h>
using namespace std;

struct nstack{
	int size;
	int maxSize;
	double alpha;
	char* base;

	nstack(int ms , double alp){
		size = 0;
		maxSize = ms;
		alpha = alp;
		base = new char[ms];
	}
};


void push(nstack* st , char val){
	cout<<val<<endl;
	st->base[st->size] = val;
	st->size = st->size + 1;
}

void pop(nstack* st){
	if(st->size==0){
		cout<<"Stack is Empty"<<endl;
		return;
	}
	cout<<"Top element is Removed:- " <<st->base[st->size-1]<<endl;
	st->size--;
}

int main(){

	ofstream file;

	file.open("random_file.txt");


		srand((unsigned)(0));
		int ran_data;
		for (int index = 0; index < 100; index++) {
			ran_data = (rand() % 26) ;
			file << (char)(ran_data + 'a');
		}

  	file.close();

  	double threshold ;
  	cout<<"Enter a threshold  value : "<<endl;
  	cin>>threshold;

  	int initialSize;
  	cout<<"Enter the initial size of stack : "<<endl;
  	cin>>initialSize;

  	nstack* st = new nstack(initialSize , threshold);

  	char currChar = 0;
  	ifstream input_file("random_file.txt");
  	while (input_file.get(currChar)) {
  		cout<<st->alpha<<" "<<(st->maxSize)<< " "<< st->size<<endl;
  		cout<<st->alpha * (st->maxSize)<<endl;
        if(st->alpha * st->maxSize > st->size ){
        	push(st , currChar);
		}else{
			cout<<"stack overflow. Do you want to increase the size of stack. Y/N"<<endl;
			char flag;
			cin>>flag;

			if(flag == 'Y'){
				st->maxSize = 2*st->maxSize;
				char * newptr = new char[st->maxSize];

				for(int i=0 ; i<st->size ; i++){
					newptr[i] = st->base[i];
				}
				st->base = newptr;
				push(st , currChar);
			}else if(flag == 'N'){
				break;
			}
		}
		cout<<"----------------------------------------"<<endl;
    }


  	while(true){
  		cout<<"Do you want to delete element : (Y/N)"<<endl;
  		char flag;
  		cin>>flag;
  		if(flag=='N'){
  			break;
		}
  		pop(st);
	}

}
