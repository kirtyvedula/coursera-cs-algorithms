#include "QuickFind.h"
#include <string.h>

void uf::QuickFind::connect( const int first, const int second )
{
	if(first == second)
		return;
	int firstGrp = m_id[first];
	int secondGrp = m_id[second];
	if(firstGrp == secondGrp)
		return;
	for (int i = 0; i < m_size; ++i)
	{
		if(m_id[i] == firstGrp)
			m_id[i] = secondGrp;
	}
}

bool uf::QuickFind::connected( const int first, const int second ) const
{
	return m_id[first] == m_id[second];
}
