/* 
 * File:   Celda.h
 * Author: HP
 *
 * Created on 14 de junio de 2015, 04:01 AM
 */

#ifndef CELDA_H
#define	CELDA_H

class Celda {
public:
    Celda();
    Celda(int);
    Celda(const Celda& orig);
    virtual ~Celda();
    void SetTipo(int tipo);
    int GetTipo() const;
private:
    int tipo;
};

#endif	/* CELDA_H */

