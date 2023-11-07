#include "Player.hpp"
#include "Hand.hpp" 
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"

int main(){
    Deck<ActionCard> A;
    ActionCard a1;
    a1.setInstruction("DRAW 8 CARD(S)");
    ActionCard a2;
    a2.setInstruction("PLAY 1 CARD(S)");
    ActionCard a3;
    a3.setInstruction("DRAW 9 CARD(S)");
    A.AddCard(a1);
    std::cout << A.getSize() << std::endl;
    A.AddCard(a2);
    std::cout << A.getSize() << std::endl;
    A.AddCard(a3);
    std::cout << A.getSize() << std::endl;
    A.Shuffle();
    ActionCard B = A.Draw();
    ActionCard C = A.Draw();
    ActionCard N = A.Draw();
    B.Print();
    std::cout << B.getDrawn() << std::endl;
    C.Print();
    N.Print();
}