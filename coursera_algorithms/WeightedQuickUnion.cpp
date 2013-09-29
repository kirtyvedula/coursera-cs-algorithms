#include "WeightedQuickUnion.h"
#include <string.h>

uf::WeightedQuickUnion::WeightedQuickUnion( int size )
	: QuickUnion(size)
{
	m_weights = new int[size];
	for(int i = 0; i < size; ++i)
		m_weights[i] = 1;
}

uf::WeightedQuickUnion::~WeightedQuickUnion()
{
	if(m_weights)
		delete m_weights;
}

const uf::WeightedQuickUnion& uf::WeightedQuickUnion::operator=( const WeightedQuickUnion& src )
{
	if(m_weights != NULL)
		delete m_weights;
	m_size = src.m_size;
	m_weights = new int[m_size];
	memcpy(m_weights, src.m_weights, sizeof(int) * src.m_size);
	return *this;
}

void uf::WeightedQuickUnion::connect( const int first, const int second )
{
	if(m_weights[first] < m_weights[second])
	{
		m_weights[root(second)] += m_weights[root(first)];
		QuickUnion::connect(first, second);
	}
	else
	{
		m_weights[root(first)] += m_weights[root(second)];
		QuickUnion::connect(second, first);
	}
}

int uf::WeightedQuickUnion::root( const int item )
{
	int r = item;
	while(r != m_id[r])
	{
		m_id[r] = m_id[m_id[r]];
		r = m_id[r];
	}
	return r;
}
