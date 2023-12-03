#pragma once
#include<vector>

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		//cout << key << ":" << hash << endl;
		return hash;
	}
};

namespace open_address
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _s;          //状态
	};

	template<class K, class V,class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first)) return false;

			// 负载因子0.7就扩容
			if (_n * 10 / _tables.size() == 7)
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V,Hash> newHT;
				newHT._tables.resize(newSize);
				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._s == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newHT._tables);
			}
			Hash hf;
			size_t hashi = hf(kv.first) % _tables.size();
			while (_tables[hashi]._s == EXIST)
			{
				hashi++;

				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._s = EXIST;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			while (_tables[hashi]._s !=EMPTY)
			{
				if (_tables[hashi]._s==EXIST&&_tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				hashi++;

				hashi %= _tables.size();
			}

			return NULL;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret) 
			{
				ret->_s = DELETE;
				_n--;
				return true;
			}
			else
			{
				return false;
			}
		}

		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._s == EXIST)
				{
					
					//printf("[%d]->%d\n", i, _tables[i]._kv.first);
					cout << "[" << i << "]" << "->" << _tables[i]._kv.first << ":" << _tables[i]._kv.second << endl;
				}
				else if (_tables[i]._s == EMPTY)
				{
					cout << "[" << i << "]" << "->" << endl;
				}
				else
				{
					cout << "[" << i << "]" << "->D" << endl;
				}
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; // 存储的关键字的个数
	};

	void TestHT1()
	{
		HashTable<int, int> ht;
		int a[] = { 4,14,24,34,5,7,1 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(-3, -3));
		ht.Print();
		cout << endl;
		ht.Erase(3);
		ht.Print();
		cout << endl;

		if (ht.Find(3))
		{
			cout << "3存在" << endl;
		}
		else
		{
			cout << "3不存在" << endl;
		}

		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
		ht.Print();
		cout << endl;
	}

	void TestHT2()
	{
		string arr[] = { "香蕉","甜瓜","苹果","西瓜" ,"苹果",
			"西瓜", "苹果", "苹果","西瓜" , "苹果" , "香蕉" ,"甜瓜" ,"西瓜" };
		HashTable<string, int> ht;

		for (auto& e : arr)
		{
			HashData<string, int>* ret = ht.Find(e);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}
		}

		ht.Print();

		ht.Insert(make_pair("sort", 1));
		ht.Insert(make_pair("apple", 1));

		ht.Insert(make_pair("abc", 1));
		ht.Insert(make_pair("acb", 1));
		ht.Insert(make_pair("aad", 1));
		ht.Print();
	}

}


namespace hash_bucket
{
	 template<class T>
	 struct HashNode
	 {
		 HashNode* _next;
		 T _data;

		 HashNode(const T& data)
			 :_data(data)
			 ,_next(nullptr)
		 {}
	 };

	 //前置声明
	 template<class K, class T,class KeyOfT, class Hash>
	 class HashTable;

	 template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	 struct __HTIterator
	 {
		 typedef HashNode<T> Node;
		 typedef __HTIterator<K, T,Ref,Ptr, KeyOfT, Hash>Self;
		 Node* _node;
		 const HashTable<K, T, KeyOfT, Hash>* _pht;
		 size_t _hashi;

		 __HTIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht,size_t hashi)
			 :_node(node)
			 ,_pht(pht)
			 ,_hashi(hashi)
		 {}

		 __HTIterator(Node* node, const HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
			 :_node(node)
			 , _pht(pht)
			 , _hashi(hashi)
		 {}

		 Self& operator++()
		 {
			 if (_node->_next)
			 {
				 //当前桶还有节点，走到下一个节点
				 _node = _node->_next;
			 }
			 else
			 {
				 //当前桶已经走完了，下一个桶
				 ++_hashi;
				 while (_hashi < _pht->_tables.size())
				 {
					 if (_pht->_tables[_hashi])
					 {
						 _node = _pht->_tables[_hashi];
						 break;
					 }
						 ++_hashi;
					 
				 }

				 if (_hashi == _pht->_tables.size())
				 {
					 _node = nullptr;
				 }
			 }

			 return *this;
		 }

		 Ref operator*()
		 {
			 return _node->_data; 
		 }

		 Ptr operator->()
		 {
			 return &_node->_data;
		 }

		 bool operator!=(const Self& s)
		 {
			 return _node != s._node;
		 }
	 };

