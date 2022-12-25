#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head=NULL;
node*tail=NULL;
int length=0;
void insertTail(int x){
	node*new_node=new node;
	new_node->data=x;
	if(head==NULL){
		head=tail=new_node;
		tail->next=head;
	}else{
		tail->next=new_node;
		tail=new_node;
		tail->next=head;
		
	}
	length++;
}

void insertHead(int x){
	node*new_node=new node;
	new_node->data=x;
	if(head==NULL){
		head=tail=new_node;
		tail->next=head;
	}else{
		tail->next=new_node;
		new_node->next=head;
		head=new_node;
	
		
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
	node*temp=head;
	for(int i=0;i<pos-1;i++){
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	length++;
		
	}
	
	
}

void deleteHead(){
	if(head==NULL){
		cout<<"list is empty";
	}else if (head==tail){
		delete(head);
		head=tail=NULL;
		length--;
	}else{
		node*cur=head->next;
		tail->next=cur;
		delete(head);
		head=cur;
		length--;
	}
}
void deleteTail(){
	if(head==NULL){
		cout<<"list is empty";
	}else if (head==tail){
		delete(head);
		head=tail=NULL;
		length--;
	}else{
	node*cur=head;
	while(cur->next!=tail){
		cur=cur->next;
	}
	cur->next=head;
	delete(tail);
	tail=cur;
	length--;
	}
}
void deleteElement(int x){
	if(head==NULL){
		cout<<"list is empty\n";
	}else {
		node *cur=head;
		if(cur->data==x){
			deleteHead();
		}else{
			node*prev=head;
			cur=head->next;
			while(cur->data!=x){
				if(cur->next==head&&cur->data!=x){
					cout<<"not found\n";
					return ;
				}else{
						cur=cur->next;
				prev=prev->next;
				}
			
				
			}
			prev->next=cur->next;
			delete(cur);
			if(prev->next==head){
				tail=prev;
			}
			length--;
			
		}
	}
}




void display(){
	node*cur=head;
	if(cur==NULL){
		cout<<"list is empty\n";
	}else{
		while(true){
			if(cur->next==head){
				cout<<cur->data;
				break;
			}else{
				cout<<cur->data<<" ";
			cur=cur->next;
			}
			
		
	}	
	}

}
void find(int x){
	if(head==NULL){
		cout<<"list is empty\n";
	}else{
		node*cur=head;
		while(cur->data!=x){
			if(cur->next==head&&cur->data!=x){
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
	
insertHead(5);
insertTail(10);
insertTail(12);
insertHead(14);
insertatpos(19,1);


//14 19 5 10 12 
//deleteHead();
////deleteElement(12);
find(9);

//display();	
	
	

}
