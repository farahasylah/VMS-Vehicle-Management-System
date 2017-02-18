
#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>
using namespace std;




template <typename T>
struct Node {
  T info;
  Node<T> *next;
};

template <typename T>
class LList {
  Node<T> *start,*current;
public:
  LList() {
      start =  NULL; }
  ~LList() { makeEmpty(); }

LList<T> & operator= (LList<T>& source) {
        makeEmpty();
        T element;
        for(int i = 1; i <= source.size(); i++)
        {
            source.retrieve(element, i);
            insert(element, i);
        }
    }

 void insertEnd (T& newElement) {
    Node<T> *newNode = new Node<T>;
    newNode->info = newElement;
    newNode->next = NULL;

  if (start == NULL){
        start = newNode;
        return;
    }
     Node<T>* ptr = start;
    while(ptr->next != NULL)
    ptr = ptr->next;
    ptr->next = newNode;
 }

  bool insertAfter (int targetindex, T& newElement) {
    if(targetindex < 1 || start== NULL)
        return false;
    Node<T> *newNode = new Node<T>;
    newNode->info = newElement;
    Node<T> *ptr = start;
    int i = 1;
    while(ptr != NULL && i <= targetindex ){
        if(i == targetindex)
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

 bool modify (int targetindex, T*& modifyV)
 {  if (targetindex < 1 || start == NULL)
        return false;
    Node<T>* ptr = start;
    int i = 1;
    while (ptr != NULL && i <= targetindex)
    {
      if (i == targetindex)
      { modifyV = &(ptr->info);
        return true;
      }
      else
      { ptr = ptr->next;
        i++;
      }
    }
    return false;
  }



  bool replace (const T & newElement) {
    if (current == NULL) return false;
    current->info = newElement;
    return true;
  }

bool insertnew (int targetindex, T& insertV)
 {  if (targetindex < 1 || start == NULL)
        return false;
    Node<T>* ptr = start;
    int i = 1;
    while (ptr != NULL && i <= targetindex)
    {
      if (i == targetindex)
      { ptr->info = insertV;
        return true;
      }
      else
      { ptr = ptr->next;
        i++;
      }
    }
    return false;
  }


bool erase (int targetindex)
{  if (targetindex < 1 || start == NULL)
        return false;
    Node<T>* ptr = start;
    int i = 1;
    while (i != targetindex)
        ptr = ptr->next;
    Node<T> *ptr2 = ptr->next;
	ptr->next = ptr2->next;
	delete ptr2;
   return true;
}

  void removeFront()
  {
    if (start != NULL)
    {   Node<T>* ptr = start;
        start = start->next;
        delete ptr;
    }
  }

  void makeEmpty()
  { while (start != NULL)
    removeFront();
  }


friend ostream& operator<< (ostream& os, LList <T>& list)
 {
     Node<T> *ptr = list.start;
    int i = 1;
    while (ptr != NULL)
    {   os <<"   "<<i++ << "        " <<ptr->info<<endl;
        ptr = ptr->next;
    }
    cout <<endl;
    return os;
 }

  friend istream& operator>> (istream& is,LList <T>& list)
    {   cout << "Input model of vehicle:  ";
         Node<T> *ptr = list.start;
        is >>  ptr->info;
        return is;
    }
};

#endif
