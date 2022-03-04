#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "game_core.h"

/* prints the inputted player's items */
void printItems(struct player player)
{
    printf("you have %d coins, %d wheat fields, %d ranches, %d bakeries, %d cafes, %d convenience stores, %d forests, %d stadiums, %d TV stations, %d business centers, %d cheese factories, %d furniture factories, %d mines, %d family restaurants, %d apple orchards, %d farmers markets.\n", player.coins, player.wheatFields, player.ranches, player.bakeries, player.cafes, player.convenienceStores, player.forests, player.stadiums, player.tvStations, player.businessCenters, player.cheeseFactories, player.furnitureFactories, player.mines, player.familyRestaurants, player.appleOrchards, player.farmersMarkets);

    return;
}

/* rolls the dice, either rolling with one die or two dice */
bool roll(struct player player, int *numRolled, bool *doub)
{
    srand(time(0));

    int roll1, roll2;

    if (player.trainStation == false)
    {
        *numRolled = rand() % 6 + 1;
        return false;
    }
    else
    {
        roll1 = rand() % 6 + 1;
        roll2 = rand() % 6 + 1;
        *numRolled = roll1 + roll2;
        if (roll1 = roll2 && player.amusementPark)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/* earn income */
void earn(struct player *player, struct player *opp1, struct player *opp2, int roll)
{
    srand(time(0));

    switch (roll)
    {
    case 1:
        player->coins += player->wheatFields;
        opp1->coins += opp1->wheatFields;
        opp2->coins += opp2->wheatFields;
        break;

    case 2:
        player->coins += player->ranches;
        if (player->shoppingMall)
            player->coins += player->bakeries + player->bakeries;
        else
            player->coins += player->bakeries;
        opp1->coins += opp1->ranches;
        opp2->coins += opp2->ranches;
        break;

    case 3:
        player->coins -= opp1->cafes;
        player->coins -= opp2->cafes;
        if (player->shoppingMall)
            player->coins += player->bakeries + player->bakeries;
        else
            player->coins += player->bakeries;
        if (opp1->shoppingMall)
            opp1->coins += opp1->cafes + opp1->cafes;
        else
            opp1->coins += opp1->cafes;
        if (opp2->shoppingMall)
            opp2->coins += opp2->cafes + opp2->cafes;
        else
            opp2->coins += opp2->cafes;
        break;

    case 4:
        if (player->shoppingMall)
            player->coins += player->convenienceStores * 3 + (player->convenienceStores);
        else
            player->coins += player->convenienceStores * 3;
        break;

    case 5:
        player->coins += player->forests;
        opp1->coins += opp1->forests;
        opp2->coins += opp2->forests;
        break;

    case 6:
        player->coins += player->stadiums * 4;
        opp1->coins -= player->stadiums * 2;
        opp2->coins -= player->stadiums * 2;

        player->coins += player->tvStations * 5;
        char *playerToLose;
        if (player->tvStations > 0)
        {
            for (int i = 0; i < player->tvStations; i++)
            {
                printf("Which player would you like to take %d from from your TV Station?\n", player->tvStations * 5);
                scanf(" %s", playerToLose);
                if (playerToLose == opp1->name)
                {
                    opp1->coins -= player->tvStations * 5;
                }
                else
                {
                    opp2->coins -= player->tvStations * 5;
                }
            }
        }

        if (player->businessCenters > 0)
        {
            for (int i = 0; i < player->businessCenters; i++)
            {
                int establishment;
                printf("Which non skyscraper establishment would you like to exchange for one of your opponent's? 1 for wheat field, 2 for ranch, 3 for bakery, 4 for cafe, 5 for convenience store \n6 for forest, 7 for cheese factory, 8 for furniture factory, 9 for mine, 10 for family restaurant, 11 for apple orchard, 12 for farmers market.\n");
                scanf("%d", &establishment);
                printf("Which player would you like to take it from?\n");
                scanf(" %s", playerToLose);
                if (playerToLose == opp1->name)
                {
                    switch (establishment)
                    {
                    case 1:
                        opp1->wheatFields--;
                        player->wheatFields++;
                        break;

                    case 2:
                        opp1->ranches--;
                        player->ranches++;
                        break;

                    case 3:
                        opp1->bakeries--;
                        player->bakeries++;
                        break;

                    case 4:
                        opp1->cafes--;
                        player->cafes++;
                        break;

                    case 5:
                        opp1->convenienceStores--;
                        player->convenienceStores++;
                        break;

                    case 6:
                        opp1->forests--;
                        player->forests++;
                        break;

                    case 7:
                        opp1->cheeseFactories--;
                        player->cheeseFactories++;
                        break;

                    case 8:
                        opp1->furnitureFactories--;
                        player->furnitureFactories++;
                        break;

                    case 9:
                        opp1->mines--;
                        player->mines++;
                        break;

                    case 10:
                        opp1->familyRestaurants--;
                        player->familyRestaurants++;
                        break;

                    case 11:
                        opp1->appleOrchards--;
                        player->appleOrchards++;
                        break;

                    case 12:
                        opp1->farmersMarkets--;
                        player->farmersMarkets++;
                        break;
                    }
                }
                else
                {
                    switch (establishment)
                    {
                    case 1:
                        opp2->wheatFields--;
                        player->wheatFields++;
                        break;

                    case 2:
                        opp2->ranches--;
                        player->ranches++;
                        break;

                    case 3:
                        opp2->bakeries--;
                        player->bakeries++;
                        break;

                    case 4:
                        opp2->cafes--;
                        player->cafes++;
                        break;

                    case 5:
                        opp2->convenienceStores--;
                        player->convenienceStores++;
                        break;

                    case 6:
                        opp2->forests--;
                        player->forests++;
                        break;

                    case 7:
                        opp2->cheeseFactories--;
                        player->cheeseFactories++;
                        break;

                    case 8:
                        opp2->furnitureFactories--;
                        player->furnitureFactories++;
                        break;

                    case 9:
                        opp2->mines--;
                        player->mines++;
                        break;

                    case 10:
                        opp2->familyRestaurants--;
                        player->familyRestaurants++;
                        break;

                    case 11:
                        opp2->appleOrchards--;
                        player->appleOrchards++;
                        break;

                    case 12:
                        opp2->farmersMarkets--;
                        player->farmersMarkets++;
                        break;
                    }
                }
            }
        }
        break;

    case 7:
        player->coins += player->ranches * 3;
        break;

    case 8:
        player->coins += (player->forests * 3) + (player->mines * 3);
        break;

    case 9:
        player->coins += player->mines * 5;
        opp1->coins += opp1->mines * 5;
        opp2->coins += opp2->mines * 5;
        if (player->shoppingMall)
            opp1->coins += opp1->familyRestaurants * 2 + (opp1->familyRestaurants);
        else
            opp1->coins += opp1->familyRestaurants * 2;
        if (player->shoppingMall)
            opp2->coins += opp2->familyRestaurants * 2 + (opp2->familyRestaurants);
        else
            opp2->coins += opp2->familyRestaurants * 2;
        player->coins -= opp1->familyRestaurants * 2;
        player->coins -= opp2->familyRestaurants * 2;
        break;

    case 10:
        player->coins += player->appleOrchards * 3;
        opp1->coins += opp1->appleOrchards * 3;
        opp2->coins += opp2->appleOrchards * 3;
        opp1->coins += opp1->familyRestaurants * 2;
        opp2->coins += opp2->familyRestaurants * 2;
        player->coins -= opp1->familyRestaurants * 2;
        player->coins -= opp2->familyRestaurants * 2;
        break;

    case 11:
        player->coins += (player->wheatFields * 2) + (player->appleOrchards * 2);
        break;

    case 12:
        player->coins += (player->wheatFields * 2) + (player->appleOrchards * 2);
        break;
    }

    return;
}

/* purchase cards */
void purchase(struct player *player)
{
    int card;
    int amount;

    while (player->coins > 0)
    {
        printf("\n\nWhich card would you like to purchase? 0 for nothing, 1 for wheat field, 2 for ranch, 3 for bakery, 4 for cafe, 5 for convenience store, 6 for forest, 7 for stadium, 8 for TV station, 9 for business center, 10 for cheese factory, 11 for furniture factory, 12 for mine, 13 for family restaurant, 14 for apple orchard, 15 for farmers market, 16 for train station, 17 for shopping mall, 18 for amusement park, 19 for radio tower.\n");
        scanf("%d", &card);
        if (!(card == 0))
        {
            if (card < 15)
            {
                printf("How many cards would you like to purchase?\n");
                scanf("%d", &amount);
                switch (card)
                {
                case 1:
                    if (player->coins >= amount * 1)
                    {
                        player->wheatFields += amount;
                        player->coins -= amount * 1;
                    }
                    else
                    {
                        printf("You cannot afford %d wheat fields.\n", amount);
                    }
                    break;

                case 2:
                    if (player->coins >= amount * 1)
                    {
                        player->ranches += amount;
                        player->coins -= amount * 1;
                    }
                    else
                    {
                        printf("You cannot afford %d ranches.\n", amount);
                    }
                    break;

                case 3:
                    if (player->coins >= amount * 1)
                    {
                        player->bakeries += amount;
                        player->coins -= amount * 1;
                    }
                    else
                    {
                        printf("You cannot afford %d bakeries.\n", amount);
                    }
                    break;

                case 4:
                    if (player->coins >= amount * 2)
                    {
                        player->cafes += amount;
                        player->coins -= amount * 2;
                    }
                    else
                    {
                        printf("You cannot afford %d cafes.\n", amount);
                    }
                    break;

                case 5:
                    if (player->coins >= amount * 2)
                    {
                        player->convenienceStores += amount;
                        player->coins -= amount * 2;
                    }
                    else
                    {
                        printf("You cannot afford %d convenience stores.\n", amount);
                    }
                    break;

                case 6:
                    if (player->coins >= amount * 3)
                    {
                        player->forests += amount;
                        player->coins -= amount * 3;
                    }
                    else
                    {
                        printf("You cannot afford %d forests.\n", amount);
                    }
                    break;

                case 7:
                    if (player->coins >= amount * 6)
                    {
                        player->stadiums += amount;
                        player->coins -= amount * 6;
                    }
                    else
                    {
                        printf("You cannot afford %d stadiums.\n", amount);
                    }
                    break;

                case 8:
                    if (player->coins >= amount * 7)
                    {
                        player->tvStations += amount;
                        player->coins -= amount * 7;
                    }
                    else
                    {
                        printf("You cannot afford %d TV stations.\n", amount);
                    }
                    break;

                case 9:
                    if (player->coins >= amount * 8)
                    {
                        player->businessCenters += amount;
                        player->coins -= amount * 8;
                    }
                    else
                    {
                        printf("You cannot afford %d business centers.\n", amount);
                    }
                    break;

                case 10:
                    if (player->coins >= amount * 5)
                    {
                        player->cheeseFactories += amount;
                        player->coins -= amount * 5;
                    }
                    else
                    {
                        printf("You cannot afford %d cheese factories.\n", amount);
                    }
                    break;

                case 11:
                    if (player->coins >= amount * 3)
                    {
                        player->furnitureFactories += amount;
                        player->coins -= amount * 3;
                    }
                    else
                    {
                        printf("You cannot afford %d furniture factories.\n", amount);
                    }
                    break;

                case 12:
                    if (player->coins >= amount * 6)
                    {
                        player->mines += amount;
                        player->coins -= amount * 6;
                    }
                    else
                    {
                        printf("You cannot afford %d mines.\n", amount);
                    }
                    break;

                case 13:
                    if (player->coins >= amount * 3)
                    {
                        player->familyRestaurants += amount;
                        player->coins -= amount * 3;
                    }
                    else
                    {
                        printf("You cannot afford %d family restaurants.\n", amount);
                    }
                    break;

                case 14:
                    if (player->coins >= amount * 3)
                    {
                        player->appleOrchards += amount;
                        player->coins -= amount * 3;
                    }
                    else
                    {
                        printf("You cannot afford %d apple orchards.\n", amount);
                    }
                    break;

                case 15:
                    if (player->coins >= amount * 2)
                    {
                        player->farmersMarkets += amount;
                        player->coins -= amount * 2;
                    }
                    else
                    {
                        printf("You cannot afford %d farmers markets.\n", amount);
                    }
                    break;
                }
            }
            else
            {
                switch (card)
                {
                case 16:
                    if (player->trainStation)
                    {
                        printf("You already have your train station!\n");
                    }
                    else
                    {
                        if (player->coins > 4)
                        {
                            player->trainStation = true;
                        }
                        else
                        {
                            printf("You cannot afford the train station!\n");
                        }
                    }
                    break;

                case 17:
                    if (player->shoppingMall)
                    {
                        printf("You already have your shopping mall!\n");
                    }
                    else
                    {
                        if (player->coins > 10)
                        {
                            player->shoppingMall = true;
                        }
                        else
                        {
                            printf("You cannot afford the shopping mall!\n");
                        }
                    }
                    break;

                case 18:
                    if (player->amusementPark)
                    {
                        printf("You already have your amusement park!\n");
                    }
                    else
                    {
                        if (player->coins > 16)
                        {
                            player->amusementPark = true;
                        }
                        else
                        {
                            printf("You cannot afford the amusement park!\n");
                        }
                    }
                    break;

                case 19:
                    if (player->radioTower)
                    {
                        printf("You already have your radio tower!\n");
                    }
                    else
                    {
                        if (player->coins > 22)
                        {
                            player->radioTower = true;
                        }
                        else
                        {
                            printf("You cannot afford the radio tower!\n");
                        }
                    }
                    break;
                }
            }

            printf("After those purchases, ");
            printItems(*player);
        }
        else
        {
            break;
        }
    }

    return;
}