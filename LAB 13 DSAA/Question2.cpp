#include <iostream>
#include <stack>
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
		int** adjacencyMatrix;
	public:
		Graph(int v) {
			vertices=v;
			adjacencyMatrix = new int*[vertices];
			for (int i = 0; i < vertices; ++i) {
				adjacencyMatrix[i] = new int[vertices];
				for (int j = 0; j < vertices; ++j)
					adjacencyMatrix[i][j] = 0;
			}
		}
		void addEdge(int src, int des) {
			adjacencyMatrix[src][des] = 1;
			adjacencyMatrix[des][src] = 1;
		}
		void DFS(int startVertex) {
			bool visited[vertices];
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
				for (int neighbor = 0; neighbor < vertices; ++neighbor) {
					if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
						visited[neighbor] = true;
						stack.push(neighbor);
					}
				}
			}
			cout << endl;
		}
		void displayGraph() {
			cout << "Adjacency Matrix:" << endl;
			for (int i = 0; i < vertices; ++i) {
				for (int j = 0; j < vertices; ++j) {
					cout << adjacencyMatrix[i][j] << " ";
				}
				cout << endl;
			}
		}
};
int main() {
	
	int VerticesNo,src,des,vertexToStart;
	cout << "Enter the number of vertices(Integer): ";
	takeInput(VerticesNo);

	Graph graph(VerticesNo);

	while (src != -1) {
    cout << "\nEnter Edges (source) and (destination) or type [-1]  to stop: ";
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
}

		
	cout << endl;

	graph.displayGraph();

	do {
		cout << "\nEnter the starting vertex for DFS(In Integer): ";
		takeInput(vertexToStart);
		if (vertexToStart < 0 || vertexToStart >= VerticesNo) {
			cout << "\n\tInvalid starting vertex.It should be between 0 and " << VerticesNo - 1  << endl;
		}
	} while (vertexToStart < 0 || vertexToStart >= VerticesNo);


	graph.DFS(vertexToStart);

}