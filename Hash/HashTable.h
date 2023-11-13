#pragma once

namespace myhash {
	
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
		Status _s;
	};

	template<class K, class V>
	class HashTable
	{
	public:

		bool Insert(const pair<K, V>& kv)
		{

			//��������0.7������
			if (_n * 10 / _tables.size() == 7)
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);
				//�����ɱ�
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._s == EXIST)
					{
						newHT.Insert(_tables._kv);
					}
				}

				//�����ɱ���±�
			}
			size_t hashi = kv.first % _tables.size();
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

	private:
		vector<HashData> _tables;
		//��������
		size_t _n = 0;
	};
}

