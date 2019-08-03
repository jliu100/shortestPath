/**

Jinxiu Liu
Date: 5/2/2019
Professor: Ioannis Stamos
This is a cc file called CreateGraphAndTest.cc


Part1:  Read a directed graph from a text file and Represent a graph using a vector and struct. In order to test the implementation I also 
		read a second text file (let us call it AdjacencyQueries.txt) that will contain a set of pair of vertices:
		1. First create the graph by reading it from text file Graph1.txt. It will then open the file 
		   AdjacenyQueries.txt and for each pair of vertices in it, 
		2. cout whether the vertices are adjacent or not, and if they are you will cout the weight of the edge that connects them.

**/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//create struct called Vertex that contains 2 vectors.
// the first vector will store the vertices that a Vertex is directed to, in int form
//teh second vector will store the weight that exist between 2 vertices when they connect
struct Vertex
{
	vector<int> adj;
	vector<float> w;
};


string getNextStr(string &line)
{
	string newS;
	int count = 0;
	int lineSize = line.size();
	while (count < lineSize && !isspace(line[count]))
	{
		newS += line[count];
		count++;
	}   
	if (count == lineSize) 
		line = ""; 
	else
		line = line.substr(count + 1);
	
	return newS;
}
bool find(Vertex v, int x, float& y)
{
	for (size_t i = 0; i < v.adj.size(); i++)
	{
		if (v.adj[i] == x)
		{
			y = v.w[i];
			return true;
		}
	}
	return false;
}


void CreateGraphAndT(const string &g, const string &aQ)
{

	ifstream graph;
	int numV;
	string line;
	graph.open(g);
	graph >> numV;
	int count = 0;
	
	vector<Vertex> useV;
	getline(graph, line); 
	
	while (getline(graph, line) && line != "")
	{
		string mainVex = getNextStr(line);
		Vertex newV;
		while (!line.empty())
		{
			string vStr = getNextStr(line);
			newV.adj.push_back(stoi(vStr));
			string vfloat = getNextStr(line);
			newV.w.push_back(stof(vfloat));
		}	
		useV.push_back(newV);
		count++;	
	}
	
	graph.close();

	ifstream aQo;
	int vex;
	int anotherVex;
	aQo.open(aQ);
	while (aQo >> vex)
	{
		aQo >> anotherVex;
		float weight= 0.0;
		if (find(useV[vex-1], anotherVex,weight))
			cout << vex << " " << anotherVex << ": Connected, weight of edge is " << weight << endl;
		else
			cout << vex << " " << anotherVex << ": Not Connected" << endl;
	}
	
}

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
		return 0;
	}
	const string graph(argv[1]);
	const string adjQ(argv[2]);
	
	CreateGraphAndT(graph, adjQ);
	return 0;
}