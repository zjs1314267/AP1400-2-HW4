#ifndef SHARED_PTR
#define SHARED_PTR
#include <map>
template <typename T>
class SharedPtr
{
public:
    SharedPtr(T* ptr);
    template <typename U>
    friend U* make_shared(U value);
    SharedPtr();
    ~SharedPtr();
    SharedPtr(SharedPtr &ptr);
    SharedPtr operator =(SharedPtr &ptr);
    static std::map<T*,int> Count;
    int use_count();
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
#include "shared_ptr.hpp"
#endif //SHARED_PTR