#include <string>
#include <list>

class HashContainer{
    private:
        std::list<std::pair<int,std::string>>* mArr;

        int mSize;

        int mCapacity;

        int getHashIndex(int key) const{
            return key % mCapacity;
        }

    public:
        HashContainer();

        void reHash();
        
        bool find(int key);

        void insert(int key, const std::string &val);

        int size() const;

        void deleteValue(int key);
};


