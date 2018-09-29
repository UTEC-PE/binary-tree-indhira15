#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;


struct node{
public:
    int data;
    node* der;
    node* izq;

};

class arbol{
public:
    stack<node*> nodos;
    node* raiz;
    arbol():raiz(nullptr){}
    void print_nodos(node* raiz){
        if (raiz!= nullptr){
            print_nodos(raiz->izq);
            ::cout<<raiz->data;
            print_nodos(raiz->der);
        }
    }
    node* get_root(){
        return raiz;
    }


    void insert(int data, node* raiz2){
        if(!raiz){
            raiz = new node {data, nullptr, nullptr};
        }
        else{
            if(raiz2->data == data){return;}
            node* nodo = raiz2;
            if(data < nodo -> data){
                if(nodo -> izq){
                    nodo = nodo -> izq;
                    insert(data,nodo);
                }
                else{
                    nodo -> izq = new node{data, nullptr, nullptr};
                }
            }
            else{
                if(nodo -> der){
                    nodo = nodo -> der;
                    insert(data,nodo);
                }
                else{
                    nodo -> der = new node{data, nullptr, nullptr};
                }
            }
        }
    }


    void buildStack(node* nodo){
        if(nodo){
            buildStack(nodo->der);
            nodos.push(nodo);
            buildStack(nodo->izq);
        }
        else {return;}
    }
    stack<node*> getStack(){
        return nodos;
    }

}arbol1;




class Iterator{
public:
    stack <node*> pile;
    node* current;

    Iterator(){
        current = nullptr;
    }

    Iterator (node* nodo){
        this -> current = nodo;
    }

    Iterator operator++(){
        pile.pop();
        current = pile.top();
    }

    bool operator!=(Iterator other){
        return current -> data != other.current -> data;
    }

    int operator*(){
        return current -> data;
    }

    Iterator begin(){
        this -> current = pile.top();
        return* this;
    }

    Iterator setStack(stack<node*> nodos){
        pile = nodos;
        return* this;
    }

};



int main() {
    arbol1.insert(10, arbol1.get_root());
    arbol1.insert(15, arbol1.get_root());
    arbol1.insert(9, arbol1.get_root() );
    arbol1.insert(15, arbol1.get_root());
    cout<<arbol1.get_root();

    arbol1.buildStack(arbol1.get_root());

    Iterator it;
    it.setStack(arbol1.getStack());

    for(it = it.begin(); it.pile.size()>1; ++it){
        cout << *it << " ";
    }
    cout << *it;



    return 0;
}




