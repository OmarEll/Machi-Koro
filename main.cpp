#include <iostream>
#include "Player/Player.hpp"
using namespace std;
// C'est Marius
int main(){
    Player player=*new Player("Omar");
    cout<<player.getName();
    return 0;
}


