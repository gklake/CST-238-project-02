/*
* Title: project-02.cpp
* Abstract: This program will implement a linked list recursively including the Big 3.
* Author: Gabrielle Lake
* Email: glake@csumb.edu
* Estimate: 6 hours
* Date: 11/12/2020
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;


bool Node::hasNext() const {
    return myNext != nullptr;
}

bool LinkedList::empty() const {
    return myFirst == nullptr;
}

void Node::display() const {
  cout << getData() << endl;
  if(hasNext()){
    myNext->display();
  }
}

void LinkedList::display() const {
    if(empty()){
      cerr << "Empty!" << endl;
      return;
    } else {
      Node * next = myFirst;
      next->display();
      cout << endl;
    }
}

// only append if this is the last node
// otherwise, recurse
void Node::append(int data) {
    if(hasNext()){
      myNext->append(data);
    } else {
      myNext = new Node(data);
    }
}

void LinkedList::append(int data) {
    if(empty()){
      myFirst = new Node(data);
      return;
    } else {
      myFirst->append(data);
    }
}

bool Node::search(int data) const {
    if(getData() == data){
      return true;
    } else if(!hasNext()) {
      return false;
    } else {
      return getNext()->search(data);
    }
}

bool LinkedList::search(int data) const {
    if(empty()){
      return false;
    } else {
      return getFirst()->search(data);
    }
}

bool Node::insertAfter(int oldData, int newData) {
    if(getData() == oldData){
      Node * newNode = new Node(newData);
      newNode->setNext(getNext());
      setNext(newNode);
      return true;
    } else if (!hasNext()){
      return false;
    } else {
      return getNext()->insertAfter(oldData, newData);
    }
}

bool LinkedList::insertAfter(int oldData, int newData) {
    if(empty()){
      return false;
    } else {
      return getFirst()->insertAfter(oldData, newData);
    }
}

bool Node::removeNext(int data) {
    if(!hasNext()){
      return false;
    } else if (getNext()->getData() == data) {
      Node * curr = getNext();
      Node * after = curr->getNext();
      curr->setNext(nullptr);
      delete curr;
      setNext(after);
      return true;
    } else {
      return getNext()->removeNext(data);
    }
}

bool LinkedList::remove(int data) {
    if(empty()){
      return false;
    } else if(getFirst()->getData() == data) {
      Node * n = myFirst;
      myFirst = n->getNext();
      n->setNext(nullptr);
      return true;
    } else {
      return getFirst()->removeNext(data);
    }
}

Node::~Node() { 
  if(hasNext()){
    delete myNext;
  }
}

LinkedList::~LinkedList() {
  if(!empty()){
    delete myFirst;
  }
}

Node::Node(const Node & source) {
  myData = source.getData();
  if(source.hasNext()){
    myNext = new Node(*source.getNext());
  }
}

LinkedList::LinkedList(const LinkedList & source) {
  if(!source.empty()){
    myFirst = new Node(*source.getFirst());
  }
}

LinkedList &LinkedList::operator=(const LinkedList & source) {

    if(this != &source) {
      if(!empty()){
        delete myFirst;
      }
      if(!source.empty()){
        myFirst = new Node(*source.getFirst());
      }
    }
    return * this;
}

Node::Node(int data) {
    myData = data;
}

void Node::setNext(Node * next) {
    myNext = next;
}

LinkedList::LinkedList() {
    myFirst = nullptr; 
}

