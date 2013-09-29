#include "QuickUnion.h"
#include <iostream>
#include <vector>
#include <algorithm>

void uf::QuickUnion::connect( const int first, const int second )
{
	if(first == second)
		return;
	m_id[root(second)] = root(first);
}

bool uf::QuickUnion::connected( const int first, const int second )
{
	return root(first) == root(second);
}

int uf::QuickUnion::root( const int item )
{
	int r = item;
	while(r != m_id[r])
	{
		r = m_id[r];
	}
	return r;
}

void uf::QuickUnion::print() const
{
	std::cout<< "\n--------------------------------\n";
	for(int i = 0; i < m_size; ++i)
	{
		std::cout << i << " -> ";
		int r = i;
		while(r != m_id[r])
		{
			std::cout << r << " -> ";
			r = m_id[r];
		}
		std::cout << r << std::endl;
	}
	std::cout<< "\n--------------------------------\n";
}

int uf::QuickUnion::maxPathLen() const
{
	int maxLen = 1;
	for(int  i = 0; i < m_size; ++i)
	{
		int len = 1;
		int r = i;
		while(r != m_id[r])
		{
			++len;
			r = m_id[r];
		}
		if(len > maxLen)
			maxLen = len;
	}

	return maxLen;
}
