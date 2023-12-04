#pragma once
#include"bitset.h"
struct BKDRHash
{
	size_t operator()(const string& key)
	{
		// BKDR
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (size_t i = 0; i < key.size(); i++)
		{
			char ch = key[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 5381;
		for (auto ch : key)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

template<size_t N,
	class K=string,
	class HashFunc1= BKDRHash,
	class HashFunc2= APHash,
	class HashFunc3 = DJBHash>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % N;
		size_t hash2 = HashFunc2()(key) % N;
		size_t hash3 = HashFunc3()(key) % N;

		_bs.set(hash1);
		_bs.set(hash2);
		_bs.set(hash3);
	}

	// һ�㲻֧��ɾ����ɾ��һ��ֵ���ܻ�Ӱ������ֵ
	// ��Ҫ֧��ɾ����Ҳ�ǿ��Եģ��ö��λ���һ��ֵ�������ü���
	// �������������ռ����ĵľͱ����
	void Reset(const K& key);

	bool Test(const K& key)
	{
		// �жϲ�������׼ȷ��
		size_t hash1 = HashFunc1()(key) % N;
		if (_bs.test(hash1) == false)
			return false;

		size_t hash2 = HashFunc2()(key) % N;
		if (_bs.test(hash2) == false)
			return false;

		size_t hash3 = HashFunc3()(key) % N;
		if (_bs.test(hash3) == false)
			return false;

		// �������е�
		return true;
	}

private:
	bit::bitset<N> _bs;
};


void TestBF1()
{
	BloomFilter<100> bf;
	bf.Set("��˽�");
	bf.Set("ɳ��");
	bf.Set("�����");
	bf.Set("������");

	cout << bf.Test("��˽�") << endl;
	cout << bf.Test("ɳ��") << endl;
	cout << bf.Test("�����") << endl;
	cout << bf.Test("������") << endl;
	cout << bf.Test("������1") << endl;
	cout << bf.Test("������2") << endl;
	cout << bf.Test("������ ") << endl;
	cout << bf.Test("̫�׾���") << endl;
}

void TestBF2()
{
	srand(time(0));
	const size_t N = 100000;
	BloomFilter<N * 10> bf;

	std::vector<std::string> v1;
	//std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	std::string url = "��˽�";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	// v2��v1�������ַ�������ǰ׺һ���������ǲ�һ��
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string urlstr = url;
		urlstr += std::to_string(9999999 + i);
		v2.push_back(urlstr);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str)) // ����
		{
			++n2;
		}
	}
	cout << "�����ַ���������:" << (double)n2 / (double)N << endl;

	// �������ַ�����
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		//string url = "zhihu.com";
		string url = "�����";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "�������ַ���������:" << (double)n3 / (double)N << endl;
}
