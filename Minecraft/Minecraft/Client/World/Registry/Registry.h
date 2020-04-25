#pragma once
#include <vector>
#include <string>
#include <map>

template<class T>
class Registry{
public:
    Registry(){ 
        registryList.clear();
        registryMap.clear();
    }

    inline void addElement(short indices, std::string name, T object){
        registryList.push_back(object);

        registryMap.emplace(name, indices);
    }

    inline T getElement(int i){
        if(i < registryList.size()){
            return registryList[i];
        }else{
            return nullptr;
        }
    }

    inline T getByName(std::string name) {
        if (registryMap.find(name) != registryMap.end()) {
            return registryList[registryMap[name]];
        }
        else {
            return nullptr;
        }
    }

    inline void resetElements(){
        registryList.clear();
    }

    inline std::vector<T> getList(){
        return registryList;
    }

private:
    std::vector<T> registryList;
    std::map<std::string, int> registryMap;
};