#ifndef SNAKE_HPP
#define SNAKE_HPP
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
    void insertattail(int i,int j){}

    Node* getTail(){ return tail;}
    Node* getHead(){ return head; }
    void printHead(){ cout<<head->row<<" "<<head->col<<endl; }
   
    void markarray(char** arr,int n){}  // Function to mark the path of the Snake
    void printarray(char** arr,int n){}  // Function to display game state
   
    bool isValid(int u1,int r1,char** arr,int n){}  // Function to check the validity of the move
    bool move(int u1,int r1,char** arr,int n){} // Function to move the Snake based on user input

    int size(){}
    void makeempty(){}   // To delete free memory on game end

};

#endif // SNAKE_HPP
