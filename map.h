/*************************************************************************
 * Name:
 *    MAP
 * Summary:
 *    Implementation of the map class similar to std::map
 * Author:
 *    Group 13: Evan Harrison, Mark Mayeda, Edvaldo Melo, Michael Schmidt
 *************************************************************************/

#ifndef MAP_H
#define MAP_H

#include "bst.h"
#include "pair.h"

namespace custom
{

template <class K, class V>
class map
{
  private:
   BST <pair <K, V> > bst;
   
  public:
   map() { }
   map(const map & rhs) { *this = rhs; }
   ~map() { clear(); }

   map & operator = (const map & rhs);

   class iterator;
   iterator begin() { return bst.begin(); }
   iterator end()   { return bst.end(); }

   int size()   { return bst.size(); }
   bool empty() { return bst.empty(); }
   void clear() { bst.clear(); }

   iterator find(const K & k);
   void insert(const pair <K, V> & pair);
   void insert(const K & k, const V & v);
   V & operator [] (const K & k);
   V operator [] (const K & k) const;

};

/**************************************************************************
 * MAP :: ITERATOR
 * Iterator
 **************************************************************************/
template <class K, class V>
class map <K, V> :: iterator
{
  private:
   typename BST <pair <K, V> > :: iterator it;
   
  public:
   iterator() { }
   iterator(const typename BST <pair <K, V> > :: iterator & it) : it(it) { }
   iterator(const iterator & rhs) { *this = rhs; }
   iterator & operator = (const iterator & rhs)
   {
      it = rhs.it;
      return *this;
   }

   // comparison
   bool operator == (const iterator & rhs) const { return it == rhs.it; }
   bool operator != (const iterator & rhs) const { return it != rhs.it; }

   // increment and decrement
   iterator & operator ++ ()            { ++it; }
   iterator & operator ++ (int postfix) { it++; }
   iterator & operator -- ()            { --it; }
   iterator & operator -- (int postfix) { it--; }

   // dereference
   pair <K, V> & operator * () { return *it; }
   
};
      
   

/**************************************************************************
 * MAP :: OPERATOR =
 * Assignment Operator
 **************************************************************************/
template <class K, class V>
map <K, V> & map <K, V> :: operator = (const map <K, V> & rhs)
{
   bst = rhs.bst;
   return *this;
}
   

/**************************************************************************
 * MAP :: FIND
 * Returns an iterator to a pair with a given key if it exists; otherwise,
 * the end() iterator is returned
 **************************************************************************/
template <class K, class V>
typename map <K, V> :: iterator map <K, V> :: find(const K & k)
{
   pair <K, V> pair(k, V());
   return bst.find(pair);
}
   

/**************************************************************************
 * MAP :: INSERT
 * Inserts a key-value pair into the map; if the key already exists, the
 * value at the key will be updated
 **************************************************************************/
template <class K, class V>
void map <K, V> :: insert(const pair <K, V> & pair)
{
   iterator findIt = bst.find(pair);

   // update value if pair exists; otherwise, insert new pair
   if (findIt != end())
      *findIt = pair;
   else
      bst.insert(pair);
}

template <class K, class V>
void map <K, V> :: insert(const K & k, const V & v)
{
   pair <K, V> pair(k, v);
   insert(pair);
}

/**************************************************************************
 * MAP :: OPERATOR []
 * Square Brackets Operator
 **************************************************************************/
template <class K, class V>
V & map <K, V> :: operator [] (const K & k)
{
   iterator findIt = find(k);

   // insert if key doesn't exist
   if (findIt == end())
   {
      insert(k, V());
      findIt = find(k);
   }

   return (*findIt).second;
}

template <class K, class V>
V map <K, V> :: operator [] (const K & k) const
{
   iterator findIt = find(k);

   // return value if key exists; otherwise, return default
   if (findIt != end())
      return (*findIt).second;
   else
      return V();   
}

} // namespace custom

#endif // MAP_H
