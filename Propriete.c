
#include "Propriete.h"
static Propriete create(int id, int idCase, int price, int owner, int rent){
    Propriete p;
    p.id = id;
    p.idCase = idCase;
    p.price = price;
    p.owner = owner;
    p.rent = rent;

    return p;
};
