#ifndef listeformes_hpp
#define listeformes_hpp

#include "Forme.hpp"
#include <ostream>
#include <vector>
#include <tuple>

using namespace std;

template<typename T, typename S>
class ListeFormes;

template<typename T, typename S>
ostream& operator<<(ostream&, ListeFormes<T, S> const &);

template<typename T, typename S>
class ListeFormes
{
    public:
        ListeFormes();
        void ajouter(Forme<T,S> f);
        void supprimer(Forme<T,S> f);
        S calcSurfaceTot();
        tuple<T, T> calcBoiteEnglobante();
        int  getSize();
        friend ostream& operator<< <T,S>(ostream&, ListeFormes<T, S> const &);
    protected:
        vector<Forme<T,S>> v;
};

template<typename T, typename S>
ListeFormes<T,S>::ListeFormes() {}

template<typename T, typename S>
ostream& operator<<(ostream& os, ListeFormes<T, S> const & lf)
{
    for (typename vector<Forme<T,S>>::const_iterator it = lf.v.begin(); it != lf.v.end(); ++it) {
        os << &it << " ";
    }
    return os;
}

template<typename T, typename S>
void ListeFormes<T,S>::ajouter(Forme<T,S> f)
{
    v.push_back(f);
}

template<typename T, typename S>
void ListeFormes<T,S>::supprimer(Forme<T,S> f) {
    for (typename vector<Forme<T,S>>::iterator it = v.begin(); it != v.end(); ++it) {
        if (&f == &(*it)) {
            v.erase(it);
            break;
        }
    }
}

template<typename T, typename S>
int ListeFormes<T,S>::getSize()
{
    return v.size();
}

template<typename T, typename S>
S ListeFormes<T,S>::calcSurfaceTot()
{
    T surfaceTotale = 0;
    for (const auto& forme : v) {
        surfaceTotale += forme.surface();
    }
    return surfaceTotale;
}
        
template<typename T, typename S>
tuple<T, T> ListeFormes<T,S>::calcBoiteEnglobante()
{
    if (v.empty())
    {
        cout << "La liste est vide" << endl;
        tuple<int,int> zero (0,0);
        return zero;
    }
        
    T maxX = v[0].getL();
    T maxY = v[0].getH();

    for (const auto& forme : v) {
        if (forme.getL() > maxX) 
            maxX = forme.getL();
        if (forme.getH() > maxY)
            maxY = forme.getH();
    }

    tuple<T, T> be(maxX, maxY);
    return be;
}

#endif