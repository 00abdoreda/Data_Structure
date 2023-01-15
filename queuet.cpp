#include<iostream>
using namespace std;
#define Max_Size 5

class queue{
	int items[Max_Size];
	int front ,rear,length;
	
	public:
		queue(){
			front=0;
			rear=Max_Size-1;
			length=0;
		}
		bool isfull(){
			return length==Max_Size;
		}
		
		bool isempty(){
			return length==0;
		}
		void enqueue(int x){
			if(isfull()){
				cout<<"overflow\n";
				return;
			}
			rear=(rear+1)%Max_Size;
			items[rear]=x;
			length++;
		}
		
		void dequeue(){
				if(isempty()){
				cout<<"underflow\n";
				return;
			}
				front=(front+1)%Max_Size;
				length--;
		}
		void peek(){
				if(isempty()){
				cout<<"underflow\n";
				return;
			}
			
			cout<<items[front]<<endl;
		}
		
		void print(){
				if(isempty()){
				cout<<"underflow\n";
				return;
			}
			
			for(int i=front;i!=rear;i=(i+1)%Max_Size){
				cout<<items[i]<<" ";
			}
			cout<<items[rear]<<" ";
		}
		
};


int main(){
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.dequeue();
	q.dequeue();
	q.enqueue(6);
	q.print();
	
}
