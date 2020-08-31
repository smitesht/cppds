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
    void addAtTop(int data);
    void addAfterPos(int pos, int data);
    void deleteAtPos(int pos);
    void reverse();
    void print();
    void printReverse();
    void isPalindrome();
    
    
private:
    bool printReverse(stNode *pNode);
    bool isPalindrome(stNode *pNode);
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

// remove last element
int SingleLinkList::pop_back(){
    stNode *pTemp = m_pHead;
    
    //iterate till second last
    while(m_pHead->pNext->pNext != nullptr){       
        
        m_pHead = m_pHead->pNext;
        
    }
    
    //assign null to second last next and then delete last element
    stNode *p = m_pHead->pNext;
    m_pHead->pNext = nullptr;
    int data = p->data;
    m_pHead = pTemp;
    delete p;
 
   
    return data;
}

void SingleLinkList::addAtTop(int data){
    
    if(m_pHead == nullptr){
        m_pHead = new stNode();
        m_pHead->data = data;
        m_pHead->pNext = nullptr;
    }
    else
    {
        stNode *p = new stNode();
        p->data = data;
        p->pNext = m_pHead;
        m_pHead = p;
    }
            
}

void SingleLinkList::print(){
    stNode *pNode = m_pHead;
    while(m_pHead != nullptr){
        cout<<m_pHead->data<<endl;
        m_pHead = m_pHead->pNext;
    }
    
    m_pHead = pNode;
}

void SingleLinkList::addAfterPos(int pos, int data){
    
    if(pos == 0){
        addAtTop(data);
    }
    else
    {
        stNode *pTemp = m_pHead;
        int currPos = 0;
        while(m_pHead->pNext != nullptr){
            if(currPos == pos){
                break;
            }         
            
            currPos++;
            
            m_pHead = m_pHead->pNext;
        }
        
        stNode *p = new stNode();
        p->data = data;
        p->pNext = m_pHead->pNext;
        m_pHead->pNext = p;
        
        m_pHead = pTemp;
    }
}

void SingleLinkList::deleteAtPos(int pos){
    
    if(m_pHead != nullptr)
    {
        if(pos == 0){
            stNode *p = m_pHead;
            m_pHead = m_pHead->pNext;
            delete p;
        }
        else
        {
            int currPos = 0;
            stNode *pTemp = m_pHead;
            
            while(m_pHead->pNext->pNext != nullptr){
                if(currPos == (pos -1)){
                    stNode *p = m_pHead->pNext;
                    m_pHead->pNext = m_pHead->pNext->pNext;
                    delete p;
                    m_pHead = pTemp;
                    break;                    
                }
                
                currPos++;
                m_pHead = m_pHead->pNext;
            }
        }
    }
    
}

void SingleLinkList::reverse(){
    
    stNode *pPrev = nullptr;
    stNode *pNext;
    stNode *pCurr = m_pHead;
    
    
    while(pCurr != nullptr){
        
        pNext = pCurr->pNext;
        pCurr->pNext = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }
    
    m_pHead = pPrev;
    
}

void SingleLinkList::printReverse(){
    printReverse(m_pHead);    
}

bool SingleLinkList::printReverse(stNode *pNode){
    
    if(pNode == nullptr)
        return true;
    else
        printReverse(pNode->pNext);
    
    cout<<pNode->data<<endl;
}

void SingleLinkList::isPalindrome(){
    stNode *pTemp = m_pHead;
    
    if(isPalindrome(m_pHead))
    {
        cout<<"List is Palindrome"<<endl;
    }
    else
    {
        cout<<"No List is NOT Palindrome"<<endl;
    }
    
    m_pHead = pTemp;
}

bool SingleLinkList::isPalindrome(stNode *pNode){
    
    if(pNode == nullptr)
        return true;
    
    bool isPalin =  isPalindrome(pNode->pNext);
    
    if(isPalin == false)
        return false;
    
    if(pNode->data == m_pHead->data){
        m_pHead = m_pHead->pNext;
        return true;
    }
    
    return false;
    
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
    
    s1.addAtTop(9);
    s1.addAtTop(5);
    
    s1.addAfterPos(2,99);
    s1.deleteAtPos(2);
    s1.reverse();
    s1.reverse();
    s1.print();
    s1.printReverse();
    
    s1.isPalindrome();
    
    return 0;
}

