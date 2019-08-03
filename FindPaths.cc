/**

Jinxiu Liu
Date: 5/2/2019
Professor: Ioannis Stamos
This is a cc file called FindPaths.cc


Part2:  This program use Dijkstra’s Algorithm to find the shortest 
		paths from a given starting vertex to all vertices in the graph file. 
		The program output all paths in the form: 
			Destination: Start, V1, V2, … , Destination, Total cost: X 

		The program print out the paths to every destination.

**/

#include "binary_heap.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Vertex
{
	vector<int> adj;
	vector<float> w;
	float distance;
	bool known;
	int previous;

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
float c(Vertex a, int b)
{
	return a.w[b];
}

Vertex getV(int a, vector<Vertex> v)
{
	return v[a-1];
}

string findAnswer(int start, int i, vector<Vertex> v)
{
	int finalA = i;
	string an = "";
	an=an+ to_string(finalA)+", ";
	
	while (finalA != start)
	{
		finalA = v[finalA - 1].previous;
		an+=to_string(finalA)+ ", ";
	}
	return an;
}
string reverseS(string str)
{
	string an = "";
	for (int i = str.size() - 3; i >= 0; i--)
		an += str[i];
	return an;
}
bool equal(Vertex a, Vertex b)
{
	return a.adj == b.adj;
}
int getIntV(Vertex anv, vector<Vertex> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (equal(anv, v[i]))
			return i + 1;
	}
	return -1;
}
void findP( int start,  vector<Vertex> v)
{
	BinaryHeap<Vertex> h;
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i].distance = 100000;
		v[i].known =false;
	}
	v[start-1].distance = 0;
	h.insert(v[start - 1]);
	while (true)
	{
		if (h.isEmpty())
			break;
		
		Vertex anv = h.findMin();
		h.deleteMin();
		anv.known = true;
		
		for (size_t i = 0; i < anv.adj.size(); i++)
		{
			if (!getV(anv.adj[i],v).known)
			{
				if (anv.distance + c(anv, i) < getV(anv.adj[i],v).distance)
				{
					v[anv.adj[i]-1].distance = anv.distance + c(anv, i);
					h.insert(v[anv.adj[i]-1]);
					v[anv.adj[i] - 1].previous = getIntV(anv, v);
				}
			}
		}
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		cout <<  i+1 << ": ";
		string an =findAnswer(start, i+1, v);
		string reAn = reverseS(an);
		cout << std::setprecision(1);
		cout <<std::fixed;
		cout<< reAn<<", Cost: " << v[i].distance <<"."<< endl;
	}

	
}

//this function will first create the graph and then go to findP() function to do the task
void findPaths(const string &g, const string &startV)
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

	int startVN = stoi(startV);
	findP( startVN,useV);
}

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
		return 0;
	}
	const string graph(argv[1]);
	const string startV(argv[2]);

	findPaths(graph, startV);
	return 0;
}