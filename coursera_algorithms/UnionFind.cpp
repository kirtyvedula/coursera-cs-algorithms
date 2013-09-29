#include "UnionFind.h"
#include <string.h>

uf::UnionFind::UnionFind( int size )
{
	m_size = size;
	m_id = new int[m_size];
	for(int i = 0; i < m_size; ++i)
		m_id[i] =i;
}

const uf::UnionFind& uf::UnionFind::operator=( const UnionFind& src )
{
	if(m_id != NULL)
		delete m_id;
	m_size = src.m_size;
	m_id = new int[m_size];
	memcpy(m_id, src.m_id, m_size * sizeof(int));
	return *this;
}
