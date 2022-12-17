#include<iostream>
using namespace std;

struct node{
	int data;
	node*next;
	
};
node*head=NULL;
node*tail=NULL;
int length=0;
void insertNode(int x);
void insertatbeg(int x);
void insertatpos(int x,int pos);
void display();


int main(){
	insertNode(5);
	insertNode(7);
	insertNode(9);
	insertatbeg(15);
	//15 5 7 9
	insertatpos(20,1);
	display();
}





void insertNode(int x){
	node*new_node = new node;
	new_node->data=x;
	if(head==NULL){
		head=tail=new_node;
		new_node->next=NULL;
	}else{
		
		tail->next=new_node;
		tail=new_node;
		tail->next=NULL;
		
	}
	length++;
	
}

void insertatbeg(int x){
	
	node*new_node = new node;
	new_node->data=x;
	if(head==NULL){
		head=tail=new_node;
		new_node->next=NULL;
	}else{
		new_node->next=head;
		head=new_node;
	}
	
	length++;
	
}

void insertatpos(int x,int pos){
	
	if(pos<0||pos>length){
		cout<<"out of length\n";
	}else if(pos ==0){
		insertatbeg(x);
	}else if(pos==length){
		insertNode(x);
	}else{
		node*new_node = new node;
	new_node->data=x;
	node*temp=head;
	for(int i=0;i<pos-1;i++){
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	length++;
		
	}
	
	
}

void display(){
	
	node*cur=head;
	while(cur!=NULL){
		cout<<cur->data<<" ";
		cur=cur->next;
	}
}















