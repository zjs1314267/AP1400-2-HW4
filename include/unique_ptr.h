#ifndef UNIQUE_PTR
#define UNIQUE_PTR
template <typename T>
class UniquePtr
{
public:
    UniquePtr(T* ptr);
    template <typename U>
    friend U* make_unique(U value);
    UniquePtr();
    ~UniquePtr();
    T* get();
    T operator *();
    T* operator ->();
    void reset();
    void reset(T* newptr);
    T* release();
    explicit operator bool() const;
private:
    T* _p;
};








#include "unique_ptr.hpp"

#endif //UNIQUE_PTR