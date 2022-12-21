#include "Card.hpp"

WheatField::launchEffect(Game g){
    if (owner!=nullptr){
        owner.wallet.addCoins(num); //a voir si on a une banque qui est limité il faut que cela vienne de la banque sinon est-ce qu'on a vraiment besoin d'une banque ?
    }
}

WheatField::WheatField((int i, string n, string desc, int cos, Expansions exp, Types typ, Types typ, /* voir comment on gere list*/ , string ori, int num
            :id(i),cardName(n),description(desc),cost(cos),expansion(exp), type(typ), /* voir comment on gere list*/, originOfCoinsEarned(ori), numberOfCoinsEarned(num);{
                n = "Wheat Field";
                desc = "blabla";
                cos = 1;
                exp = "Standard";
                typ = "wheat";
                /* voir comment on gere list*/
                ori = "Bank";
                num = 1;
            }