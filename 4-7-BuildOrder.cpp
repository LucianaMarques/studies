#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

/* Base tree node definition */
class Node {
public:
    set<char> nexts;
    int data;
    int inc = 0;
    Node(int d){
        this->data = d;
    }
};

int main(){
    return 0;
}

void print_order(vector<char> projects, vector<pair<char,char>> dep){
    // Create graph
    map<char, Node *> graph = create_graph(projects, dep);
    // Create order queue
    queue<char> print;    
}

map<char, Node *> create_graph(vector<char> projects, vector<pair<char,char>> dep){
    map<char, Node *> p_graph;
    for (int i = 0; i < projects.size(); i++){
        p_graph[projects[i]] = new Node(projects[i]);
    }
    for (int i = 0; i < dep.size(); i++){
        pair <char,char> p = dep[i];
        p_graph[p.first]->nexts.insert(p.second); // adds the dependency
        p_graph[p.second]->inc++; //increases the incoming number;
    }
    return p_graph;
}

queue<char> create_queue(map<char, Node *> graph, vector<char> project){
    set<char> gone;
    queue<char> result;
    for (int i = 0; i < projects.size(); i++){
        if (graph[projects[i]]->inc == 0){
            if (gone.find(projects[i]) == gone.end()){
                gone.insert(projects[i]);
                result.push(projects[i]);
            }
        }
    }
    gone.clear();
    return result;
}