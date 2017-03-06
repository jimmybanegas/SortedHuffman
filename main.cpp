#include "Test.h"
#include "BinaryNode.h"
#include <iostream>
#include <queue>
using namespace std;

map<char,string> mapa_global;

void recorrerArbol(BinaryNode* actual,string codigo)
{
    if(actual->value!= NULL )
    {
        mapa_global[actual->value] = codigo;
    }else
    {
        recorrerArbol(actual->left,codigo+"0");
        recorrerArbol(actual->right,codigo+"1");
    }
}

map<char,string> getHuffmanCodes(BinaryNode* huffman_tree)
{
    mapa_global.clear();

    recorrerArbol(huffman_tree,"");

    return mapa_global;
}

map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
    //Crear dos colas de nodos binarios
    queue<BinaryNode*> q1;
    queue<BinaryNode*> q2;
    BinaryNode *ni, *n1, *n2;

    //Agregar todos los caracteres c[] con sus respectivas frecuencias f[] a q1, se deben agregar de menor a mayor
    //Ya vienen ordenados de menor a mayor int arr2[] = {5, 10, 12, 13, 19, 91};

    for(int i=0;i<characters.size();i++)
        q1.push(new BinaryNode(characters[i], frequencies[i]));

    //Mientras
    while(!(q1.empty() && q2.size()==1)) {
    //while(q1.size()>1 && q2.empty()) {

         //El hijo izquierso
    for(int x = 0;x<2;x++){
        if (q1.empty()) {
            if(x==0){
                n1 = q2.front();
                q2.pop();
            }
            else if(x==1){
                n2 = q2.front();
                q2.pop();
            }
        } else if (q2.empty()) {
             if(x==0){
                n1 = q1.front();
                q1.pop();
             }else if(x==1){
                n2 = q1.front();
                q1.pop();
             }
        } else if (q1.front()->frequency  < q2.front()->frequency) {
            if(x==0){
                n1 = q1.front();
                q1.pop();
            }else if(x==1){
                n2 = q1.front();
                q1.pop();
            }
        } else {
            if(x==0){
                n1 = q2.front();
                q2.pop();
            }else if(x==1){
                n2 = q2.front();
                q2.pop();
            }
        }
    }
        //Crear nodo intermedio ni
        ni = new BinaryNode(NULL, n1->frequency + n2->frequency);

        if(q1.size() != 0){
            ni->left = n1;
            ni->right = n2;
        }
        else{
            ni->left = n2;
            ni->right = n1;
        }

        cout<<"Q1 SIZE:"<<q1.size()<<endl;
        cout<<"Q2 SIZE:"<<q2.size()<<endl;

        /*ni->left->value = n1->value;
        ni->left->frequency = n1->frequency;
        ni->left->left = n1->left;
        ni->left->right = n1->right;*/


        q2.push(ni);

        cout<<"NI: "<<ni->frequency<<" left: "<<ni->left->value<<"-"<<ni->left->frequency<<
                                     " right: "<<ni->right->value<<"-"<<ni->right->frequency<<endl;


    }

  /*  ni = new BinaryNode('NULL', q1.front()->frequency + q2.front()->frequency);
    ni->left = q1.front();
    ni->right = q2.front();*/

  //  q2.push(ni);

    map<char,string> answer = getHuffmanCodes(q2.front());
    return answer;
}

int main ()
{
    test();
    return 0;
}
