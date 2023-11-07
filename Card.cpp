/*
CSCI335 Fall 2023
Assignement 1 - Card Game
Kenny Yu
10/28/23
Card.cpp is the implementation of Card.hpp
*/

#include <iostream>
#include "Card.hpp"

/**
* Destructor
* @post: Destroy the Card object
*/
Card::~Card(){
    instruction_ = "";
    delete bitmap_;
    bitmap_ = nullptr;
    drawn_ = false;
}

/**
 * Copy Constructer
 * @post: Construct a new Card:: Card object
 * @param: const reference to a Card object 
 */
Card::Card(const Card& rhs) :cardType_(rhs.cardType_), instruction_(rhs.instruction_), bitmap_(rhs.bitmap_), drawn_(rhs.drawn_){
}

/**
* Copy Assignment Operator
* @param const reference to a Card object
* @return this Card object
*/
Card& Card::operator=(const Card& rhs){
    instruction_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    cardType_ = rhs.cardType_;
    return *this;
}

/**
 * Move Constructer
 * @param: rvalue reference to a Card Object 
 */
Card::Card(Card&& rhs) : instruction_(rhs.instruction_),bitmap_(rhs.bitmap_),drawn_(rhs.drawn_),cardType_(rhs.cardType_){
    rhs.~Card();
}

/**
 * Move assignement operator
 * @param: rvalue reference to a Card object
 * @return this card object
 */
Card& Card::operator=(Card&& rhs){
    std::swap(cardType_, rhs.cardType_);
    std::swap(instruction_,rhs.instruction_);
    std::swap(bitmap_,rhs.bitmap_);
    std::swap(drawn_,rhs.drawn_);
    return *this;
}

/**
 * Default Constructer
 * @post: Construct a new Card object
 */
Card::Card(){
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
}

/**
 * @return the string representation of the card type
 */
std::string Card::getType() const{
    switch(cardType_){
        case POINT_CARD:
        return "POINT_CARD";
        
        case ACTION_CARD:
        return "ACTION_CARD";
    }
    return "";
}

/**
* @post: set the card type
* @param const reference to a CardType object
*/
void Card::setType(const CardType& type){
    switch(type){
        case POINT_CARD:
        cardType_ = POINT_CARD;
        break;
        
        case ACTION_CARD:
        cardType_ = ACTION_CARD;
        break;
    }
}

/**
 * @return the string representation of the card instruction
 */
const std::string& Card::getInstruction() const{
    return instruction_;
}

/**
 * @post: set the card instruction to param
 * @param: const refrence to an instruction
 */
void Card::setInstruction(const std::string& instruction){
    instruction_ = instruction;
}

/**
 * @return the image data
 */
const int* Card::getImageData() const{
    return bitmap_;
}

/**
 * @post: Set the image data
 * @param: pointer to an array of integers
 */
void Card::setImageData(int* data){
    bitmap_ = data;
}

/**
 * @return the drawn status of the card
 */
bool Card::getDrawn() const{
    return drawn_;
}

/**
 * @post:set the drawn status of the card
 * @param: const reference to a boolean
 */
void Card::setDrawn(const bool& drawn){
    drawn_ = drawn;
}