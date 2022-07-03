#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
void addEdge(int x,int y);    // function to add edge to the graph
void bfs(int start);     // function to perform breadth first search on the graph

int main(){
     system("CLS");
     cout<<"Welcome!!!"<<endl;
     int v = 1000;  // number of vertices
     adj= vector<vector<int>>(v,vector<int>(v,0));     // adjacency matrix
	int numberOfNodes;
	printf("Please enter the number of loops: "); cin>>numberOfNodes;
	for(int i = 1; i <= numberOfNodes; i++){
       int x, y;
       cout<<"Please enter the value of node "<< i <<": ";     cin>>x;
       cout<<"Please enter the value of node " << i << " that you want to direct your node to: ";    cin>>y;
       addEdge(x, y);
  }
	int ans1;
	printf("Please enter the staring point: ");	cin>>ans1;
     bfs(ans1);   // to start the BFS search bfs(the starting edge)
     cout<<"\nThanks for using this algorithm for BFS!";
}

void addEdge(int x,int y){
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void bfs(int start){
	vector<bool> visited(adj.size(), false);     // Initializing the vector to false as no vertex is visited at the beginning
	vector<int> q;
	q.push_back(start);
	visited[start] = true;      	// set the starting point as visited

	int vis;
	while (!q.empty()) {
		vis = q[0];
		cout << vis << " ";      // Prints the current node
		q.erase(q.begin());
		// For every adjacent vertex to the current vertex
		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {
				q.push_back(i);     // Push the adjacent node to the queue
				visited[i] = true;       // to put the node in a visited array and set it as true
			}
		}
	}
}