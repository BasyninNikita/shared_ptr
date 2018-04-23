// Example program
#include <iostream>
#include <string>
#include <utility>
template <typename T>
class shared_ptr{
private:
    T * ptr;
    size_t * count;
public:
    shared_ptr(){
        ptr=nullptr;
        count=nullptr;
    }
    shared_ptr(T * oth)
    {
        ptr=oth;
        count=(new size_t=1);
    }
    shared_ptr(shared_ptr & other){
        ptr=other.ptr;
        count=other.count;
    }
    ~shared_ptr(){
        if (count) {
            if (*count == 1) {
                delete count;
                delete ptr;
            }
            else (*count)--;
        }    
    }
    void swap(shared_ptr & other){
        std::swap (ptr_, *other);
		std::swap (count, other.count);    
    }
    T * get()const{
        return ptr;
    }
    T & operator*(){
        return ptr;    
    }
    shared_ptr & operator=(const shared_ptr & other){
        if (this != &other) {
            if (count) {
                if (*count == 1) {
                    delete count;
                    delete ptr;
                }
                else (*count)--;
            }
            ptr = other.ptr;
            count = other.count;
            (*count)++;
        }
        return *this;
    }
    T * operator->(){
        return * ptr;    
    }
    T * reset()const{}
    
    
};
