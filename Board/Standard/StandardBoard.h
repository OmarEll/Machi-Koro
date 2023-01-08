#pragma once

#include "Board.h"
#include "../Collection/Collection_standard.h"

class Board;
class Establishment;
using namespace std;

class StandardBoard : public Board {

public :
    StandardBoard(Collection_standard&);
    ~StandardBoard() = default;
};
