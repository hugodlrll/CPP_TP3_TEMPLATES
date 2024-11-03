#ifndef rectangle_hpp
#define rectangle_hpp

#include "Forme.hpp"

template<typename T, typename S>
class Forme;

template<typename T, typename S>
class Rectangle;

template<typename T, typename S>
ostream& operator<<(ostream& os, Rectangle<T, S> const &);

template<typename T, typename S>
class Rectangle : public Forme<T,S>
{
    public:
    Rectangle(T l, T h) : l_(l), h_(h) {}
    
    // Implémentation des méthodes purement virtuelles de Forme
    S perimetre() const override {
        return 2 * (l_ + h_);
    }
    
    S surface() const override {
        return l_ * h_;
    }
    
    T getH() const override {
        return h_;
    }
    
    T getL() const override {
        return l_;
    }

    friend ostream& operator<< <T,S>(ostream& os, Rectangle<T, S> const &);

protected:
    T l_;  // Largeur du rectangle
    T h_;  // Hauteur du rectangle
};

template<typename T, typename S>
ostream& operator<<(ostream& os, Rectangle<T, S> const & rect)
{
    os << "Rectangle l: " << rect.getL() << "h: " << rect.getH() << endl << "Centre" << "(X : " << rect.p_.getX() << ",Y : " << rect.p_.getY() << ")" << endl;
    return os;
}

/*
    public:
        Rectangle(); 
        Rectangle(T l, T h); 
        S perimetre();
        S surface();
        T getL();
        T getH();
        friend ostream& operator<< <T,S>(ostream& os, Rectangle<T, S> const &);
    protected:
        T l_;
        T h_;
};

template<typename T, typename S>
Rectangle<T, S>::Rectangle() : l_(2), h_(1) {} 

template<typename T, typename S>
Rectangle<T, S>::Rectangle(T l, T h) : l_(l), h_(h) {}

template<typename T, typename S>
S Rectangle<T, S>::perimetre()
{
    return (this->l_*2+this->h_*2);
}

template<typename T, typename S>
S Rectangle<T, S>::surface()
{
    return (this->l_*this->h_);
}

template<typename T, typename S>
T Rectangle<T, S>::getL()
{
    return l_;
}

template<typename T, typename S>
T Rectangle<T, S>::getH()
{
    return h_;
}

template<typename T, typename S>
ostream& operator<<(ostream& os, Rectangle<T, S> const & rect)
{
    os << "Rectangle l: " << rect.getL() << "h: " << rect.getH() << endl << "Centre" << "(X : " << rect.p_.getX() << ",Y : " << rect.p_.getY() << ")" << endl;
    return os;
}
*/
#endif 