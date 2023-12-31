/*
CSCI335 Fall 2023
Assignement 1 - Card Game
Kenny Yu
10/28/23
Deck.cpp is the implementation of Deck.hpp
*/

#include "Deck.hpp"

/**
 * Default Constructer
 * @post:Construct a new Deck Object
 */
template<typename CardType>
Deck<CardType>::Deck(){
}

/**
 * @brief Destroy the Deck:: Deck object
 */
template<typename CardType>
Deck<CardType>::~Deck(){
    cards_.clear();
}

/**
 * @post: Add a card to the deck
 * @param: const reference to CardType card
 */
template<typename CardType>
void Deck<CardType>::AddCard(const CardType& card){
    cards_.push_back(card);
}

/**
 * @post: Draw a card from the deck
 * @pre: the deck is not empty
 * @return the right hand value of type CardType
 */
template<typename CardType>
CardType&& Deck<CardType>::Draw(){
    while(!cards_.empty() && cards_.back().getInstruction() == ""){   //removes cards that aren't playable
        cards_.pop_back();
    }
    if(!cards_.empty()){        //if there are still cards after popping return a rvalue of card
        cards_.back().setDrawn(true);
        return std::move(cards_.back());
    }
    else{
        throw std::out_of_range("Deck is Empty");
    }
}

/**
 * @return if the deck is empty
 */
template<typename CardType>
bool Deck<CardType>::IsEmpty() const{
    return cards_.empty();
}

/**
 * @post: Shuffle the deck
 */
template<typename CardType>
void Deck<CardType>::Shuffle(){
    std::mt19937 mt(2028358904);
    std::shuffle(cards_.begin(),cards_.end(),mt);
}

/**
 * @return the size of the deck
 */
template<typename CardType>
int Deck<CardType>::getSize() const{
    return cards_.size();
}

/**
 * @return the vector of cards in the deck
 */
template<typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const{
    return cards_;
}