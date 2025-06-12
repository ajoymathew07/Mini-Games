#include<iostream>

#include <thread>  // for std::this_thread::sleep_for
#include<windows.h>
#include<conio.h>

#include<snake.hpp>

using namespace std;

void printarray(char** arr,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;

        }
        cout<<endl;
}

void take_input(char c,int& u1,int& r1){
     if(c=='w'){
            u1--;
        }else if(c=='s'){
            u1++;
        }else if(c=='d'){
            r1++;
        }else if(c=='a'){
            r1--;
        }else{
            cout<<"Enter a Valid input: (w,a,s,d)"<<endl;
    }
}

void addFood(char** arr, int n){
    int c1,c2;
    while(true){
        c1=rand()% n;
        c2=rand()% n;
        if(arr[c1][c2]=='#'){
            break;
        }
    }
    
    arr[c1][c2]='$'; // Food
}
int main(){
    srand(time(0));
    int n;
    cin>>n;
    Snake s;
    char** arr = new char*[n];
    for(int i=0;i<n;i++){
        arr[i]=new char [n];
        for(int j=0;j<n;j++){
            arr[i][j]='#';
        }
    }
    int i = rand() % n;
    int j = rand() % n;
    
    s.insertathead(i,j);
    addFood(arr,n);
    // Initializing game board
    s.markarray(arr,n);
    s.printarray(arr,n);
    s.printHead(); 
    char c;
    cin>>c;
    bool flag=true;
    int counter=1000;
    while(true){
        if(flag==false){
            if(_kbhit()){
                c=_getch(); 
            }
        }
        flag=false;
        int u1=0;
        int r1=0;
        take_input(c,u1,r1);
        if(s.isValid(u1,r1,arr,n)){
            if(s.move(u1,r1,arr,n)){ 
                if(counter>150){
                counter-=100;
            }
            addFood(arr,n);
            s.printarray(arr,n);
            //std::this_thread::sleep_for(std::chrono::milliseconds(300)); 
            Sleep(counter);  
            }else{
                cout<<"Score: "<<s.size()<<endl;
                break;
            }
        }
    }
    s.makeempty();
    return 0;
}
