#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> c;
	string key;
	int i;
	cin >> key;
	while(key != "#"){
		if( key == "PUSH"){
			cin >> i;
			c.push(i);
		}
		else
		{
			if(!c.empty()){
			int a=c.top();
			c.pop();
			cout << a << endl;
			}
			else
			{ 
				cout << "NULL" << endl;
			}
		}
		cin >> key;
	}
	    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> s;
	string key;
	int i;
	cin>> key;
	while(key!="#"){
		if(key=="PUSH"){
			cin>>i;
			s.push(i);
		}
		else{
			if(!s.empty()){
			int e=s.top();
			s.pop();
			cout<<e<<endl;
			}
			else{
				cout<<"NULL"<<endl;
			}
			
		}
		cin>>key;
	}
	return 0;
}
