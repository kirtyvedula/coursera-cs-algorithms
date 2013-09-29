#ifndef UF_QUICK_FIND_H
#define UF_QUICK_FIND_H

#include "UnionFind.h"

namespace uf
{
	/*	This algorithm checks for connectivity of 2 items.
		Implementation requires an array with's as data structure
	*/
	class QuickFind: public UnionFind
	{
	public:
		QuickFind(int size) : UnionFind(size) {}

		/* Cost: N, because in worst case we need to change the id's of N-1 items
					so characteristic for this algorithms is linear. */
		virtual void connect(const int first, const int second);
		
		/* Cost: 1 because we just check for equality id's of items */ 
		virtual bool connected(const int first, const int second) const;
		virtual ~QuickFind() {}
	};
}

#endif // UF_QUICK_FIND_H