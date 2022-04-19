/**
 * Author: Matthew Ricketts
 * File: Graph.h
 * Project: CS210 Homework 4
 * Date: 4/18/2022
 * Excerpt: Graph and minimum spanning tree implementation
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

struct EdgeNode {
	int y;
	int weight;
	struct EdgeNode* next;

	EdgeNode(int y = 0, int weight = 0, EdgeNode* next = nullptr)
		: y{ y }, weight{ weight }, next{ next } { }
};

class Graph {

private:
	static const int MAXV = 50;
	EdgeNode* edges[MAXV + 1] = {};
	int nvertices = 0;
	int nedges = 0;
	// Note: you may need more instance variables (ivars) here depending on your implementation

public:

	Graph()
	{
		for (int k = 0; k <= MAXV; k++) {
			edges[k] = new EdgeNode(k, 0, nullptr);
		}
	}

	/**
     * Destructor for the graph
     */
	~Graph() {}

	/**
	 * Add an edge from i to j with weight d
	 */
	void link(int i, int j, int d) {

		// Weight and Nodes must be positive
		// Nodes must be less than 50
		if (i >= 0 && j >= 0 && d >= 0 && i <= 50 && j <= 50) {

			// Add an edge both ways between the two nodes
			// i to j
			EdgeNode* newEdge = new EdgeNode(edges[j]->y, d, edges[i]->next);
			edges[i]->next = newEdge;

			// j to i
			newEdge = new EdgeNode(edges[i]->y, d, edges[j]->next);
			edges[j]->next = newEdge;

		}
	}


	/**
	 * Print the minimum spanning tree using Prim's algorithm
	 */
	void printMST() {

		// Array to store constructed MST
		int parent[MAXV+1];

		// Key values used to pick minimum weight edge in cut
		int keyWeights[MAXV+1];

		// To represent set of vertices included in MST
		bool visited[MAXV+1];

		// Initialize all keys as INFINITE
		for (int i = 0; i < MAXV+1; i++)
			keyWeights[i] = INT_MAX, visited[i] = false;

		// Initialize the first vertex as the root of the MST
		int i = 0;
		while (edges[i]->next == nullptr) i++;

		keyWeights[i] = 0;		// Distance to the root of the MST is 0
		parent[i] = -1; // First node is always root of MST

		// The MST will have V vertices
		for (int count = 0; count <= MAXV; count++)
		{
			// If the node has any connections
			if (edges[count]->next != nullptr) {

				// Pick the minimum key vertex from the set of vertices not yet included in MST
				int u = minEdge(visited, keyWeights);

				// If no MST, return and print error
				if (u == -1) {
					cout << "\nNo MST, there are unreachable nodes";
					return;
				}


				// Add the picked vertex to the MST Set
				visited[u] = true;

				// Update key value and parent index of the adjacent vertices of the picked vertex.
				// Consider only those vertices which are not yet included in MST
				EdgeNode* p = edges[u];
				while (p != nullptr) {
					
					// mstSet[v] is false for vertices not yet included in MST
					// Update the key only if p->weight is smaller than key[v]
					if (visited[p->y] == false && p->weight < keyWeights[p->y]) {
						parent[p->y] = u;
						keyWeights[p->y] = p->weight;
					}

					// Go to the next connected node
					p = p->next;
			
				}
			}

		}

		// Print the MST
		printMST(parent, keyWeights);



	}

	/**
	*  Find the nearest non-visited vertex
	*/
	int minEdge(bool visited[], int keyWeights[]) {

		int min = INT_MAX;
		int u = -1;

		// Look through the vertexes for the minimum unvisited edge
		for (int v = 0; v <= MAXV; v++)

			// If the vertex has not been visited and weight is the smallest found yet,
			// Set the keyWeight to the vertex weight
			// Set the value to return to the vertex
			if (visited[v] == false && keyWeights[v] < min)
				min = keyWeights[v], u = v;

		// Return the min vertex
		return u;
	}

	/**
	*  Print the minimum spanning tree
	*/
	void printMST(int parent[], int keyWeights[])
	{
		// Counter for length of tree
		int length = 0;
		cout << "\nEdge \tWeight\n";

		// Print the MST
		for (int i = 0; i <= MAXV; i++)

			// If the edge exists and the node is in the tree
			if (keyWeights[i] < INT_MAX && parent[i] >= 0) {
				cout << parent[i] << " - " << i << " \t" << keyWeights[i] << " \n";
				length++;
			}
		
		// Print length of tree
		cout << "\nFor a total length of " << length << "\n\n";
	}

};

#endif
