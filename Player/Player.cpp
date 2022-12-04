//
// Created by Omar Elloumi on 04/12/2022.
//

#include "Player.hpp"

bool Player::hasLandmark(LandmarksNames name) const {
    return hand.getLandmarks().find(name)!=hand.getLandmarks().end();
}