	 template<class K,class T,class KeyOfT,class Hash>
	 class HashTable
	 {
		 typedef HashNode<T> Node;
		 template<class K, class T,class Ref,class Ptr, class KeyOfT, class Hash>
		 friend struct __HTIterator;
	 public:
		 typedef __HTIterator<K, T,T&,T*, KeyOfT, Hash> iterator;
		 typedef __HTIterator<K, T,const T&,const T*, KeyOfT, Hash> const_iterator;

		 iterator begin()
		 {
			 for (size_t i = 0; i < _tables.size(); i++)
			 {
				 if (_tables[i])
				 {
					 return iterator(_tables[i],this, i);
				 }
			 }

			 return end();
		 }

		 iterator end()
		 {
			 return iterator(nullptr, this, -1);
		 }

		 const_iterator begin()const
		 {
			 for (size_t i = 0; i < _tables.size(); i++)
			 {
				 if (_tables[i])
				 {
					 return const_iterator(_tables[i], this, i);
				 }
			 }

			 return end();
		 }

		 const_iterator end()const
		 {
			 return const_iterator(nullptr, this, -1);
		 }

	 public:
		 HashTable()
		 {
			 _tables.resize(10);
		 }

		 ~HashTable()
		 {
			 for (size_t i = 0; i < _tables.size(); i++)
			 {
				 Node* cur = _tables[i];
				 while (cur)
				 {
					 Node* next = cur->_next;
					 delete cur;
					 cur = next;
				 }
				_tables[i] = nullptr;
			 }
		 }

		 pair<iterator, bool> Insert(const T& data)
		 {
			 Hash hf;
			 KeyOfT kot;

			 iterator it = Find(kot(data));
			 if (it != end())
				 return make_pair(it, false);

			 // 负载因子最大到1
			 if (_n == _tables.size())
			 {
				 vector<Node*> newTables;
				 newTables.resize(_tables.size() * 2, nullptr);
				 // 遍历旧表
				 for (size_t i = 0; i < _tables.size(); i++)
				 {
					 Node* cur = _tables[i];
					 while (cur)
					 {
						 Node* next = cur->_next;

						 // 挪动到映射的新表
						 size_t hashi = hf(kot(cur->_data)) % newTables.size();
						 cur->_next = newTables[hashi];
						 newTables[hashi] = cur;

						 cur = next;
					 }

					 _tables[i] = nullptr;
				 }

				 _tables.swap(newTables);
			 }

			 size_t hashi = hf(kot(data)) % _tables.size();
			 Node* newnode = new Node(data);

			 // 头插
			 newnode->_next = _tables[hashi];
			 _tables[hashi] = newnode;
			 ++_n;

			 return make_pair(iterator(newnode, this, hashi), true);
		 }

		 iterator Find(const K& key)
		 {
			 Hash hf;
			 KeyOfT kot;

			 size_t hashi = hf(key) % _tables.size();
			 Node* cur = _tables[hashi];
			 while (cur)
			 {
				 if (kot(cur->_data) == key)
				 {
					 return iterator(cur, this, hashi);
				 }

				 cur = cur->_next;
			 }

			 return end();
		 }

		 bool Erase(const K& key)
		 {
			 Hash hf;
			 KeyOfT kot;

			 size_t hashi = hf(key) % _tables.size();
			 Node* prev = nullptr;
			 Node* cur = _tables[hashi];
			 while (cur)
			 {
				 if (kot(cur->_data) == key)
				 {
					 if (prev == nullptr)
					 {
						 _tables[hashi] = cur->_next;
					 }
					 else
					 {
						 prev->_next = cur->_next;
					 }
					 delete cur;

					 return true;
				 }

				 prev = cur;
				 cur = cur->_next;
			 }

			 return false;
		 }


	 private:
		 vector<Node*> _tables;
		 size_t _n = 0;
	 };

}

	