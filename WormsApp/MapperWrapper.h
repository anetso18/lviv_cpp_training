#ifndef MAPPERWRAPPER_H
#define MAPPERWRAPPER_H

#include <unordered_map>
#include <utility>
#include<thread>

template <typename KeyType, typename valueType> class MapperWrapper
{
    public:
        void add(KeyType key, valueType&& value)
        {
        mapper.emplace(key, std::forward<std::thread>(value));
        }

        std::unordered_map<KeyType, valueType> mapper;
};
#endif
