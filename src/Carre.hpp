#ifndef carre_hpp
#define carre_hpp

#include "Rectangle.hpp"

//template<typename T, typename S>
//class Carre;

//template<typename T, typename S>
//ostream& operator<<(ostream& os, Carre<T, S> const &);

class Forme<T>;

template<typename T, typename S>
class Carre : public Rectangle<T,S>
{
    public:
        Carre(T cote) : Rectangle<T, S>(cote, cote) {} 
};

/*
    public:
        Carre(); 
        Carre(T c);
        S perimetre();
        S surface();
        friend ostream& operator<< <T,S>(ostream& os, Carre<T, S> const &);
};

template<typename T, typename S>
Carre<T, S>::Carre() : Rectangle<T,S>(1,1) {} 

template<typename T, typename S>
Carre<T, S>::Carre(T c) : Rectangle<T,S>(c,c) {}


template<typename T, typename S>
S Carre<T, S>::perimetre() 
{
    return (this->l_*4);
}

template<typename T, typename S>
S Carre<T, S>::surface()
{
    return (this->l_*this->l_);
}

template<typename T, typename S>
ostream& operator<<(ostream& os, Carre<T, S> const & c)
{
    os << "Carre de coté " << c.getL() << endl << "Centre" << "(X : " << c.p_.getX() << ",Y : " << c.p_.getY() << ")" << endl;
    return os;
}*/

#endif