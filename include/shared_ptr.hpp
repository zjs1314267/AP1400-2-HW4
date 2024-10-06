template <typename T>
std::map<T*,int> SharedPtr<T>::Count={};

template <typename T>
SharedPtr<T>::SharedPtr(T* ptr)
{
    _p=ptr;
    Count[ ptr]++;
}

template <typename U>
U* make_shared(U value)
{
    return new U(value);
}

template <typename T>
SharedPtr<T>::SharedPtr()
{
    _p=nullptr;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (_p) {
        Count[_p]--;
        if (Count[_p] == 0) {
            delete _p;
            Count.erase(_p);
        }
        _p=nullptr;
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr &ptr)
{
    _p=ptr.get();
    Count[_p]++;
}

template <typename T>
SharedPtr<T> SharedPtr<T>::operator =(SharedPtr &ptr)
{
    if (this != &ptr) {
        Count[_p]--;
        if (Count[_p] == 0) {
            delete _p;
            Count.erase(_p);
        }
    _p=ptr.get();
    Count[_p]++;
    }
    return *this;
}

template <typename T>
int SharedPtr<T>::use_count()
{
    if(_p==nullptr)
    return 0;
    return Count[_p];
}

template <typename T>
T* SharedPtr<T>::get()
{
    return _p;
}

template <typename T>
T SharedPtr<T>::operator *()
{
    return *_p;
}

template <typename T>
T* SharedPtr<T>::operator ->()
{
    return _p;
}

template <typename T>
void SharedPtr<T>::reset()
{
    Count[_p]=0;
    delete(_p);
    _p=nullptr;
}

template <typename T>
void SharedPtr<T>::reset(T* newptr)
{   
    Count[_p]=0;
    delete(_p);
    _p=newptr;
    Count[_p]++;
}

template <typename T>
 SharedPtr<T>::operator bool() const
 {
    return _p;
 }
