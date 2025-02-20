#pragma once

namespace bit
{
	template<class K,class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT,Hash>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT, Hash>::const_iterator const_iterator;
		/*iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}*/

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		pair<const_iterator, bool> insert(const K& key)
		{
			auto ret = _ht.Insert(key);
			return pair<const_iterator, bool>(const_iterator(ret.first._node, ret.first._pht, ret.first._hashi), ret.second);
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}
	private:
		hash_bucket::HashTable<K, K, SetKeyOfT,Hash> _ht;
	};

	void test_set()
	{
		unordered_set<int> us;
		us.insert(5);
		us.insert(15);
		us.insert(52);
		us.insert(3);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			//*it += 5;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;

	}
}
