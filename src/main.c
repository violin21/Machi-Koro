/* Machi Koro Game by Pandasaurus ported to C. All rights
go to their respective owners */

/* TODO (version 0.2): make it so you can choose how many players are playing, make it so you can
have second and third places after the first person wins */

/* Version 0.1 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "game_core.h"
#include "string_functions.h"

int main()
{

    srand(time(0));

    printf("Hello and welcome to Machi Koro by Pandasaurus \nported to C. All rights to their \nrespective owners.\n");

    /* making players */
    struct player player1;
    struct player player2;
    struct player player3;

    /* giving players starting resources */
    player1.wheatFields = 1;
    player1.bakeries = 1;
    player1.coins = 3;
    player1.ranches = 0;
    player1.cafes = 0;
    player1.convenienceStores = 0;
    player1.forests = 0;
    player1.stadiums = 0;
    player1.tvStations = 0;
    player1.businessCenters = 0;
    player1.cheeseFactories = 0;
    player1.furnitureFactories = 0;
    player1.mines = 0;
    player1.familyRestaurants = 0;
    player1.appleOrchards = 0;
    player1.farmersMarkets = 0;
    player1.trainStation = false;
    player1.shoppingMall = false;
    player1.amusementPark = false;
    player1.radioTower = false;

    player2.wheatFields = 1;
    player2.bakeries = 1;
    player2.coins = 3;
    player2.ranches = 0;
    player2.cafes = 0;
    player2.convenienceStores = 0;
    player2.forests = 0;
    player2.stadiums = 0;
    player2.tvStations = 0;
    player2.businessCenters = 0;
    player2.cheeseFactories = 0;
    player2.furnitureFactories = 0;
    player2.mines = 0;
    player2.familyRestaurants = 0;
    player2.appleOrchards = 0;
    player2.farmersMarkets = 0;
    player2.trainStation = false;
    player2.shoppingMall = false;
    player2.amusementPark = false;
    player2.radioTower = false;

    player3.wheatFields = 1;
    player3.bakeries = 1;
    player3.coins = 3;
    player3.ranches = 0;
    player3.cafes = 0;
    player3.convenienceStores = 0;
    player3.forests = 0;
    player3.stadiums = 0;
    player3.tvStations = 0;
    player3.businessCenters = 0;
    player3.cheeseFactories = 0;
    player3.furnitureFactories = 0;
    player3.mines = 0;
    player3.familyRestaurants = 0;
    player3.appleOrchards = 0;
    player3.farmersMarkets = 0;
    player3.trainStation = false;
    player3.shoppingMall = false;
    player3.amusementPark = false;
    player3.radioTower = false;

    printf("What is the first player's name?\n");
    scanf(" %s", &player1.name);
    printf("What is the second player's name?\n");
    scanf(" %s", &player2.name);
    printf("What is the third player's name?\n");
    scanf(" %s", &player3.name);

    /* Deciding which player goes first */
    int first = rand() % 3 + 1;
    int second = rand() % 3 + 1;
    while (second == first) // making sure that two players aren't both first
    {
        second = rand() % 3 + 1;
    }
    int third = rand() % 3 + 1;
    while (third == first || third == second)
    {
        third = rand() % 3 + 1;
    }

    char firstPlayer[32];
    char secondPlayer[32];
    char thirdPlayer[32];

    /* giving the first, second, third players names as strings so we can call
    them by their names later */
    switch (first)
    {
    case 1:
        strcpy(firstPlayer, player1.name);
        break;

    case 2:
        strcpy(firstPlayer, player2.name);
        break;

    case 3:
        strcpy(firstPlayer, player3.name);
        break;
    }
    switch (second)
    {
    case 1:
        strcpy(secondPlayer, player1.name);
        break;

    case 2:
        strcpy(secondPlayer, player2.name);
        break;

    case 3:
        strcpy(secondPlayer, player3.name);
        break;
    }
    switch (third)
    {
    case 1:
        strcpy(thirdPlayer, player1.name);
        break;

    case 2:
        strcpy(thirdPlayer, player2.name);
        break;

    case 3:
        strcpy(thirdPlayer, player3.name);
        break;
    }

    printf("%s will go first, then %s then %s.\n", firstPlayer, secondPlayer, thirdPlayer);

    int numRolled;
    int turn = 1;
    char ch;
    bool gameStatus = true;
    bool doub;

    while (gameStatus)
    {
        switch (turn)
        {
        case 1:
            printf("\n%s, when you're ready to roll, press type any key and then hit enter.\n", firstPlayer);

            scanf(" %c", &ch);

            if (streq(firstPlayer, player1.name))
            {
                do
                {
                    roll(player1, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player1.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes, any other key for no.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player1, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player1, &player2, &player3, numRolled);

                    printf("After earning, ");
                    printItems(player1);

                    purchase(&player1);
                } while (doub);
            }
            else if (streq(firstPlayer, player2.name))
            {
                do
                {
                    roll(player2, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player2.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player2, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player2, &player1, &player3, numRolled);

                    printf("After earning, ");
                    printItems(player2);

                    purchase(&player2);
                } while (doub);
            }
            else
            {
                do
                {
                    roll(player3, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player3.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player3, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player3, &player1, &player2, numRolled);

                    printf("After earning, ");
                    printItems(player3);

                    purchase(&player3);
                } while (doub);
            }

            turn++;

            break;

        case 2:
            printf("\n%s, when you're ready to roll, type any key then press enter.\n", secondPlayer);

            scanf(" %c", &ch);

            if (streq(secondPlayer, player1.name))
            {
                do
                {
                    roll(player1, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player1.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player1, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player1, &player2, &player3, numRolled);

                    printf("After earning, ");
                    printItems(player1);

                    purchase(&player1);
                } while (doub);
            }
            else if (streq(secondPlayer, player2.name))
            {
                do
                {
                    roll(player2, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player2.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player2, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player2, &player1, &player3, numRolled);

                    printf("After earning, ");
                    printItems(player2);

                    purchase(&player2);
                } while (doub);
            }
            else
            {
                do
                {
                    roll(player3, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player3.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player3, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player3, &player1, &player2, numRolled);

                    printf("After earning, ");
                    printItems(player3);

                    purchase(&player3);
                } while (doub);
            }

            turn++;

            break;

        case 3:
            printf("\n%s, when you're ready to roll, type any key then press enter.\n", thirdPlayer);

            scanf(" %c", &ch);

            if (streq(thirdPlayer, player1.name))
            {
                do
                {
                    roll(player1, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player1.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player1, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player1, &player2, &player3, numRolled);

                    printf("After earning, ");
                    printItems(player1);

                    purchase(&player1);
                } while (doub);
            }
            else if (streq(thirdPlayer, player2.name))
            {
                do
                {
                    roll(player2, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player2.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player2, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player2, &player1, &player3, numRolled);

                    printf("After earning, ");
                    printItems(player2);

                    purchase(&player2);
                } while (doub);
            }
            else
            {
                do
                {
                    roll(player3, &numRolled, &doub);

                    printf("You rolled %d\n\n", numRolled);

                    if (player3.radioTower)
                    {
                        char in;
                        printf("Since you have a radio tower, would you like to re roll? y for yes.\n");
                        scanf(" %c", &in);
                        if ((in == 'y') || (in == 'Y'))
                        {
                            roll(player3, &numRolled, &doub);

                            printf("You rolled %d\n\n", numRolled);
                        }
                    }

                    if (doub)
                        printf("Since both \"dice\" rolled the same number, and you have an amusement park, you will get to have another turn!\n");

                    earn(&player3, &player1, &player2, numRolled);

                    printf("After earning, ");
                    printItems(player3);

                    purchase(&player3);
                } while (doub);
            }

            turn = 1;

            break;
        }

        if ((player1.trainStation || player2.trainStation || player3.trainStation) && (player1.shoppingMall || player2.shoppingMall || player3.shoppingMall) && (player1.amusementPark || player2.amusementPark || player2.amusementPark) && (player1.radioTower || player2.radioTower || player3.radioTower))
            break;
    }

    if (player1.trainStation && player1.shoppingMall && player1.amusementPark && player1.radioTower)
        printf("%s has won! Congratulations!\n", player1.name);
    else if (player2.trainStation && player2.shoppingMall && player2.amusementPark && player2.radioTower)
        printf("%s has won! Congratulations!\n", player2.name);
    else
        printf("%s has won! Congratulations!\n", player3.name);
    return 0;
}