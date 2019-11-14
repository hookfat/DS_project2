#include "p2.h"
using namespace std;
void myqueue::push(Point* p)
{
    if(tail != nullptr){
        tail->next = new node(p);
        tail = tail->next;
    }
    else{
        head = new node(p);
        tail = head;
    }
}

void myqueue::pop()
{
    node* temp;
    if(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    if(head == nullptr){
        tail = nullptr;
    }
}

Point* myqueue::gethead()
{
    return head->data;
}

Point* myqueue::gettail()
{
    return tail->data;
}

bool myqueue::isempty()
{
    return (head == nullptr);
}

myqueue::~myqueue()
{
    node* temp;
    if(head == nullptr)
        return;
    temp = head->next;
    while(temp != nullptr){
        delete head;
        head = temp;
        temp = temp->next;
    }
    delete head;
}
