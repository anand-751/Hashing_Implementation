#include <iostream>
#include <list>

#include "Hashing.h"

HashContainer::HashContainer() : mArr(new std::list<std::pair<int, std::string>>[10]), mSize(0), mCapacity(10) {}

bool HashContainer::find(int key) {
    int index = getHashIndex(key);

    const std::list<std::pair<int, std::string>>& p = mArr[index];

    for (const auto& pair : p) {
        if (pair.first == key) {
            std::cout << "Data: " << pair.second << std::endl;
            return true;
        }
    }
    
    return false;
}

void HashContainer::reHash(){
    int oldCapacity = mCapacity;
    mCapacity = mCapacity*2;
  
    std::list<std::pair<int, std::string>>* newArr = new std::list<std::pair<int, std::string>>[mCapacity];

    for (int i = 0; i < oldCapacity; i++)
    {
        std::list<std::pair<int, std::string>>& list = mArr[i];

        for (const auto& pair : list)
        {
            int newIndex = getHashIndex(pair.first);
            newArr[newIndex].push_back(pair);
        }
        
    }

    delete [] mArr;
    mArr = newArr;
}

void HashContainer::insert(int key, const std::string &val) {
    int index = getHashIndex(key);

    std::list<std::pair<int, std::string>>& p = mArr[index];

    p.push_back(std::make_pair(key, val));

    mSize++;

    if (mSize / mCapacity > 0.7)
    {
        reHash();
    }
    
}

int HashContainer::size() const{
    return mSize;
}


void HashContainer::deleteValue(int key){
    int index = getHashIndex(key);

    std::list<std::pair<int, std::string>>& p = mArr[index];

    for ( auto i = p.begin(); i != p.end(); i++)
    {
        if (i->first == key)
        {
            p.erase(i);
            mSize--;
            break;
        }       
    } 
}