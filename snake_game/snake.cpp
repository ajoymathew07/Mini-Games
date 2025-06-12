#include <iostream>
#include "snake.hpp"
using namespace std;

Node::Node(int i,int j){
        row=i;
        col=j;
        next=NULL;
}

Snake::Snake(){
        // Head and tail position
        head=NULL;
        tail=NULL;
}

 void Snake::insertathead(int i,int j){
        Node* n=new Node(i,j);
        if(head==NULL && tail==NULL){
            head=n;
            tail=n;
            return;
        }
       
        n->next=head;
        head=n;
}
 void Snake::insertattail(int i,int j) {
        Node* n=new Node(i,j);
        if(head==NULL && tail==NULL){
            head=n;
            tail=n;
            return;
        }
        tail->next=n;
        tail=n;
}
void Snake:: printHead(){ 
    cout<<head->row<<" "<<head->col<<endl;
 }

void Snake::markarray(char** arr,int n){
        
        Node* temp=head;
        while(temp!=tail){
            arr[temp->row][temp->col]='*';
            temp=temp->next;
        }
        arr[temp->row][temp->col]='*';       
}

bool Snake:: isValid(int u1,int r1,char** arr,int n){
         int newi1=head->row + u1;
         int newj1=head->col + r1;
        if(newi1>=n || newi1<0){
            return false; // out of bounds
        }
        if(newj1>=n || newj1<0){
            return false; // out of bounds
        }
        
        if(head==tail){
            return true; // Base case when snake is of size 1
        }
        if(size()==2){
            // Error handling
            if(newi1==tail->row && newj1==tail->col){
                return false;
            }  
        }
       Node* temp=head;
        
         while(temp!=tail){
            // To check if it hits the snake
            if(temp->row==newi1 && temp->col==newj1){
                return false;
            }
            temp=temp->next;
         }
         return true;
       
    
}
bool Snake:: move(int u1,int r1,char** arr,int n){
        if(arr[head->row+u1][head->col+r1]=='$'){
            arr[head->row+u1][head->col+r1]='*';
            insertathead(head->row+u1,head->col+r1);
            // Winning condition
            if(size()==n*n){
                cout<<"You win"<<endl;
            }
            return true;
        }
        // Edge case
        if(head==tail){
            Node* n=new Node(head->row+u1,head->col+r1);
            arr[head->row][head->col]='#';
            head=n;
            arr[head->row][head->col]='*';
            tail=n;
            return false;
        }
        Node* temp = head;
        while(temp->next != tail){
        temp=temp->next;
       }
       Node* todelete=temp->next;
       arr[temp->next->row][temp->next->col]='#';
       tail = temp;
       temp->next = NULL;
       delete todelete; // Deleting tail

       arr[head->row+u1][head->col+r1]='*';
       insertathead(head->row +u1,head->col+r1);
       return false;
    
     
}

int Snake:: size(){
        Node* temp = head;
        int sz=0;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
        return sz;
}

void Snake:: makeempty(){
        Node* temp = head;
        while(temp!=NULL){
            Node* todelete=temp;
            temp=temp->next;
            delete todelete;
        }

}
 
        
