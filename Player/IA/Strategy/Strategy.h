//
// Created by Omar Elloumi on 24/12/2022.
//
#pragma once

#include "../../Card/Card.hpp"
#include "../../UTILS/Enums.hpp"

class Strategy{
public:
    virtual Card* chooseCard()=0;
};

class EasyLevel : public Strategy{
public :
    Card* chooseCard() override;
};

class MediumLevel : public Strategy{
public :
Card* chooseCard() override;
};

class HardLevel : public Strategy{
public :
Card* chooseCard() override;
};
