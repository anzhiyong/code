#pragma once

#include"RBTree.h"

namespace an
{
	template <class K, class T>
	class set
	{
	public:
		struct MapKeyOfT
		{
			const T& operator()(const T& kv)
			{
				return kv.first;
			}
		};
	private:

		RBTree<K, pair<K,T> MapKeyOfT>* Node;
	};
}