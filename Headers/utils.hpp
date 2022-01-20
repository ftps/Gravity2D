#ifndef UTILS_HPP
#define UTILS_HPP

/*
Utility header file for lists and containers
*/
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

#define LOG std::cout << "IN LINE " << __LINE__ << " OF FILE " << __FILE__ << std::endl;


/*
Function to find an element in a container
*/
template<typename T, typename U>
std::size_t findIn(const T& v, const U& id)
{
    auto it = std::find(v.begind(), v.end(), id);
    return (it == v.end()) ? -1 : std::distance(v.begin(), it);
}






/*
Vector operations for math library
*/

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& r)
{
    os << "[ ";
    for(const T& t : r){
        os << t << " ";
    }
    os << "]";
    return os;
}


// addition
template<typename T>
std::vector<T> operator+(const std::vector<T>& l, const std::vector<T>& r)
{
    std::vector<T> res(l);

    for(std::size_t i = 0; i < l.size(); ++i){
        res[i] += r[i];
    }

    return res;
}

// add equals
template<typename T>
std::vector<T> operator+=(std::vector<T>& l, const std::vector<T>& r)
{
    for(std::size_t i = 0; i < l.size(); ++i){
        l[i] += r[i];
    }

    return l;
}

// subtraction
template<typename T>
std::vector<T> operator-(const std::vector<T>& l, const std::vector<T>& r)
{
    std::vector<T> res(l);

    for(std::size_t i = 0; i < l.size(); ++i){
        res[i] -= r[i];
    }

    return res;
}

// sub equals
template<typename T>
std::vector<T> operator-=(std::vector<T>& l, const std::vector<T>& r)
{
    for(std::size_t i = 0; i < l.size(); ++i){
        l[i] -= r[i];
    }

    return l;
}

// negation
template<typename T>
std::vector<T> operator-(const std::vector<T>& r)
{
    std::vector<T> res(r.size(), 0);

    for(std::size_t i = 0; i < r.size(); ++i){
        res[i] = -r[i];
    }

    return res;
}

// vector product
template<typename T>
T operator*(const std::vector<T>& l, const std::vector<T>& r)
{
    T res = 0;

    for(std::size_t i = 0; i < l.size(); ++i){
        res += l[i]*r[i];
    }

    return res;
}

// scalar product (right side)
template<typename T>
std::vector<T> operator*(const std::vector<T>& l, const T& r)
{
    std::vector<T> res(l.size());

    for(std::size_t i = 0; i < l.size(); ++i){
        res[i] = l[i]*r;
    }

    return res;
}

// scalar product (left side)
template<typename T>
std::vector<T> operator*(const T& l, const std::vector<T>& r)
{
    return r*l;
}

#endif