#ifndef __deviant_hpp__
#define __deviant_hpp__

#include <iostream>
#include <stdexcept>
#include <vector>
#include <exception>
#include <string>
using namespace std;
// completer la liste suivant vos besoins

enum class TYPE { PERSONNE, DEVIANT,INCONNU };

// Utiliser une des versions de Cite
// #define CITE Cite::getCite()



/* CLASS CITE */
class Cite
{
private:
    /* data */
    int nombredhabitant = 0;
public:
    Cite(/* args */);
    int size();
    void ajouter();
    void remove();
    ~Cite();
};
extern Cite CITE;
/* CLASS EXCEPTION */
class IllegalException : public exception
{
private:
    /* data */
public:
    IllegalException(/* args */){}
    virtual const char * what() const throw() {
        return "illegal exception";
    }
    ~IllegalException(){}
};










/* CLASS INDIVIDU */
class Individu
{
protected:
    /* data */
    int id;
    static int compteur;
    TYPE type;
public:
    Individu(/* args */);
    int getId() const ;
    TYPE getType() const;
    virtual void afficher(ostream & o = cout);
    friend ostream& operator<<(ostream&o, Individu in);
    static int getCompteur();
    virtual ~Individu();
};
ostream& operator<<(ostream&o, Individu in);
class Personne : public Individu 
{
private:
    /* data */
    string nom;
public:
    Personne(/* args */);
    Personne(const string );
    string getNom() const;
    void afficher(ostream & o = cout);
    friend ostream& operator<<(ostream&o, Personne in);
    void setNom(const string&);
    ~Personne();
};
ostream& operator<<(ostream&o, Personne in);



/* CLASS Deviant */
class Deviant : public Individu
{
private:
    /* data */
    Personne perso;
    string obs;
public:
    Deviant(/* args */);
    Deviant(const Personne& p);
    Deviant(const Personne & p , const string obs);
    bool operator<(const Deviant & dev) const;
    int getId();
    void setObs(const string &);
    string getObs();
    ~Deviant();
};




/* CLASS COVID */
class Covid
{
private:
    /* data */
    vector<Deviant *> devs;
public:
    Covid(/* args */);
    void push(Deviant&);
    const Deviant& top();
    void pop();
    // ~Covid();
};


class Comparator
{
private:
    /* data */
public:
    Comparator(/* args */);
    bool operator()(const Deviant * A, const Deviant * B) const;
};

#endif
