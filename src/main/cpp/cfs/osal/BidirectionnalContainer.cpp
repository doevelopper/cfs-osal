

#include <cfs/osal/BidirectionnalContainer.hpp>

using namespace cfs::osal;

template <typename Object>
BidirectionnalContainer<Object>::BidirectionnalContainer()
{
}

template <typename Object>
BidirectionnalContainer<Object>::~BidirectionnalContainer()
{
    //  for(size_t i=0; i<objectVec.size(); ++i)
    //      delete objectVec[i];
}

template <typename Object>
Object& BidirectionnalContainer<Object>::operator[](const int &i)
{
    return *objectVec[i];
}

template <typename Object>
const Object& BidirectionnalContainer<Object>::operator[](const int &i) const
{
    return *objectVec[i];
}

template <typename Object>
Object* BidirectionnalContainer<Object>::at(const int &i)
{
    return objectVec[i];
}

template <typename Object>
Object* BidirectionnalContainer<Object>::at(const int &i) const
{
    return objectVec[i];
}

template <typename Object>
Object& BidirectionnalContainer<Object>::front()
{
    return *objectVec[0];
}

template <typename Object>
const Object& BidirectionnalContainer<Object>::front() const
{
    return *objectVec[0];
}

template <typename Object>
Object& BidirectionnalContainer<Object>::back()
{
    return *objectVec[objectVec.size() - 1];
}

template <typename Object>
const Object& BidirectionnalContainer<Object>::back() const
{
    return *objectVec[objectVec.size() - 1];
}

template <typename Object>
Object* BidirectionnalContainer<Object>::last()
{
    return objectVec[objectVec.size() - 1];
}

template <typename Object>
size_t BidirectionnalContainer<Object>::size() const
{
    return objectVec.size();
}

template <typename Object>
int BidirectionnalContainer<Object>::getIndex(Object* ref)// const
{
    if(indexMap.find(ref) != indexMap.end())
    {
        return (indexMap.find(ref)->second);
    }
    else
    {
        return (-1);
    }
}

