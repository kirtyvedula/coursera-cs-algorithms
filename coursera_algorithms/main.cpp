#include "QuickFind.h"
#include "QuickUnion.h"
#include "WeightedQuickUnion.h"
#include <assert.h>
#include <time.h>
#include <math.h>
#include <iostream>

void setup(uf::UnionFind* alg);
void setupRand(uf::UnionFind* alg, int count, int maxSize);

int main()
{
	srand(time(NULL));
	double sum = 0.;
	int testsCount = 10000;
	int itemsCount = 100;
	for(int i = 0; i < testsCount; ++i)
	{
		uf::WeightedQuickUnion wqu(itemsCount);
		uf::QuickUnion qu(itemsCount);
		setupRand(&wqu, itemsCount * itemsCount + 1, itemsCount);
		setupRand(&qu, itemsCount * itemsCount + 1, itemsCount);
		sum += double(qu.maxPathLen()) / double(wqu.maxPathLen());
	}

	std::cout << "Average: " << sum / ((double) testsCount) << std::endl;
	system("pause");
	return 0;
}

void setup(uf::UnionFind* alg)
{
	alg->connect(4, 3);
	alg->connect(3, 8);
	alg->connect(6, 5);
	alg->connect(9, 4);
	alg->connect(2, 1);
	alg->connect(5, 0);
	alg->connect(7, 2);
	alg->connect(6, 1);
	alg->connect(7, 3);
}

void setupRand( uf::UnionFind* alg, int count, int maxSize )
{
	int combinationsCount = (maxSize - 1) * (maxSize - 2);
	count = count > combinationsCount ? combinationsCount : count;
	for (int i =0; i < count; ++i)
	{
		int f = rand() % maxSize;
		int s = rand() % maxSize;
		if(f == s || alg->connected(s, f))
			continue;
		alg->connect(f, s);
	}
}
