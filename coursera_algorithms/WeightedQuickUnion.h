#ifndef UF_WEIGHTED_QUICK_UNION_H
#define UF_WEIGHTED_QUICK_UNION_H

#include "QuickUnion.h"

namespace uf
{
	class WeightedQuickUnion: public QuickUnion
	{
	public:
		WeightedQuickUnion(int size);
		virtual ~WeightedQuickUnion();
		WeightedQuickUnion(const WeightedQuickUnion& src): QuickUnion(src) { *this = src; }
		const WeightedQuickUnion& operator = (const WeightedQuickUnion& src);
		virtual void connect(const int first, const int second);
		virtual int root(const int item);
	private:
		int* m_weights;
	};
}

#endif // UF_WEIGHTED_QUICK_UNION_H