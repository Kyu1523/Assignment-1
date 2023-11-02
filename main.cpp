#include "Player.hpp"

int main(){
    Player a;
    Player b;
    Deck<PointCard> point_deck;
    for(int i = 0; i < 20; i++){
        PointCard temp;
        temp.setInstruction(std::to_string(i));
        point_deck.AddCard(temp);
    }
    a.setPointDeck()
}