#include<bits/stdc++.h>
using namespace std;

struct Node{

    Node* links[26];
    bool flag=false;

    bool containsKey(char ch){

        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node){

        links[ch-'a']=node;
    }

    Node* get(char ch){

        return links[ch-'a'];
    }

    bool setEnd(){

        flag=true;
    }

    bool isEnd(){
        return flag;
    }

};


class Trie {

    private:
    Node* root;


    public:

    /* initialize your data structure here */
    Trie(){
        root=new Node();
    }   


    /* insert a word into trie */
    void insert(string word){

        Node* node=root;

        for(int i=0;i<word.size();i++)
        {   
            if(!node->containsKey(word[i])){

                node->put(word[i],new Node());
            }

            //move to the reference trie
            node=node->get(word[i]);
        }

        node->setEnd();
    }


    /* Return if the word is in the trie */
    bool search(string word){

        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            return false;

            node=node->get(word[i]);
        }

        return node->isEnd();
    }

    /* Return if any word in the trie start with given word */
    bool startWith(string word){

        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            return false;

            node=node->get(word[i]);
        }

        return true;
    }
};


int main()
{

}
