/*
CSCI335 Fall 2023
Assignment 1 - Card game
Kenny Yu
10/29/23
PointCard.cpp is the implementation fo the PointCard.hpp
*/
#include "PointCard.hpp"

/**
 * @post:Construct a new Point Card object
 * 
 */
PointCard::PointCard(){
    setType(POINT_CARD);
}

/**
 * @return true if card is drawn and instruction is a valid number
 */
bool PointCard::isPlayable(){
    std::string inst = getInstruction();
    if(!getDrawn()){
        return false;
    }
    for(int i = 0; i < inst.length();i++){
        if(!std::isdigit(inst[i])){
            return false;
        }
    }
    return true;
}

/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card:
 * [ImageData]
 */
void PointCard::Print() const{
    std::cout << "Type: " << this->getType() << std::endl;
    std::cout << "Points: " << this->getInstruction() << std::endl;
    if(this->getImageData() == nullptr){
        std::cout << "Card: " << "No image data" << std::endl;
    }
    else{
        int x = getImageData();
        std::cout << "Card: " << std::endl;
        for(int i = 0; i < 80; i++){
            std::cout << x[i];
        }
        std::cout << std::endl;
    }
}