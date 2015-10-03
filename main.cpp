#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::queue;
using std::cout;
using std::endl;

struct Node{
    int data;
    vector<Node*> neighbors;
    bool visited = false;
};

bool isConnected(Node* n1, Node* n2){
    queue<Node*> q;
    q.push(n1);
    n1->visited = true;
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current == n2)
            return true;
        for(Node* neighbor: current->neighbors){
            if(!neighbor->visited){
                neighbor->visited = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]){
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    
    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n3);
    
    n3.neighbors.push_back(&n4);
    
    cout << (isConnected(&n1, &n4) ? "True" : "False") << endl;
}