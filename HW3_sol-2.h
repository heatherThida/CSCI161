#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cassert>

template <class T>
class priority_queue
{
	public:
		// pre: none
		// post: creates an empty priority queue
		priority_queue()
		{
			_data = new T[1];
			_capacity = 1;
			_size = 0;
		}

		// pre: none
		// post: returns dynamically allocated memory to OS
		~priority_queue()
		{
			delete [] _data;
		}

		// pre: none
		// post: returns true iff this priority_queue is empty
		bool empty() const
		{
			return (_size == 0);
		}

		void reserve(std::size_t new_capacity)
		{
			if (new_capacity > _capacity)
			{
				T * new_data = new T[new_capacity];
				std::copy(_data, _data+_size, new_data);
				delete [] _data;
				_data = new_data;
				_capacity = new_capacity;
			}
		}
		

		// pre: this priority_queue is not empty
		// post: returns a reference to the front (largest) element
		T & front() 
		{
			assert(!empty());
			return _data[0];
		}

		// const version
		T & front() const
		{
			assert(!empty());
			return _data[0];
		}

		// pre: this priority queue is not empty
		// post: the front element of this priority_queue has been removed
		void pop()
		{
			assert(!empty());
			_data[0] = _data[--_size];

			std::size_t r = 0;
			while (2*r + 1 < _size)
			{
				std::size_t lc = 2*r+1;
				if (lc+1 < _size && _data[lc] < _data[lc+1])
					++lc;
				if (!(_data[r] < _data[lc]))
					break;
				std::swap(_data[r], _data[lc]);
				r = lc;
			}
		}

		// pre: none
		// post: a copy of entry has been added to this priority_queue
		void push(const T & entry)
		{
			if (_size == _capacity)
				reserve(2*_capacity);
			_data[_size++] = entry;

			std::size_t r = _size - 1;
			while (r > 0 &&_data[r] > _data[(r-1)/2])
			{
				std::swap(_data[r], _data[(r-1)/2]);
				r = (r-1)/2;
			}
		}


	private:
		T *_data;
		std::size_t _capacity;
		std::size_t _size;

		// invariants:
		// _data is a dynamic array of physical size _capacity
		// _data[0.._size-1] hold the elements of this priority as a max heap
};
