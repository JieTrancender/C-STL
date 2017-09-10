/*************************************************************************
	> File Name: string_eager.cpp
	> Author: JieTrancender
	> Mail: jie-email@jie-trancender.org
	> Created Time: Sun Sep 10 08:57:21 2017
 ************************************************************************/

#include "string_eager.h"

#include <cassert>
#include <cstring>
#include <algorithm>

char muduo::StringEager::m_kEmpty[] = "";
const uint32_t muduo::StringEager::m_kMinCapacity;

using namespace muduo;

StringEager::StringEager(const StringEager& rhs)
    : m_start(m_kEmpty),
      m_size(rhs.m_size),
      m_capacity(0)
{
    init(rhs.m_start);
}

StringEager& StringEager::operator=(const StringEager& rhs)
{
    assign(rhs.m_start, rhs.m_size);
    return *this;
}

StringEager::StringEager(StringEager&& rhs)
    : m_start(rhs.m_start),
      m_size(rhs.m_size),
      m_capacity(rhs.m_capacity)
{
    rhs.m_start = nullptr;
}

StringEager& StringEager::operator=(StringEager&& rhs)
{
    swap(rhs);
    return *this;
}

StringEager::StringEager(const char* str)
    : m_start(m_kEmpty),
      m_size(::strlen(str)),
      m_capacity(0)
{
    init(str);
}

StringEager::StringEager(const char* str, size_t len)
    : m_start(m_kEmpty),
      m_size(len),
      m_capacity(0)
{
    init(str);
}

StringEager& StringEager::operator=(const char* str)
{
    assign(str, ::strlen(str));
    return *this;
}

StringEager::StringEager(char* str, uint32_t size, uint32_t capacity, NoAlloc)
    : m_start(str),
      m_size(size),
      m_capacity(capacity)
{}  // no content

void StringEager::init(const char* str)
{
    if (m_size > 0)
    {
        m_capacity = std::max(m_size, m_kMinCapacity);
        m_start = new char[m_capacity + 1];
        ::memcpy(m_start, str, m_size + 1);
    }
}

bool StringEager::operator<(const StringEager& rhs) const
{
    return lessThan(rhs.m_start, rhs.m_size);
}

bool StringEager::operator<(const char* str) const
{
    return lessThan(str, ::strlen(str));
}

bool StringEager::operator==(const StringEager& rhs) const
{
    return this == &rhs || equals(rhs.m_start, rhs.m_size);
}

bool StringEager::operator==(const char* str) const
{
    return equals(str, ::strlen(str));
}

void StringEager::reserve(size_type len)
{
    if (len > m_capacity)
    {
        const uint32_t newCapacity = nextCapacity(len);
        char* newStart = new char[newCapacity + 1];
        ::memcpy(newStart, m_start, m_size);
        newStart[m_size] = '\0';
        StringEager tmp(newStart, m_size, newCapacity, NoAlloc());
        swap(tmp);
    }
}

void StringEager::clear() throw()
{
    m_size = 0;
    m_start[m_size] = '\0';
}

void StringEager::swap(StringEager& rhs) throw()
{
    std::swap(m_start, rhs.m_start);
    std::swap(m_size, rhs.m_size);
    std::swap(m_capacity, rhs.m_capacity);
}

void StringEager::assign(const char* str, size_t len)
{
    if (m_capacity >= len)
    {
        ::memmove(m_start, str, len);
        m_size = len;
        m_start[m_size] = '\0';
    }
    else
    {
        clear();
        expandAndAppend(str, len);
    }
}

void StringEager::push_back(char c)
{
    if (m_capacity >= m_size + 1)
    {
        m_start[m_size] = c;
        m_start[++m_size] = '\0';
    }
    else
    {
        expandAndAppend(&c, 1);
    }
}

void StringEager::append(const char* str)
{
    append(str, ::strlen(str));
}

void StringEager::append(const char* str, size_t len)
{
    if (m_capacity >= m_size + len)
    {
        ::memcpy(m_start + m_size, str, len);
        m_size += len;
        m_start[m_size] = '\0';
    }
    else
    {
        expandAndAppend(str, len);
    }
}

void StringEager::expandAndAppend(const char* str, size_t len)
{
    const uint32_t newSize = m_size + len;
    const uint32_t newCapacity = nextCapacity(newSize);
    char *newStart = new char[newCapacity + 1];
    ::memcpy(newStart, m_start, m_size);
    ::memcpy(newStart + m_size, str, len);
    newStart[newSize] = '\0';
    StringEager tmp(newStart, newSize, newCapacity, NoAlloc());
    swap(tmp);
}

uint32_t StringEager::nextCapacity(uint32_t newSize) const
{
    uint32_t newCapacity = std::max(2 * m_capacity, newSize);
    return std::max(newCapacity, m_kMinCapacity);
}

bool StringEager::equals(const char* str, size_t len) const
{
    return m_size == len && ::memcmp(m_start, str, m_size) == 0;
}

bool StringEager::lessThan(const char* str, size_t len) const
{
    uint32_t size = std::min(m_size, static_cast<size_type>(len));
    int result = ::memcmp(m_start, str, size);
    return result == 0 ? (m_size < len) : (result < 0);
}
