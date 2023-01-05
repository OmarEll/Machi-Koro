//
// Created by mabur on 20/12/2022.
//

#ifndef MACHI_KORO_COLLECTION_STANDARD_H
#define MACHI_KORO_COLLECTION_STANDARD_H


#include "../Collection/Collection_standard.h"
#include "Establishment.h"
#include "Landmark.h"

class Collection_standard {
protected:
    vector<Establishment*> Establishment_Collection;
    vector<Landmark*> Landmark_Collection;
public :
    Collection_standard();
    virtual ~Collection_standard();
    vector<Establishment*> GetEstablishment(){return Establishment_Collection;}
    vector<Landmark*> GetLandmark(){ return Landmark_Collection;}

};


#endif //MACHI_KORO_COLLECTION_STANDARD_H
