//
// Created by mabur on 20/12/2022.
//
#include <vector>
#include "Establishment.h"
#include "Landmark.h"

#ifndef MACHI_KORO_COLLECTION_H
#define MACHI_KORO_COLLECTION_H

// A METTRE EN SINGLETON

using namespace std;

class Collection {
protected:
    vector<Establishment*> Establishment_Collection;
    vector<Landmark*> Landmark_Collection;
public:
    vector<Establishment*> GetEstablishment(){return Establishment_Collection;}
    vector<Landmark*> GetLandmark(){ return Landmark_Collection;}
    virtual ~Collection() = default;
    virtual void Clone(vector<Establishment*>,vector<Landmark*>) = 0;
};


#endif //MACHI_KORO_COLLECTION_H
