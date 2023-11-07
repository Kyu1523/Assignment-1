/*
CSCI335 Fall 2023
Assignment 1 - Card Game
Kenny Yu
10/29/23
Hand.cpp is the implementation of the hand class
*/
#include "Hand.hpp"


/**
 * @post: Construct a new Hand object
 */
Hand::Hand(){
}

/**
 * @post:Destory the Hand object
 */
Hand::~Hand(){
    cards_.clear();
}

/**
 * @Copy Constructer
 * @param: Another hand object
 */
Hand::Hand(const Hand& other) : cards_(other.cards_){
}

/**
 * Copy Assignment Operator
 * @param:other Hand object
 * @return this Hand;
 */
Hand& Hand::operator=(const Hand& other){
    if(this != &other){
        cards_ = other.cards_;
    }
    return *this;
}

/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand&& other) : cards_(other.cards_){
    other.~Hand();
}

/**
 * Move Assignement Operator
 * @param: other Hand object
 * @return this hand
 */
Hand& Hand::operator=(Hand&& other){
    std::swap(cards_,other.cards_);
    return *this;
}

/**
 * @return Hand
 */
const std::deque<PointCard>& Hand::getCards() const{
    return cards_;
}
/**
 * @post: Add a card to the hand 
 * @param: Pointcard object
 */
void Hand::addCard(PointCard&& card){
    cards_.push_back(card);
}

/**
 * @return true if hand is empty
 */
bool Hand::isEmpty() const{
    if(cards_.empty()){
        return true;
    }
    return false;
}

/**
 * @post : Reverse the hand
 */
void Hand::Reverse(){
    std::reverse(cards_.begin(),cards_.end());
}

/**
 * @post: Play the card at the front of hand, throw exception if hand is empty or card isn't playable
 * @return the points earned from playing the card
 */
int Hand::PlayCard(){
    if(cards_.empty()){
        throw std::invalid_argument("Hand is empty");
    }
    if(!cards_.front().isPlayable()){
        throw std::invalid_argument("Card isn't playable");
    }
    PointCard card = cards_.front();
    card.setDrawn(true);
    return std::stoi(card.getInstruction());
}