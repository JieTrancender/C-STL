/*************************************************************************
	> File Name: string_eager.h
	> Author: JieTrancender
	> Mail: jie-email@jie-trancender.org
	> Created Time: Sun Sep 10 08:32:53 2017
 ************************************************************************/

#ifndef _STRING_EAGER_H
#define _STRING_EAGER_H

#include <cstddef>  //size_t
#include <cstdint>  //uint32_t

namespace muduo
{

class StringEager
{
public:
    typedef char value_type;
    typedef uint32_t size_type;
    typedef int32_t deifference_type;
    typedef value_type& reference;
    typedef const char& const_reference;
    typedef value_type* pointer;
    typedef const char* const_pointer;
    typedef pointer iterator;
    typedef const_pointer const_iterator;

    static const size_type npos = static_cast<size_type>(-1);

    const_pointer c_str() const { return m_start; }
    const_pointer data() const { return m_start; }

    iterator begin() { return m_start; }
    const_iterator begin() const { return m_start; }
    const_iterator cbegin() const { return m_start; }

    iterator end() { return m_start + m_size; }
    const_iterator end() const { return m_start + m_size; }
    const_iterator cend() const { return m_start + m_size; }

    size_type size() const { return m_size; }
    size_type length() const { return m_size; }
    size_type capacity() const { return m_capacity; }

    size_type max_size() const { return 1 << 30; }
    bool empty() const { return m_size == 0; }

    StringEager()
        : m_start(m_kEmpty),
          m_size(0),
          m_capacity(0)
    {}  // no content

    StringEager(const StringEager&);
    StringEager& operator=(const StringEager&);

    StringEager(StringEager&&);
    StringEager& operator=(StringEager&&);

    ~StringEager()
    {
        if (m_start != m_kEmpty)
        {
            delete[] m_start;
        }
    }

    StringEager(const char* str);
    StringEager(const char* str, size_t);
    StringEager& operator=(const char*);

    bool operator<(const StringEager&) const;
    bool operator<(const char*) const;
    bool operator==(const StringEager&) const;
    bool operator==(const char*) const;
    StringEager& operator+=(const StringEager&);
    StringEager& operator+=(const char*);

    void push_back(char c);

    void append(const char* str);
    void append(const char* str, size_t);

    void assign(const char* str, size_t);

    void reserve(size_type);
    void clear() throw();
    void swap(StringEager& rhs) throw();

private:
    struct NoAlloc {};

    void init(const char* str);
    StringEager(char* str, uint32_t, uint32_t, NoAlloc);
    void expandAndAppend(const char* str, size_t len);
    uint32_t nextCapacity(uint32_t) const;
    bool equals(const char* str, size_t len) const;
    bool lessThan(const char* str, size_t len) const;

    char* m_start;
    size_type m_size;
    size_type m_capacity;

    static char m_kEmpty[1];
    static const size_type m_kMinCapacity = 15;
};

template <typename Stream>
Stream& operator<<(Stream&, const StringEager&);

}

#endif
