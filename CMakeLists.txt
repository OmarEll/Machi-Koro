cmake_minimum_required(VERSION 3.24)
project(Machi_Koro)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Bank)
include_directories(Board)
include_directories(Game)
include_directories(Hand)
include_directories(Player)
include_directories(UTILS)
include_directories(Wallet)

add_executable(Machi_Koro
        Bank/Bank.hpp
        Board/Board.cpp
        Board/Board.h
        Board/Deck.h
        Board/DeluxeBoard.h
        Board/GreenValleyBoard.h
        Board/HarborBoard.h
        Board/StandardBoard.h
        Game/DeluxeExpansion.cpp
        Game/DeluxeExpansion.h
        Game/Game.cpp
        Game/Game.h
        Game/GreenValeyExpansion.cpp
        Game/GreenValeyExpansion.h
        Game/HarborExpansion.cpp
        Game/HarborExpansion.h
        Game/StandardExpansion.cpp
        Game/StandardExpansion.h
        Hand/Hand.hpp
        Player/EasyLevel.hpp
        Player/IA.hpp
        Player/Player.hpp
        Player/Strategy.hpp
        UTILS/Enums.hpp
        Wallet/Wallet.hpp
        Card.hpp
        main.cpp Dies/Dies.cpp Dies/Dies.h)
