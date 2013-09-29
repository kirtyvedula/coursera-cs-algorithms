#ifndef UF_UNION_FIND_H
#define UF_UNION_FIND_H

#include <stdlib.h>

namespace uf
{
	class UnionFind
	{
	public:
		UnionFind(int size);
		virtual ~UnionFind() { if(m_id != NULL) delete m_id; }
		UnionFind(const UnionFind& src) : m_id(NULL) { *this = src; }
		const UnionFind& operator = (const UnionFind& src);
		virtual void connect(const int first, const int second) = 0;
		virtual bool connected(const int first, const int second) = 0;
	protected:
		int* m_id;
		int  m_size;
	};
}

#endif // UF_UNION_FIND_H