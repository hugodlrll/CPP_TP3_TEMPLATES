#ifndef rectangle_hpp
#define rectangle_hpp

#include "Forme.hpp"

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
    
    T getH() const {
        return h_;
    }
    
    T getL() const {
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

#endif 