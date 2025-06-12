#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
using namespace std;

class Snake;  // Forward declaration

class Node {
    int row;
    int col;
    Node* next;

public:
    Node(int i, int j);
    friend class Snake;
};

class Snake{
    Node* head;
    Node* tail;
    public:
    Snake(){}
    void insertathead(int i,int j){}
    void insertattail(int i,int j){
        Node* n=new Node(i,j);
        if(head==NULL && tail==NULL){
            head=n;
            tail=n;
            return;
        }
        tail->next=n;
        tail=n;
    }
    Node* getTail(){
        return tail;

    }
    Node* getHead(){
        return head;
    }
    void printHead(){
        cout<<head->row<<" "<<head->col<<endl;
    }
    // Function to mark the path of the Snake
    void markarray(char** arr,int n){
        
        Node* temp=head;
        while(temp!=tail){
            arr[temp->row][temp->col]='*';
            temp=temp->next;
        }
        arr[temp->row][temp->col]='*';
        
    }
    // Function to display game state
    void printarray(char** arr,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;

        }
        cout<<endl;
    }
    // Function to check the validity of the move
    bool isValid(int u1,int r1,char** arr,int n){
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
    // Function to move the Snake based on user input
    bool move(int u1,int r1,char** arr,int n){
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
    int size(){
        Node* temp = head;
        int sz=0;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
        return sz;
    }

    // To delete/ free memory on game end
    void makeempty(){
        Node* temp = head;
        while(temp!=NULL){
            Node* todelete=temp;
            temp=temp->next;
            delete todelete;
        }

    }

};

#endif // SNAKE_HPP
