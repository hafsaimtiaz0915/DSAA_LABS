#include<iostream>
#include<list>
#include<stack>
using namespace std;

template <class T>
void takeInput(T &reference) {
	cin >> reference;
	while (!cin) {
		cout << "\n\tInvalid Input, Try Again: " << endl;
		cout << "\n\t\t Your Input: ";
		cin.clear();
		cin.ignore();
		cin >> reference;
	}
}

class Graph {
    int vertices;
    list<int>* adjacencyList;

public:
    Graph(int v) {
        vertices=v;
        adjacencyList=new list<int>[v];
    }
    void addEdge(int src, int des) {
        adjacencyList[src].push_back(des);
        adjacencyList[des].push_back(src);
    }
    void DFS(int startVertex) {
        bool visited[vertices ];
        for (int i = 0; i < vertices; ++i)
            visited[i] = false;
        stack<int> stack;
        visited[startVertex] = true;
        stack.push(startVertex);
        cout << "starting from vertex " << startVertex << ": ";
        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            cout << currentVertex << " ";
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    
};

int main() {

    int VerticesNo, src, des, vertexToStart;
    cout << "Enter the number of vertices (Integer): ";
    takeInput(VerticesNo);

    Graph graph(VerticesNo);

    do {
        cout << "\nEnter Edges (source) and (destination) or type [-1] to stop: ";
        takeInput(src);

        if (src == -1) {
            break;
        }

        takeInput(des);

        if (src < 0 || src >= VerticesNo || des < 0 || des >= VerticesNo) {
            cout << "\n\tInvalid vertices. They should be between 0 and " << VerticesNo - 1 << endl;
        } else {
            graph.addEdge(src, des);
        }
    } while (src != -1);

    cout << endl;

    

    do {
        cout << "\nEnter the starting vertex for DFS (In Integer): ";
        takeInput(vertexToStart);
        if (vertexToStart < 0 || vertexToStart >= VerticesNo) {
            cout << "\n\tInvalid starting vertex. It should be between 0 and " << VerticesNo - 1 << endl;
        }
    } while (vertexToStart < 0 || vertexToStart >= VerticesNo);

    graph.DFS(vertexToStart);

}
