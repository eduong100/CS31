//
//  PayTable.cpp
//  SlotMachine
//
//
#include<iostream>
#include "PayTable.h"


PayTable::PayTable( char wheel1, char wheel2, char wheel3 )
{
    mWheel1 = wheel1;
    mWheel2 = wheel2;
    mWheel3 = wheel3;
}

// FIN TODO:  For the wheel combination, determine the pay multiplier
// SEQUENCE IS AKQJ9876
PayTable::Multiplier PayTable::calculateMultiplier( )
{
    // For now...
    Multiplier result = ZERO;
    int arr[3] = { mWheel1,mWheel2,mWheel3 };
    
    int aceCount = 0, kingCount = 0, queenCount = 0;
    for (int i = 0; i < 3; i++) {
        if (arr[i] == 'A')
            aceCount += 1;
        else if (arr[i] == 'Q')
            queenCount += 1;
        else if (arr[i] == 'K')
            kingCount += 1;
    }
    // CASE: 3 of a kind
    if (mWheel1 == mWheel2 && mWheel2 == mWheel3 && mWheel1 == mWheel3) {
        if (mWheel1 == 'A')
            result = TENTIME;
        else
            result = SEVENTIME;
    }
    // CASE: AKQ IN ANY ORDER
    else if (kingCount == 1 && queenCount == 1 && aceCount == 1)
        result = FIVETIME;
    // CASE: PAIRS
    else if (mWheel1 == mWheel2 || mWheel2 == mWheel3 || mWheel1 == mWheel3) {
        if (aceCount == 2)
            result = FIVETIME;
        if (aceCount == 1)
            result = FOURTIME;
        if (aceCount == 0)
            result = THREETIME;
    }
    // CASE: JUST A SINGLE ACE
    else if (aceCount == 1)
        result = ONETIME;
    return( result );
}

// FIN TODO: For the wheel combination and wager of the passed Bank, update the Bank's balance
void PayTable::manageWager( Bank & bank )
{
    // for the wager, adjust the Bank balance based on the pay multiplier

    int amount = bank.getWager();
    Multiplier multiplier = this->calculateMultiplier();
    //std::cout << multiplier << " " << amount << std::endl;
    if (multiplier == 0) {
        bank.lose(amount);
    }
    else {
        bank.win(amount * multiplier);
    }
    // FIN TODO: adjust the bank balance accordingly...
}
