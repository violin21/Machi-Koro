#ifndef GAME_CORE_HEADER
#define GAME_CORE_HEADER

#include <stdbool.h>

/* contains everything the player can have */
struct player
{
    char *name;
    int coins;

    bool amusementPark;
    bool radioTower;
    bool shoppingMall;
    bool trainStation;

    int place;

    int wheatFields;
    int ranches;
    int bakeries;
    int cafes;
    int convenienceStores;
    int forests;
    int stadiums;
    int tvStations;
    int businessCenters;
    int cheeseFactories;
    int furnitureFactories;
    int mines;
    int familyRestaurants;
    int appleOrchards;
    int farmersMarkets;
};

bool roll(struct player player, int *numRolled, bool *doub);
void earn(struct player *player, struct player *opp1, struct player *opp2, int roll);
void purchase(struct player *player);
void printItems(struct player player);

#endif