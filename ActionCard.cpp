/*
CSCI335 Fall 2023
Assignment 1 - Card Game
Kenny Yu
10/29/23
ActionCard.cpp defines the implementation of ActionCard.hpp
*/

#include "ActionCard.hpp"

/**
 * @post:Construt a new Action Card Object
 */
ActionCard::ActionCard(){
    setType(ACTION_CARD);
}

/**
 * @return true if the card is playable
 * To be playable, it has to be drawn and instructions has to be valid
 * Valid Instructions:
 * Draw X card(s): assume x is a positive integer
 * Play X card(s)
 * Reverse Hand: reverse the order of the cards in the hand
 * Swap hands with opponent
 */
bool ActionCard::isPlayable(){
    if(this->getInstruction() == "DRAW"){
        return true;
    }
    else if(this->getInstruction() == "PLAY"){
        return true;
    }
    else if(this->getInstruction() == "REVERSE"){
        return true;
    }
    else if(this->getInstruction() == "SWAP"){
        return true;
    }
    return false;
}

/**
 * @post: Print the ActionCard in the format
 * Type:[CardType]
 * Instruction:[Instruction]
 * Card:[ImageData]
 */
void ActionCard::Print() const {
    std::cout << "Type: " << this->getType() << std::endl;
    std::cout << "Instruction: " << this->getInstruction() << std::endl;
    if(this->getImageData() == nullptr){
        std::cout << "Card: " << "No image data" << std::endl;
    }
    else{
        std::cout << "Card: " << this->getImageData() << std::endl;
    }
}