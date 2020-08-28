/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: smt
 *
 * Created on 28 August 2020, 12:25 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct stNode{
    int data;
    stNode *pNext;
};

class stack{
    
public:
    stack();
    void push(int num);
    int pop();
    void print();
    ~stack();    
private:
    stNode *m_pTop;
    int size;
};
       
stack::stack():m_pTop(nullptr),size(0){
    
}

void stack::push(int num){
    
    try
    {
        stNode *pNode = new stNode();
        pNode->data = num;
        pNode->pNext = m_pTop;
        m_pTop = pNode;
        size++;
    }
    catch(std::bad_alloc& er){
        cout<<"bad memory allocation"<<endl;
    }
}

void stack::print(){
    
    stNode *pTemp = m_pTop;
    
    while(pTemp != nullptr){
        cout<<pTemp->data<<endl;
        pTemp = pTemp->pNext;
        
    }
}

int stack::pop(){
    
    int data = 0;
    
    if(m_pTop != nullptr){
    
        data = m_pTop->data;
        stNode *pTemp = m_pTop;
        m_pTop = m_pTop->pNext;
        delete pTemp;
        size--;
    }
    else
    {
        cout<<"stack is empty"<<endl;
    }
    return data;
}


stack::~stack(){
    
    while(m_pTop != nullptr){
        stNode *pTemp = m_pTop;
        m_pTop = m_pTop->pNext;
        delete pTemp;
    }    
    
}

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    
    s1.print();
    
    s1.pop();
    s1.pop();
    
    s1.print();
    
    return 0;
}

