#ifndef carre_hpp
#define carre_hpp

#include "Rectangle.hpp"

//template<typename T, typename S>
//class Carre;

//template<typename T, typename S>
//ostream& operator<<(ostream& os, Carre<T, S> const &);

template<typename T, typename S>
class Carre : public Rectangle<T,S>
{
    public:
        Carre(T cote) : Rectangle<T, S>(cote, cote) {} 
};

#endif