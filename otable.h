#ifndef OTABLE_H
#define OTABLE_H
#include <cstdlib>

enum status_type
{
    NEVER_USED, IN_USE, PREVIOUSLY_USED
};

template <class T>
struct table_entry
{
    table_entry(const T & init_value = T(),
                status_type init_status = NEVER_USED)
    {
        value = init_value;
        status = init_status;
    }

    T value;
    status_type status;
};

template <class T, std::size_t TABLE_SIZE, std::size_t myhash(const T &)>
class otable
{
public:
    // pre: none
    // post: creates an empty otable
    otable()
    {
        for (std::size_t i = 0; i < TABLE_SIZE; ++i)
            _data[i] = table_entry<T>();

        _size = 0;
    }

    // pre: none
    // post: returns the size of this otable
    std::size_t size() const
    {
        return _size;
    }

    // pre: none
    // post: returns true iff this otable is empty
    bool empty() const
    {
        return (_size == 0);
    }

    // pre: none
    // post: returns true iff ths otable is full
    bool full() const
    {
        return (_size == TABLE_SIZE);
    }


    // pre: none
    // post: returns true if target is in this otable
    bool find(const T & target) const
    {
        std::size_t pos = myhash(T) % TABLE_SIZE;
        std::size_t jump = 1;

        for (std::size_t i  = 0; i < TABLE_SIZE; ++i)
        {
            if (_data[pos].value == target && _data[pos].status == IN_USE)
                return true;

            if (_data[pos].status == NEVER_USED)
                return false;
            pos = (pos + jump) % TABLE_SIZE;
        }
        return false;
    }

    // pre: !full()
    // post: a copy of entry  has been added to this otable
    void insert(const T & entry)
    {
        assert(!full());

        std::size_t pos = myhash(entry) % TABLE_SIZE;
        std::size_t jump(1);

        for (std::size_t i = 0; i < TABLE_SIZE; ++i)
        {
            if (_data[pos].status != IN_USE)
            {
                _data[pos].value = entry;
                _data[pos].status = IN_USE;
                ++_size;
                return;
            }
            pos = (pos+jump) % TABLE_SIZE;
        }
    }

    // pre: none
    // post: entry has been removed from this otable, if it is there
    void erase(const T & entry)
    {
        std::size_t pos = myhash(entry)% TABLE_SIZE;
        std::size_t jump(1);

        for (std::size_t i = 0; i < TABLE_SIZE; ++i)
        {
            if (_data[pos].status == NEVER_USED)
                return;

            if (_data[pos].status == IN_USE && _data[pos].value == entry)
            {
                _data[pos].status = PREVIOUSLY_USED;
                --_size;
                return
            }
            pos = (pos+jump) % TABLE_SIZE;
        }
    }

private:
    table_entry<T> _data[TABLE_SIZE];
    std::size_t _size;

    // invariants:
    // open-address hash table
    // _size is the number of elements stored in this otable
};

#endif // OTABLE_H
