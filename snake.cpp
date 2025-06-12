#include "Snake.hpp"
#include <iostream>
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