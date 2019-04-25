#include<iostream>
#include<conio.h>
using namespace std;
class Node{
public:
    Node *prev;
    Node *next;
    int data;
};
class doublylinkedlist{
private:
    Node *head;
    
public:
    doublylinkedlist() {
        head= NULL;
    }
    void insertbegin(int val){
        Node*ptr = new Node;
        ptr->next = NULL;
        ptr->prev = NULL;
        ptr->data = val;
        if (head!=NULL)
        {
            ptr->next = head;
        }
        head = ptr;
    }
        void insertpos(int pos,int val){
            Node *temp = head;
            Node*pr = NULL;
            bool found = true;
            if (head == NULL)
            {
                cout << "value doesnt exist";
            }
            if (temp->data=val)
            {
                Node*ptr = new Node;
                ptr->data = val;
                ptr->prev = temp;
                ptr->next=temp->next
            }
            while (temp->data!=pos)
            {
                pr = temp;
                temp = temp->next;
                if (temp==NULL)
                {
                    found = false;
                    cout << "value doesnt exist";
                    break;
                }
            }
            if (found==true)
            {
                Node*ptr = new Node;
                ptr->data = val;
                ptr->prev = pr;
                pr->next = ptr;
                ptr->next = temp;
                temp->prev = ptr;
            }
    }
        void insertlast(int val){
            Node*ptr = new Node;
            ptr->next = NULL;
            ptr->data = val;
            Node *temp = head;
            if (head==NULL)
            {
                ptr->prev=NULL;
            }
            else
            {
                while (temp->next!=NULL)
                {
                    temp = temp->next;
                }
                ptr->prev = temp;
                temp->next = ptr;
            }
        }
    void display(){
        Node *ptr = head;
        while (ptr!=NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};
void main(){
    doublylinkedlist d1;
    d1.insertbegin(12);
    d1.insertpos(12, 13);
    d1.insertlast(14);
    d1.insertlast(15);
    d1.insertlast(16);
    d1.insertlast(17);
    d1.display();
    _getch();
}