/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: smt
 *
 * Created on 28 August 2020, 2:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct stNode{
    T data;
    stNode<T> *pNext;
};

template<typename T>
class stack{
    
public:
    stack();
    void push(T num);
    T pop();
    void print();
    ~stack();    
private:
    stNode<T> *m_pTop;
    int size;
};

template<typename T>
stack<T>::stack():m_pTop(nullptr),size(0){
    
}

template<typename T>
void stack<T>::push(T num){
    
    try
    {
        stNode<T> *pNode = new stNode<T>();
        pNode->data = num;
        pNode->pNext = m_pTop;
        m_pTop = pNode;
        size++;
    }
    catch(std::bad_alloc& er){
        cout<<"bad memory allocation"<<endl;
    }
}

template<typename T>
void stack<T>::print(){
    
    stNode<T> *pTemp = m_pTop;
    
    while(pTemp != nullptr){
        //pTemp->data.print();
        pTemp = pTemp->pNext;
        
    }
}

template<typename T>
T stack<T>::pop(){
    
    T data;
    
    if(m_pTop != nullptr){
    
        data = m_pTop->data;
        stNode<T> *pTemp = m_pTop;
        m_pTop = m_pTop->pNext;
        delete pTemp;
        size--;
    }
    else
    {
        cout<<"stack is empty"<<endl;
        m_pTop = nullptr;
    }
    return data;
}

template<typename T>
stack<T>::~stack(){
    
    while(m_pTop != nullptr){
        stNode<T> *pTemp = m_pTop;
        m_pTop = m_pTop->pNext;
        delete pTemp;
    }    
    
}

struct stEmployee{
    int Id;
    string name;
    
    void print(){
        cout<<"ID: "<<Id<<" Name: "<<name<<endl;
    }
};

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    stack<stEmployee> s1;
    
    stEmployee e1;
    e1.Id = 1001;
    e1.name = "Smitesh";
    
    stEmployee e2;
    e2.Id = 1002;
    e2.name = "Amit";
    
    stEmployee e3;
    e3.Id = 1003;
    e3.name = "Ankur";
    
    s1.push(e1);
    s1.push(e2);
    s1.push(e3);
    
    //int n = s1.pop();
    stEmployee e = s1.pop();
    e.print();
    
    
    
    //s1.push(40);
    //s1.push(50);
    //s1.push(60);
    
    //s1.print();
    
   // s1.pop();
    //s1.pop();
    
    //s1.print();
    
    return 0;
}
