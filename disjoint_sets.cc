/**

Jinxiu Liu
Date: 5/2/2019
Professor: Ioannis Stamos
This is a cc file called disjoint_sets.cc


Part3:  this is implementation file for disjoint_sets.h. additionally,  helper functions:
		getRoot(int root, vector<vector<int>> c) and combine(int findR1, int findR2, vector<vector<int>>& a)
		are added to help unionSets( int root1, int root2 )

**/

#include "disjoint_sets.h"
#include <iostream>


/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets( int numElements ) 
{
	for (int i = 1; i <= numElements; i++)
	{
		vector<int> a{i};
		c.push_back(a);
	}
}
int getRoot(int root, vector<vector<int>> c)
{
	for (size_t i = 0; i < c.size(); i++)
	{
		for (size_t j = 0; j < c[i].size(); j++)
		{
			if (c[i][j] == root)
				return i;
		}
	}
	return -1;
}
void combine(int findR1, int findR2, vector<vector<int>>& a)
{
	for (size_t i = 0; i < a[findR2].size(); i++)
		a[findR1].push_back(a[findR2][i]);
	a.erase(a.begin() + findR2);
}
/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::unionSets( int root1, int root2 )
{
	int findR1 = getRoot(root1,c);
	int findR2 = getRoot(root2,c);
	if (findR1 == findR2)
	{}
	else if(findR1 < findR2)
		combine(findR1, findR2, c);
	else 
		combine(findR2, findR1, c);

    
}

int DisjSets::getSize()
{
	return c.size();
}
/**
 * Perform a find.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find( int x ) const
{
    if( s[ x ] < 0 )
        return x;
    else
        return find( s[ x ] );
}


/**
 * Perform a find with path compression.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find( int x )
{
    if( s[ x ] < 0 )
        return x;
    else
        return s[ x ] = find( s[ x ] );
}


