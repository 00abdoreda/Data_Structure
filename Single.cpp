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
void deletebeg(){
	if(head==NULL){
		cout<<"list is empty\n";
	}
	else if(head==tail){
		delete(head);
		head=tail=NULL;
		length--;
	}else{
		node*cur=head;
		head=head->next;
		delete(cur);
		length--;
		
	}
	
}
void deleteTail(){
		if(head==NULL){
		cout<<"list is empty\n";
	}
	else if(head==tail){
		delete(head);
		head=tail=NULL;
		length--;
	}else{
	
	node*cur=head;
	while(cur->next!=tail){
		cur=cur->next;
	}
	delete(tail);
	tail=cur;
	tail->next=NULL;
	length--;
	
	}
}
void deleteElement(int x){
	if(head==NULL){
		cout<<"list is empty\n";
	}else {
		node *cur=head;
		if(cur->data==x){
			deletebeg();
		}else{
			node*prev=head;
			cur=head->next;
			while(cur->data!=x){
				if(cur->next==NULL&&cur->data!=x){
					cout<<"not found\n";
					return ;
				}else{
						cur=cur->next;
				prev=prev->next;
				}
			
				
			}
			prev->next=cur->next;
			delete(cur);
			if(prev->next==NULL){
				tail=prev;
			}
			length--;
			
		}
	}
}

void find(int x){
	if(head==NULL){
		cout<<"list is empty\n";
	}else{
		node*cur=head;
		while(cur->data!=x){
			if(cur->next==NULL&&cur->data!=x){
				cout<<"not found\n";
				return;
			}else{
				
				cur=cur->next;
			}
		}
		cout<<"founded"<<endl;
	}
	
}


int main(){
	insertNode(5);
	insertNode(7);
	insertNode(9);
	insertatbeg(15);
	//15 5 7 9
	insertatpos(20,1);
	//15 20 5 7 9
	find(19);
	//deleteElement(5);
	//insertNode(19);
	//20 5 7 9
		
	
	
	
	
	//deletebeg();
	//20 5 7 9
	//deletebeg();
	//5 7 9
	
//	deleteTail();
	//5 7

		
	//display();
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















