/**

Jinxiu Liu
Date: 5/2/2019
Professor: Ioannis Stamos
This is a h file called disjoint_sets.h


Part3:  Everything is similar to what professor gave. Except adding new private variable, vector<vector<int>> c, and only using this variable
		when testing. I also add new public function: int getSize(), to find the size of c.
		unionSets( int root1, int root2 ):   to union sets

**/

#ifndef DISJ_SETS_H
#define DISJ_SETS_H

// DisjSets class
//
// CONSTRUCTION: with int representing initial number of sets
//
// ******************PUBLIC OPERATIONS*********************
// void union( root1, root2 ) --> Merge two sets
// int find( x )              --> Return set containing x
// ******************ERRORS********************************
// No error checking is performed

#include <vector>
using namespace std;

/**
 * Disjoint set class.
 * Use union by rank and path compression.
 * Elements in the set are numbered starting at 0.
 */
class DisjSets
{
  public:
    explicit DisjSets( int numElements );

    int find( int x ) const;
    int find( int x );
	int getSize();
    void unionSets( int root1, int root2 );

  private:
	vector<vector<int>> c;
    vector<int> s;
	
};

#endif
