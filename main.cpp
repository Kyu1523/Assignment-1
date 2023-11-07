#include "Player.hpp"
#include "Hand.hpp" 
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"

int main(){
    ActionCard A;
    A.setInstruction("DRAW 8 CARD(S)");
    A.Print();
}