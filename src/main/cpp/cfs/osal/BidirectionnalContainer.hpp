

#ifndef CFS_OSAL_BIDIRECTIONNALCONTAINER_HPP
#define CFS_OSAL_BIDIRECTIONNALCONTAINER_HPP

#include <stdio.h>
#include <stdint.h>

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace cfs::osal
{
    template <typename Object>
    class BidirectionnalContainer
    {
        protected:

            std::vector<Object*>                      objectVec;
            std::unordered_map<Object*, std::int32_t> indexMap;

        public:

            BidirectionnalContainer();
            ~BidirectionnalContainer();
            //iterator... back();
            Object* last();
            size_t size() const;
            int getIndex(Object* ref);

            Object &operator[](const int &i);
            const Object &operator[](const int &i) const;

            Object* at(const int &i);
            Object* at(const int &i) const;

            Object &back();
            const Object &back() const;
            Object &front();
            const Object &front() const;
    };

    template <typename Object>
    class BidirectionnalContainerReference : public BidirectionnalContainer<Object>
    {
        public:

            //BidirectionnalContainerReference(const BidirectionnalContainerReference<Object> &toCopy);
            Object* push_back(Object* toInsert);
            void remove(std::unordered_set<Object*> &toRemove);
    };

    template <typename Object>
    Object* BidirectionnalContainerReference<Object>::push_back(Object* toInsert)
    {
        this->indexMap.insert({toInsert, this->objectVec.size()});
        this->objectVec.push_back(toInsert);

        return toInsert;
    }

    // Linear in container size whatever the size of the given set of element to remove
    // => more efficient to remove one big set than several small ones
    template <typename Object>
    void BidirectionnalContainerReference<Object>::remove(std::unordered_set<Object*> &toRemove)
    {
        // Remove element and its references in data structures
        int end = -1;
        for(int i = this->objectVec.size() - 1; i>=-1; --i)
        {
            if(i>=0 && toRemove.find(this->objectVec[i]) != toRemove.end())
            {
                if(end<0)
                    end = i + 1;
                this->objectVec.erase(this->objectVec.begin() + i);
            }
            //      else if(i<0 || (end>=0 && toRemove.find(this->objectVec[i]) == toRemove.end()))
            //      {
            //          this->objectVec.erase(this->objectVec.begin()+i+1, this->objectVec.begin()+end);
            //          end = -1;
            //      }
        }

        // Rebuild indexMap
        this->indexMap.clear();
        for(int32_t i = 0; i<this->objectVec.size(); ++i)
            this->indexMap.insert({this->objectVec[i], i});
    }
}
#endif

