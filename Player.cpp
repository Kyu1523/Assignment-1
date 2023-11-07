#include "Player.hpp"

/**
 * @post: Construct a new Player Object
 * 
 */
Player::Player() : score_(0),opponent_(nullptr),actiondeck_(nullptr),pointdeck_(nullptr){

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
                hand_.addCard(std::move(pointdeck_->Draw()));
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

/**
 * @post: Adds a point card from point deck to player hand 
 */
void Player::drawPointCard(){
    if(pointdeck_->IsEmpty()){
        return;
    }
    else{
        hand_.addCard(std::move(pointdeck_->Draw()));
    }
}
/**
 * @post: Play a point from the player's hand and add it to their score
 * 
 */
void Player::playPointCard(){
    if(hand_.isEmpty()){
        return;
    }
    else{   
        score_+= hand_.PlayCard();
    }
}

/**
 * @post: Sets the opponenet of the player
 * @param: a pointer to a opponent/other player
 */
void Player::setOpponent(Player* opponent){
    opponent_ = opponent;
}

/**
 * @return the player's opponent
 */
Player* Player::getOpponent(){
    return opponent_;
}

/**
 * @post:: set the action deck of the player
 * @param: A pointer to a deck holding Action Cards
 */
void Player::setActionDeck(Deck<ActionCard>* action_deck){
    actiondeck_ = action_deck;
}

/**
 * @return Player's action deck
 */
Deck<ActionCard>* Player::getActionDeck(){
    return actiondeck_;
}

/**
 * @post: set the point deck of the player
 * @param: pointer to a deck storing point cards
 */
void Player::setPointDeck(Deck<PointCard>* pointdeck){
        pointdeck_ = pointdeck;
}

/**
 * @return Player's deck of point cards
 */
Deck<PointCard>* Player::getPointDeck(){
    return pointdeck_;
}
