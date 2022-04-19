/**
 * Author: Matthew Ricketts
 * File: Source.cpp
 * Project: CS210 Homework 4
 * Date: 4/18/2022
 * Excerpt: Graph and minimum spanning tree menu
 */

#include <iostream>
#include <string>

#include "Graph.h"

string toLower(string);
void debugFillGraph1(Graph);
void debugFillGraph2(Graph);

int main() {

	string userMenuOption;

	cout << "\n\n\nThis program finds the minimum spanning tree of a graph.\n";

	do {

		cout << "\n\nWhat would you like to do:\n"
			"MST: Add a graph and print the MST\n"
			"E: exit\n\n";

		// Get user input
		cin >> userMenuOption;

		// Implement menu
		if ("mst" == toLower(userMenuOption)) {

			// Create the graph object
			Graph graph = Graph();

			// Declare variables for getting user input
			int from, to, weight;

			// Get the nodes to link
			do {

				cout << "\nEnter the nodes to link and the weights separated by spaces (e.g. 1 2 3 <enter>...). Enter -1 -1 -1 to finish adding links\n";

				cin >> from;
				cin >> to;
				cin >> weight;

				// Link the nodes
				graph.link(from, to, weight);

				cout << "Edge Added\n";

			} while (from != -1 && to != -1 && weight != -1);

			//debugFillGraph1(graph);

			cout << "\n\nThank you! A Minimum Spanning Tree for the graph is:";

			graph.printMST();


		}
		else if ("e" != toLower(userMenuOption)) {
			cout << "Invalid Input";
		}


	} while (toLower(userMenuOption) != "e");


	return 0;
}

/**
*  Function to convert a string to lowercase
*  Param: toConvert, String to convert to lowercase
*/

string toLower(string toConvert) {

	for (unsigned int i = 0; i < toConvert.length(); i++)
	{
		toConvert[i] = tolower(toConvert[i]);
	}

	return toConvert;
}


void debugFillGraph1(Graph graph) {

	graph.link(1, 2, 4);
	cout << "\n\nAdded 1, 2, 4 to graph\n";
	graph.link(1, 3, 1);
	cout << "Added 1, 3, 1 to graph\n";
	graph.link(2, 3, 2);
	cout << "Added 2, 3, 2 to graph\n";
	graph.link(2, 4, 1);
	cout << "Added 2, 4, 1 to graph\n";
	graph.link(3, 4, 1);
	cout << "Added 3, 4, 1 to graph\n";
	graph.link(-1, -1, -1);
	cout << "Added -1, -1, -1 to graph";

}

void debugFillGraph2(Graph graph) {

	graph.link(0, 1, 4);
	graph.link(0, 7, 8);
	graph.link(1, 7, 11);
	graph.link(1, 2, 8);
	graph.link(7, 8, 7);
	graph.link(7, 6, 1);
	graph.link(2, 8, 2);
	graph.link(8, 6, 2);
	graph.link(2, 5, 2);
	graph.link(6, 5, 4);
	graph.link(2, 3, 7);
	graph.link(3, 5, 14);
	graph.link(3, 4, 9);
	graph.link(5, 4, 10);
	graph.link(-1, -1, -1);

}
