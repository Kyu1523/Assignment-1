/*
CSCI335 Fall 2023
Assignment 1 - Card Game
Kenny Yu
11/5
Player.cpp is the implementation of the Player Class
*/

#include "Player.hpp"

/**
 * @post: Construct a new Player Object
 * 
 */
Player::Player() : hand_(),score_(0),opponent_(nullptr),actiondeck_(nullptr),pointdeck_(nullptr){
}
/**
 * @post: Destroy the Player object
 */
Player::~Player(){
    hand_.~Hand();
    score_ = 0;
    actiondeck_->~Deck();
    actiondeck_ = nullptr;
    pointdeck_->~Deck();
    pointdeck_ = nullptr;
    opponent_->~Player();
    opponent_ = nullptr;
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
    if(card.isPlayable()){
        std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
        if(card.getInstruction().substr(0,4) == "DRAW"){
            int num = card.getInstruction().at(5);
            for(int i = 0; i < num; i++){
                drawPointCard();
            }
        }
        else if(card.getInstruction().substr(0,4) == "PLAY"){
            int num = card.getInstruction().at(5);
            for(int i = 0; i < num; i++){
                playPointCard();
            }
        }
        else if(card.getInstruction() == "REVERSE HAND"){
            hand_.Reverse();
        }
        else if(card.getInstruction() == "SWAP HAND WITH OPPONENT"){
            std::swap(hand_, opponent_->hand_);
        }
    }
    else{
        throw std::invalid_argument("Card is not Playable");
    }
}

/**
 * @post: Adds a point card from point deck to player hand 
 */
void Player::drawPointCard(){
    if(pointdeck_->IsEmpty()){
        throw std::invalid_argument("Point Deck is Empty");
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
        throw std::invalid_argument("Hand is Empty");
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
