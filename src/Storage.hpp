#pragma once
#include <map>

template <class T>
class Storage
{
    
public:
    static void add(const char* name, const T& t){storage[name] = t;}
    static void add(const char* name, T&& t){storage[name] = t;}

    static T& get(const char* name){return storage[name];}

private:
    static std::map<const char*, T> storage;
};

template <class T> std::map<const char*, T> Storage<T>::storage;
