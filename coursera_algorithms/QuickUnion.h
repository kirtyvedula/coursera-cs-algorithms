#ifndef UF_QUICK_UNION_H
#define UF_QUICK_UNION_H

#include "UnionFind.h"

namespace uf
{
	class QuickUnion: public UnionFind
	{
	public:
		QuickUnion(int size) : UnionFind(size) {}
		virtual void connect(const int first, const int second);
		virtual bool connected(const int first, const int second);
		virtual ~QuickUnion() {}
		void print() const;
		int maxPathLen() const;
		virtual int root(const int item);
	};
}

#endif // UF_QUICK_UNION_H