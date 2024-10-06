template <typename T>
UniquePtr<T>::UniquePtr()
{
    _p=nullptr;
}

template <typename T>
UniquePtr<T>::UniquePtr(T* ptr)
{
    _p=ptr;
}

template <typename U>
U* make_unique(U value)
{
    return new U(value);
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    delete(_p);
    _p=nullptr;
}

template <typename T>
T* UniquePtr<T>:: get()
{
    return _p;
}

template <typename  T>
T UniquePtr<T>::operator *()
{
    return *_p;
}

template <typename  T>
T* UniquePtr<T>::operator ->()
{
    return _p;
}

template <typename  T>
void UniquePtr<T>::reset()
{
    delete(_p);
    _p=nullptr;
}

template <typename  T>
void UniquePtr<T>::reset(T* newptr)
{
    delete(_p);
    _p=newptr;
}

template <typename  T>
T* UniquePtr<T>::release()
{
    T* releasedPtr = _p;
    _p = nullptr;
    return releasedPtr;
}
template <typename T>
UniquePtr<T>:: operator bool()const
{
    return _p;
}