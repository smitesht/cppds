/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: smt
 *
 * Created on 29 August 2020, 2:24 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct stNode{
    int data;
    stNode *pNext;
};

class SingleLinkList{
    
public:
    SingleLinkList();
    void push_back(int data);
    int pop_back();
    /*void addAtTop(int data);
    void addAfterPos(int pos, int data);
    void deleteAtPos(int pos);
    void print();*/
    
private:
    stNode *m_pHead;    
};


SingleLinkList::SingleLinkList():m_pHead(nullptr){
    
}

void SingleLinkList::push_back(int data){
    
    if(m_pHead == nullptr){
        m_pHead = new stNode();
        m_pHead->data = data;
        m_pHead->pNext = nullptr;
    }
    else
    {
        stNode *pTemp = m_pHead;
        
        while(m_pHead->pNext != nullptr){
            m_pHead = m_pHead->pNext;
        }
        
        stNode *p = new stNode();
        p->data = data;
        p->pNext = nullptr;
        m_pHead->pNext = p;
        
        m_pHead = pTemp;        
    }
}

int SingleLinkList::pop_back(){
    stNode *pTemp = m_pHead;
    
    while(m_pHead->pNext != nullptr){
        m_pHead = m_pHead->pNext;
    }
    
    int data = m_pHead->data;
    m_pHead->pNext = nullptr;
    delete m_pHead;
    m_pHead = pTemp;
}

/*
 * 
 */
int main(int argc, char** argv) {

    SingleLinkList s1;
    s1.push_back(10);
    s1.push_back(20);
    s1.push_back(30);
    s1.push_back(40);
    
    s1.pop_back();
    return 0;
}

