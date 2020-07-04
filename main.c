#include <stdio.h>

#include "game.h"

int main()
{
    t_game * g = game_init();

    game_loop(g);
    return 0;
}

void game_loop(t_game * g)
{
  int p_hand;
  print_player_coins(g->player); // Afficher le nombre de jetons du joueur
broker_new_hand(g); // Le croupier pioche
player_new_hand(g); // Le joueur pioce
print_player_hand(g->player); // Afficher la main du joueur
broker_place_bet(g); // Le croupier mise
player_place_bet(g); // Le joueur mise
p_hand = sum_player_hand(g->player); /* Le joueur choisi la valeur de ses Valets
 et cette function "return" le score du joueur */
print_turn_results(g, p_hand); /* Afficher le score du croupier et du joueur
 (le score du joueur doit être donné par la
 variable p_hand) */


if (p_hand > 21) {
 player_breakthrough(g); // Le joueur dépasse 21
}

if (p_hand <= g->brocker) {
  player_lost(g); // Le joueur perd
 }

 if (p_hand == 21) {
  player_jackpot(g); // Le joueur fait 21
 }

 if (p_hand >= g->brocker)
 player_win(g); // Le joueur gagne 
 }
}