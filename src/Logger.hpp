// use log << whatever u want to log
// or log(a, v, ds, df, "   ")

#include <iostream>

namespace LoggerStuff
{
template<typename T, typename = void>
struct canWrite: std::false_type {};

template <typename T>
struct canWrite<T, std::void_t<decltype(std::cout<<std::declval<T>())  >> : std::true_type {};

template <typename>
struct isPair : std::false_type {};

template <class A, class B>
struct isPair<std::pair<A, B>> : std::true_type {};

}

class Logger
{
public:
    template <class T> 
    typename std::enable_if<LoggerStuff::canWrite<T>::value, Logger&>::type
    operator<<(const T& t)
    {
        std::cout << t; return *this;
    }

    template <class T> 
    typename std::enable_if<!LoggerStuff::canWrite<T>::value, Logger&>::type
    operator<<(const T& t)
    {
        if constexpr (LoggerStuff::isPair<T>::value)
        {
            return *this << "(" << t.first << "," << t.second << ")";
        }
        else
        {
            *this << "{";
            for(auto i = t.begin(); i != t.end();)
            {
                *this << *i;
                if(++i != t.end())
                    *this << ' ';
            }

            return (*this << "}");
        }

    }

    template <class... Args> void operator()(const Args&... args)
    {
        auto t = {(*this << (args), 0)...};
        reinterpret_cast<int&>(t)++; //shut up warnings        
    }
};

extern Logger log;

