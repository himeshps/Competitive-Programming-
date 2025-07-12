#include<bits/stdc++.h>
using namespace std; 

#define NUM_CHAR 256

struct Node {
    Node *links[26] ;
    bool terminal = false; 
    bool hasKey( char ch ){
        return (links[ch - 'a'] != NULL); 
    }
    void put(char ch , Node* node){
        links[ch - 'a'] = node; 
    }  
    Node* get(char ch){
        return links[ch - 'a'] ;
    } 
    void setEnd(){
        terminal = true;
    }
    bool isEnd(){
        return terminal; 
    }
};

class Trie{
private :
    Node* root; 

public : 
    Trie(){
        root = new Node(); 
    }

    void insert(string word){
        Node* node = root; 
        for( int i = 0 ; i < word.length() ; ++i){
            if(!node -> hasKey(word[i])){
                node -> put(word[i] , new Node()); 
            }
            node = node -> get(word[i]); 
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node = root; 
        for( int i = 0 ; i < word.length() ; ++i){
            if(!node->hasKey(word[i])){
                return false;
            }
            node = node->get(word[i]); 
        }
        return node->isEnd(); 
    }

    bool starts(string word){
        Node* node = root;
        for( int i = 0 ; i < word.length() ; ++i){
            if(!node -> hasKey(word[i])){
                return false; 
            }
            node = node -> get(word[i]); 
        }
        return true; 
    }
}; 

int main(){

}
