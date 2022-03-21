#include <algorithm>

#include "deviant.hpp"

Cite CITE;
// CLASS PERSONNE
Personne::Personne(/* args */) : Personne("inconnu")
{
    // CITE.ajouter();
}


Personne::Personne(const string _nom) : nom(_nom)
{
    type = TYPE::PERSONNE;
    CITE.ajouter();
}
string Personne::getNom() const{
    return nom;
}
void Personne::afficher(ostream & o){
    o << nom  <<" "<< id ;
}

ostream& operator<<(ostream&o, Personne perso){
    perso.afficher(o);
    return o;
}


void Personne::setNom(const string& _nom){
    nom=_nom;
}
Personne::~Personne()
{
    CITE.remove();
}



/* CLASS INDIVIDU */
int Individu::compteur = 0;
Individu::Individu(/* args */)
{
    compteur++;
    id = compteur;
    type = TYPE::INCONNU;
}

int Individu::getId() const {
    return id;
}

TYPE Individu::getType() const{
    if (type == TYPE::INCONNU)
    {
        throw IllegalException();
    }else
    {
        return type;
    }
    
}

void Individu::afficher(ostream & o){
    o << id ;
}

ostream& operator<<(ostream&o, Individu in){
    in.afficher(o);
    return o;
}

int Individu::getCompteur(){
    return compteur;
}
Individu::~Individu()
{
}

/* CLASS CITE */

Cite::Cite(/* args */)
{
}
void Cite::ajouter(){
    nombredhabitant++;
}
int Cite::size(){
    return nombredhabitant;
}
void Cite::remove(){
    nombredhabitant--;
}
Cite::~Cite()
{
}
/* CLASS DEVIANT */

Deviant::Deviant(/* args */)
{
    type = TYPE::DEVIANT;

}

Deviant::Deviant(const Personne& p) : Deviant(p,""){
    
}

Deviant::Deviant(const Personne & p , const string _obs) : perso(p), obs(_obs){
    type = TYPE::DEVIANT;
    CITE.remove();
    // CITE.ajouter();
}
int Deviant::getId(){
    return perso.getId();
}

bool Deviant::operator<(const Deviant & dev) const{
    return this->obs < dev.obs;
}

void Deviant::setObs(const string &_obs){
    obs = _obs;
}
string Deviant::getObs(){
    return obs;
}


Deviant::~Deviant()
{
    // delete perso;
    perso.~Personne();
}



//CLASS COVID 
Covid::Covid(/* args */)
{
}

void Covid::push(Deviant& dev){
    devs.push_back(&dev);
    sort(devs.begin(),devs.end(),Comparator());
    /* cout << devs.size() << endl;
    auto toto = **devs.begin();
    cout <<toto.getObs()<<endl; */
}

const Deviant& Covid::top(){
    
    return  *devs.back();
}


void Covid::pop(){
    devs.pop_back();
}
// Covid::~Covid()
// {
   
//     //     for (auto i = devs.begin(); i != devs.end(); i++)
//     // {
//     //     if (*i != nullptr)
//     //     {
//     //         delete (*i);
//     //     }
        
//     // }
//     // devs.clear();
    
    
    
// }


Comparator::Comparator(/* args */)
{
}
bool Comparator::operator()(const Deviant * A, const Deviant * B) const{
    return *A < *B;
}
