#include <iostream>
#include "Player/Player.hpp"
using namespace std;
// C'est Marius
// C'est Sarah
int main(){
    Player player=*new Player("Omar");
    cout<<player.getName();
    return 0;
}


