#pragma once

namespace bit
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize((N >> 5) + 1, 0);
		}

		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] &= ~(1 << j);
		}

		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			return _bits[i] & (1 << j);
		}

	private:
		vector<int> _bits;
	};

	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x)
		{
			//00->01
			//01->10
			//10->不变 代表出现了两次及以上
			if (_bs1.test(x) == false && _bs2.test(x) == false)
			{
				_bs2.set(x);
			}
			else if (_bs1.test(x) == false && _bs2.test(x) ==true )
			{
				_bs1.set(x);
				_bs2.reset(x);
			}
			else if (_bs1.test(x) == true && _bs2.test(x) == false)
			{
				_bs1.set(x);
				_bs2.set(x);
			}

		}

		void PrintOnce()
		{
			for (size_t i = 0; i < N; i++)
			{
				if (_bs1.test(i) == false && _bs2.test(i) == true)
				{
					cout << i << endl;
				}
				
			}
			cout << endl;
		}

	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};

}
