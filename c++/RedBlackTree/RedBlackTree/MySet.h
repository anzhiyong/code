#pragma once

#include"RBTree.h"

namespace an
{
	
	template <class K>
	class set
	{
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	private:

		RBTree<K, K, SetKeyOfT>* Node;
	};
}

