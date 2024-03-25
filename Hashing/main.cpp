#include <iostream>
#include "Hashing.h"

void ifPresent(bool isPresent){
    if (isPresent)
    {
        std::cout << "Key is present!" << std::endl;
    }else{
        std::cout<<"Not Found!!"<<std::endl;
    }
}

int main(){
    HashContainer Hash;
    

    Hash.insert(35,"Anand");
    Hash.insert(13,"Pushpa");
    Hash.insert(40,"Vijay");
    Hash.insert(3,"Auja");
    Hash.insert(4,"Suresh");

    std::cout << "Size of Hash: " << Hash.size() << std::endl;

    std::cout<<"Enter Key to find the data : ";
    int key;
    std::cin>> key;

    bool result = Hash.find(key);
    ifPresent(result);
    
    Hash.deleteValue(13);

    std::cout<<"Enter Key to find the data : ";
    int key2;
    std::cin>> key2;

    bool result2 = Hash.find(key);
    ifPresent(result2);

    return 0;
}