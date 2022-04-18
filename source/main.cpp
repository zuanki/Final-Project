#include <iostream>
#include "node.hpp"

void PrintNode(Node* &a){
    while(a != NULL){
        std::cout<<a->data<<std::endl;
        a = a->next;
    }
}

int main(int argc, char* argv[]){
    Node* a = new Node();
    Node* b = new Node();
    a->data = 100;
    b->data = 111;
    a->next = b;
    PrintNode(a);
    return 0;
}