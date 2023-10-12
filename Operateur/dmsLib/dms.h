#pragma once
#include <iostream>
using namespace std;
class dms
{
private:
	int* degre;
	int* minutes;
	int* secondes;

	

public:

    dms();  
    dms(int my_degre, int my_minutes, int my_secondes); 
    dms(const float my_degre);  
    ~dms(); 
    dms(const dms& my_dms);

    inline int* getDegre() const {
        return degre;
    }

    inline int* getMinutes() const {
        return minutes;
    }

    inline int* getSecondes() const {
        return secondes;
    }

    inline void setDegre(int nb) {
        *degre = nb;
    }

    inline void setMinutes(int nb) {
        *minutes = nb;
    }

    inline void setSecondes(int nb) {
        *secondes = nb;
    }
    
    dms& operator=(const dms& my_dms); 
    dms operator + (const dms& my_dms) const;  
    dms operator - (const dms& my_dms) const;  
    dms operator * (const unsigned int nb) const;  
    float operator ^ (const dms& my_dms) const;  
    bool operator <= (const dms& my_dms) const; 
    bool operator >= (const dms& my_dms) const;  
    bool operator < (const dms& my_dms) const;  
    bool operator > (const dms& my_dms) const;  
    bool operator == (const dms& my_dms) const;  
    bool operator != (const dms& my_dms) const;

    void affiche();

};

