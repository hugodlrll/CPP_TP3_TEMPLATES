#ifndef forme_hpp
#define forme_hpp

#include "PointT.hpp"

template<typename T, typename S>
class Forme;

template<typename T, typename S> 
ostream& operator<<(ostream&, Forme<T,S> const &);

template<typename T, typename S>
class Forme
{
  public:
   Forme(PointT<T> p);
   Forme();
   virtual S perimetre() const=0;
   virtual S surface() const=0;
   virtual T getH() const=0;
   virtual T getL() const=0;
   friend ostream& operator<< <T,S>(ostream&, Forme<T,S> const &);
  protected:
    PointT<T> p_;
};

template<typename T, typename S>
Forme<T, S>::Forme(PointT<T> p){
    this->p_ = p;
}

template<typename T, typename S>
Forme<T, S>::Forme(){
    PointT<int> p(0,0);
    this->p_ = p;
}

template<typename T, typename S>
ostream& operator<<(ostream& os, Forme<T, S> const & forme)
{
    os << "Forme de centre" << "(X : " << forme.getX() << ",Y : " << forme.getY() << ")" << endl;
    return os;
}

#endif