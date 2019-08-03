/**

Jinxiu Liu
Date: 5/2/2019
Professor: Ioannis Stamos
This is a cc file called TestRandomGraph.cc


Part3:  This program will generate a random undirected graph of N vertices. In order to achieve that, 
		we will use pairs of random numbers (i1, i2) with 1 <= i1 <= N and 1 <= i2 <= N
		Then, add the edge (i1, i2) to the graph. Keep also the sets of connected vertices. (using the Union-Find data structure by including disjoint_sets)

		At the end,  the following information will display: 
		a) The number of edges that your final graph contains.
		b) The smallest out-degree for a vertex. 
		c) The largest out-degree for a vertex.
		d) The average out-degree for a vertex. 
 
**/

#include "disjoint_sets.cc"
#include "binary_heap.h"
#include <cstdlib> 
#include <ctime> 
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std; 
struct Vertex
{
	vector<int> adj;
	vector<float> w;
	float distance;
	bool known;
	int previous;
	int outD;
};

struct Edge
{
	int x;
	int y;
	float w;
};

void createVector(vector<Vertex> &verx, int max)
{
	Vertex a;
	for (int i = 0; i < max; i++)
		verx.push_back(a);
}

bool repeate(int a, int b, vector<Vertex> &verx)
{
	for (size_t i = 0; i < verx[a - 1].adj.size(); i++)
	{
		if (verx[a - 1].adj[i] == b)
			return true;
	}
	return false;
}

void getE(Edge e)
{
	cout << e.x << " " << e.y << ", ";
}

void TestRandomG(const string &g)
{
	int max = stoi(g);
	DisjSets ds(max);

	vector<Vertex> verx;
	createVector(verx, max);

	srand(time(0)); //use current time as seed for random generator
	const int maximum_value = max;

	vector<Edge> ed;
	Edge e;

	vector<int> vA;

	while (ds.getSize()> 1)
	{
		int random_variableA = rand() % maximum_value + 1;
		int random_variableB = rand() % maximum_value + 1;

		if (random_variableA != random_variableB && repeate(random_variableA, random_variableB, verx) == false)
		{

			e = { random_variableA ,random_variableB ,1 };
			ed.push_back(e);
			//getE(e);
			//cout << endl;
			ds.unionSets(random_variableA, random_variableB);
			verx[random_variableA - 1].adj.push_back(random_variableB);
			verx[random_variableA - 1].w.push_back(1);
			verx[random_variableA - 1].outD = verx[random_variableA - 1].adj.size();

			verx[random_variableB - 1].adj.push_back(random_variableA);
			verx[random_variableB - 1].w.push_back(1);
			verx[random_variableB - 1].outD = verx[random_variableB - 1].adj.size();
		}
	}
	
	cout <<"The number of edges that final graph contains: "<< ed.size() << endl;
	int smallestO = 1000, largeO = 0,mean = 0;
	for (size_t i = 0; i < verx.size(); i++)
	{
		if (verx[i].outD < smallestO)
			smallestO = verx[i].outD;
		if (verx[i].outD > largeO)
			largeO = verx[i].outD;
		mean += verx[i].outD;
	}
	cout << "The smallest out-degree for a vertex is: " << smallestO << endl;
	cout << "The largest out-degree for a vertex is: " << largeO << endl;
	cout << "The average out-degree for a vertex is: " << mean / float(verx.size()) << endl;
	
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
		return 0;
	}
	const string numV(argv[1]);

	TestRandomG(numV);
	
	return 0;
}

