#pragma once

#include <unordered_map>
#include <utility>
#include<thread>

template <typename keyType, typename valueType>
class MapperWrapper
{
public:
    void add(keyType key, valueType&& value)
    {
        mapper.emplace(key, std::forward<valueType>(value));
    }

      std::unordered_map<keyType, valueType>&  getMapper(){
        return  mapper;
    }

private:
      std::unordered_map<keyType, valueType> mapper;
};
