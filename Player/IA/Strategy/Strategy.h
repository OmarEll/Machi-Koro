//
// Created by Omar Elloumi on 24/12/2022.
//
#pragma once

#include "../../Card/Card.hpp"
#include "../../UTILS/Enums.hpp"
#include "../IA.hpp"

class Strategy{
public:
    virtual Card* chooseCard(Player* ia,int balance,Board* board)=0;
    virtual ~Strategy()=default;
};

class EasyLevel : public Strategy{
public :
    Card* chooseCard(Player* ia,int balance,Board* board) override;
    ~EasyLevel()=default;
};
