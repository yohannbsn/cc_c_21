#include <stdio.h>

#include "game.h"

int main()
{
    t_game * g = game_init();
    t_game * g2 = game_init();

    game_loop(g, g2);
    return 0;
}

void game_loop(t_game * g)
{
  int p_hand;
  int cards;
  int turns = 0;

  while (turns < 5 && g->player->score > 0){
  

 

    print_player_coins(g->player); // Afficher le nombre de jetons du joueur
    broker_new_hand(g); // Le croupier pioche
    player_new_hand(g); // Le joueur pioce
    print_player_hand(g->player); // Afficher la main du joueur
    broker_place_bet(g); // Le croupier mise
    player_place_bet(g); // Le joueur   mise
    cards = player_ask_cards(g);
    p_hand = sum_player_hand(g->player); /* Le joueur choisi la valeur de ses Valets
    et cette function "return" le score du joueur */
    print_turn_results(g, p_hand); /* Afficher le score du croupier et du joueur
    (le score du joueur doit être donné   par la
    variable p_hand) */
    if (cards == 6 && p_hand < 21 )
    {
    player_jackpot(g);
    }
    else if (p_hand > 21) 
   player_breakthrough(g); // Le joueur dépasse 21

    else if (p_hand <= g->broker) 
    player_lost(g); // Le joueur perd
 
    else if (p_hand == 21)
    player_jackpot(g); // Le joueur fait 21

    else if (p_hand > g->broker)
    player_win(g); // Le joueur gagne
    turns++;
  }
  if (g->player->score < 15){
    printf("le joueur à perdu et il possède %d nombre de jetons\n", g->player->score);
  }
  else {
    printf("le joueur à gagné et il possède %d nombre de jetons\n", g->player->score);
  }
  
}



