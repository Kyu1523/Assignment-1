#include "Player.hpp"

/**
 * @post: Construct a new Player Object
 * 
 */
Player::Player() : score_(0),opponent_(nullptr){

}
/**
 * @post: Destroy the Player object
 */
Player::~Player(){
    hand_.~Hand();
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_->~Deck();
    pointdeck_->~Deck();
}

/**
 * @return the player's hand
 * 
 */
const Hand& Player::getHand() const{
    return hand_;
}

/**
 * @post:Set the player's Hand
 * @param const reference to a hand object
 */
void Player::setHand(const Hand& hand){
    hand_ = hand;
}

/**
 * @return the Player's current score
 */
int Player::getScore() const{
    return score_;
}

/**
 * @post: Play a given action card
 * @param: an ActionCard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard&& card){
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    if(card.isPlayable()){
        if(card.getInstruction().substr(0,3) == "DRAW"){
            int num = card.getInstruction().at(5);
            for(int i = 0; i < num; i++){
                hand_.addCard(pointdeck_->Draw());
            }
        }
        else if(card.getInstruction().substr(0,3) == "PLAY"){
            int num = card.getInstruction().at(5);
            for(int i = 0; i < num; i++){
                score_ += hand_.PlayCard();
            }
        }
        else if(card.getInstruction() == "REVERSE HAND"){
            hand_.Reverse();
        }
        else if(card.getInstruction() == "SWAP HAND WITH OPPONENT"){
            Hand temp = hand_;
            hand_ = opponent_->hand_;
            opponent_->hand_ = temp;
            temp.~Hand();
        }
    }
}