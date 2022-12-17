#include<iostream>
using namespace std;
const int  Max_Size=20;
class stack{
private:
	int top;
int item[Max_Size];	//0 1 
public:
stack(){
top=-1;	
}
void push(int x){
	if(top>=Max_Size-1){
		cout<<"stack is full";
	}else{
			top++;
	item[top]=x;
	}
	

}

bool isempty(){
	return top<0;
	
}

void pop(){
	if(isempty()){
		cout<<"stack is empty";
	}else{
		top--;
	}
	
}

void pop(int &x){
	
	if(isempty()){
		cout<<"stack is empty";
	}else{
		x=item[top];
		top--;
	}
}

void gettop(){
		if(isempty()){
		cout<<"stack is empty";
	}else{
	cout<<item[top];
	}
	
}

void print(){
	if(isempty()){
		cout<<"stack is empty";
	}else{
	for(int i=top;i>-1;i--){
		cout<<item[i]<<endl;
	}
	}

}	
	
	
};


int main(){
	stack s;
	int x;
	s.push(5);
	s.push(4);
	s.push(9);
	s.pop(x);
	//x for main = x for pop
	s.gettop();
//	s.pop();
	//s.pop();
//	s.pop();
//	s.pop();//is empty
//	s.print();//isempty
	
	
}
