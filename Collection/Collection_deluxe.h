//
// Created by sarah on 29/12/2022.
//

#ifndef MACHI_KORO_2_COLLECTION_DELUXE_H
#define MACHI_KORO_2_COLLECTION_DELUXE_H

#include "Collection_harbor.h"
#include "Collection_GreenValley.h"
#include "Collection_standard.h"

class Collection_deluxe : public Collection_harbor, public Collection_GreenValley{
public:
    Collection_deluxe() : Collection_standard(), Collection_harbor(), Collection_GreenValley(){};
    ~Collection_deluxe(){};
};


#endif //MACHI_KORO_2_COLLECTION_DELUXE_H
