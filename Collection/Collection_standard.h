//
// Created by mabur on 20/12/2022.
//

#pragma once

#include "../Collection/Collection_standard.h"
#include "../Card/Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"

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
