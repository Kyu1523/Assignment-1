/*
CSCI335 Fall 2023
Assignment 1 - Card Game
Kenny Yu
10/29/23
ActionCard.cpp defines the implementation of ActionCard.hpp
*/

#include "ActionCard.hpp"

/**
 * @post:Construct a new Action Card Object
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
    if(getInstruction() == "SWAP HAND WITH OPPONENT"){
        return true;
    }
    else if(getInstruction() == "REVERSE HAND"){
        return true;
    }
    else if(getInstruction().substr(0,4) == "DRAW" && std::isdigit(getInstruction().at(5)) && getInstruction().substr(7,14) == "CARD(S)"){
        return true;
    }
    else if(getInstruction().substr(0,4) == "PLAY" && std::isdigit(getInstruction().at(5)) && getInstruction().substr(7,14) == "CARD(S)"){
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
    if(getImageData() == nullptr){
        std::cout << "Card: " << std::endl;
        std::cout << "No image data" << std::endl;
    }
    else{
        const int* x = getImageData();
        std::cout << "Card: " << std::endl;
        for(int i = 0; i < 80; i++){
            std::cout << x[i];
        }
        std::cout << std::endl;
    }
}