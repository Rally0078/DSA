
//template implementation
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
   
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
   
    return true;
}
 
// Function to return the smallest
// prime number greater than N
int nextPrime(int N)
{
 
    // Base case
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;
 
    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;
 
        if (isPrime(prime))
            found = true;
    }
 
    return prime;
}


//hash class with string template
template <>
class hash<string>
{
    public:
        size_t operator()(const string &key)
        {
            size_t hashValue = 0;
            for(char ch : key)
                hashValue = 37 * hashValue + ch;
            return hashValue;
        }
};

template <typename HashObj>
size_t HashTable<HashObj>::myhash(const HashObj &x ) const
{
    static hash<HashObj> hf;
    return hf(x) % theLists.size();
}

template <typename HashObj>
void HashTable<HashObj>::makeEmpty()
{
    for(auto &thisList: theLists)
        thisList.clear();
}

template <typename HashObj>
bool HashTable<HashObj>::contains(const HashObj &x) const
{
    auto &whichList = theLists[myhash(x)];
    return find(begin(whichList), end(whichList), x) != end(whichList);
}

template <typename HashObj>
bool HashTable<HashObj>::remove(const HashObj &x) 
{
    auto &whichList = theLists[myhash(x)];
    auto itr = find(begin(whichList), end(whichList), x);
    if(itr == end(whichList))
    {
        return false;
    }
    whichList.erase(itr);
    --currentSize;
    return true;
}

template <typename HashObj>
bool HashTable<HashObj>::insert(const HashObj &x)
{
    auto &whichList = theLists[myhash(x)];
    if(contains(x))
        return false;
    whichList.push_back(x);
    //rehash here
    if(++currentSize> theLists.size())
        rehash();
    return true;
}

template <typename HashObj>
void HashTable<HashObj>::rehash( )
{
    vector<list<HashObj>> oldLists = theLists;
    theLists.resize( nextPrime( 2 * theLists.size( ) ) );
    for( auto & thisList : theLists )
        thisList.clear( );
    currentSize = 0;
    for( auto & thisList : oldLists )
        for( auto & x : thisList )
            insert( std::move( x ) );
}