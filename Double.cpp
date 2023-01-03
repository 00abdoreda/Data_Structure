#include<iostream>
using namespace std;

struct node{
	int data;
	node*next;
	node*prev;
	
};
node*head=NULL;
node*tail=NULL;
int length=0;

void insertHead(int x){
	node*new_node=new node;
	new_node->data=x;
	if(head==NULL){
		new_node->next=NULL;
		new_node->prev=NULL;
		head=tail=new_node;
	}else{
		new_node->next=head;
		new_node->prev=NULL;
		head->prev=new_node;
		head=new_node;
	}
	length++;
}

void insertTail(int x){
	node*new_node=new node;
	new_node->data=x;
	if(head==NULL){
		new_node->next=NULL;
		new_node->prev=NULL;
		head=tail=new_node;
	}else{
	new_node->prev=tail;
	tail->next=new_node;
	new_node->next=NULL;
	tail=new_node;
	}
	length++;
}

void insertatpos(int x,int pos){
	
	if(pos<0||pos>length){
		cout<<"out of length\n";
	}else if(pos ==0){
		insertHead(x);
	}else if(pos==length){
		insertTail(x);
	}else{
		node*new_node = new node;
	new_node->data=x;
	node*cur=head;
	for(int i=0;i<pos-1;i++){
		cur=cur->next;
	}
	cur->next->prev=new_node;
	new_node->next=cur->next;
	new_node->prev=cur;
	cur->next=new_node;
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
void displayr(){
	node*cur=tail;
	while(cur!=NULL){
		cout<<cur->data<<" ";
		cur=cur->prev;
		
	}
}
void deleteHead(){
	if(head==NULL){
		cout<<"list is empty\n";
	}else if(head==tail){
		delete(head);
		head=tail=NULL;
		length--;
	}else{
		head=head->next;
		delete(head->prev);
		head->prev=NULL;
		length--;
	}
}
void deleteTail(){
	if(head==NULL){
		cout<<"list is empty\n";
	}else if(head==tail){
		delete(head);
		head=tail=NULL;
		length--;
	}else{
		tail=tail->prev;
		delete(tail->next);
		tail->next=NULL;
		length--;
	}
}
void deleteatpos(int pos){
	if(pos<0||pos==length){
		cout<<"out of length\n";
	}else if(pos==0){
		deleteHead();
	}else if(pos==length-1){
		deleteTail();
	}else{
		node*cur=head;
		for(int i=0;i<pos;i++){
			cur=cur->next;
		}
		cur->prev->next=cur->next;
		cur->next->prev=cur->prev;
		delete(cur);
		length--;
	}
}

int main(){
	insertHead(10);
	insertHead(12);
	insertHead(15);
	//15 12 10
	insertTail(20);
	insertTail(30);
	//15 12 10 20 30
	insertatpos(13,2);
	//15 12 13 10 20 30
	deleteatpos(2);

//	deleteHead();
	//deleteHead();
	// 13 10 20 30
//	deleteTail();
	

	display();
	//cout<<endl;
	//displayr();
	
}
