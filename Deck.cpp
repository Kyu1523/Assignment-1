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
    if(card.isPlayable()){
        cards_.push_back(card);
    }
}

/**
 * @post: Draw a card from the deck
 * @pre: the deck is not empty
 * @return the right hand value of type CardType
 */
template<typename CardType>
CardType&& Deck<CardType>::Draw(){
    if(IsEmpty()){
        throw std::invalid_argument("Deck is Empty");
    }
    if(!cards_.back().isPlayable()){    //removes already moved cards
        cards.pop_back();
    }
    if(IsEmpty()){                              //if empty after popping
        throw std::invalid_argument("Deck is Empty");
    }
    cards_.back().setDrawn(true);
    return std::move(cards_.back());
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