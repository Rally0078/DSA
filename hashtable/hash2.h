#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>

using std::string;
using std::list;
using std::vector;
using std::find;
using std::begin;
using std::end;


//Hash with separate chaining(linked list)
template <typename HashObj>
class HashTable
{
    public:
     explicit HashTable( int size = 101):currentSize(size){theLists.resize(size);}
     bool contains(const HashObj &x) const;

     void makeEmpty();
     bool insert(const HashObj &x);
     bool remove(const HashObj &x);

    private:
     vector<list<HashObj>> theLists;
     int currentSize;

     void rehash();
     size_t myhash(const HashObj &x) const;
};
template <typename Key>
class hash
{
    public:
    size_t operator() ( const Key & k ) const;
};

#include "hash2.tpp"


