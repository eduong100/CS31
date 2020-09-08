// slotmachine.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  
// As you finish implementing each TODO: item, remove its TODO: comment.

#include "SlotMachine.h"
#include "Bank.h"
#include "PayTable.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;



int main()
{
    using namespace std;

    /*
    Bank b4(100);
    SlotMachine t("ABCDEFG");
    t.showDisplay();
    b4.setWager(100.00);
    t.play(b4, 'A', 'B', 'C');


    Bank b;
    assert(b.balance() == 0);
    assert(b.getWager() == 0);
    assert(!b.canWager(100));
    b.deposit(50);
    assert(b.balance() == 50);
    assert(!b.canWager(100));
    assert(b.canWager(50));
    b.deposit(50);

    PayTable p('A', 'A', 'A');
    PayTable::Multiplier m = p.calculateMultiplier();  // 3 Aces is a 10-1 winner
    assert(m == PayTable::Multiplier::TENTIME);

    SlotMachine k("A12345");   // cheating...
    b.setWager(100);
    k.noDisplay();
    k.play(b, 'A', 'A', 'A');
    assert(b.balance() == 1100);               // 3 Aces is 10-1 winner and a round of play adjusts the bank 

    // CASE: Losing Roll
    SlotMachine testSlot("ABCDEFG987");
    testSlot.noDisplay();
    Bank testBank(100);
    testBank.setWager(100);
    testSlot.play(testBank, '7', '9', 'Q'); // cheating...
    assert(testBank.balance() == 0); // the wager is lost
    
    // CASE: Ace Pair
    testBank.deposit(10);
    testBank.setWager(10);
    testSlot.play(testBank, 'A', 'A', 'Q'); // cheating...
    assert(testBank.balance() == 60);
    testBank.cashOut();

    // CASE: Normal Pair
    testBank.deposit(10);
    testBank.setWager(10);
    testSlot.play(testBank, 'Q', '9', 'Q'); // cheating...
    assert(testBank.balance() == 40);
    testBank.cashOut();

    // CASE: Pair With Ace
    testBank.deposit(10);
    testBank.setWager(10);
    testSlot.play(testBank, 'Q', 'A', 'Q'); // cheating...
    assert(testBank.balance() == 50);
    testBank.cashOut();

    // CASE: Single Ace
    testBank.deposit(10);
    testBank.setWager(10);
    testSlot.play(testBank, 'Q', 'A', '7'); // cheating...
    assert(testBank.balance() == 20);
    testBank.cashOut();

    // CASE: AKQ
    testBank.deposit(10);
    testBank.setWager(10);
    testSlot.play(testBank, 'Q', 'A', 'K'); // cheating...
    assert(testBank.balance() == 60);
    testBank.cashOut();

    // CASE: 3 of a Kind
    testBank.deposit(10);
    testBank.setWager(10);
    testSlot.play(testBank, '7', '7', '7'); // cheating...
    assert(testBank.balance() == 80);
    testBank.cashOut();

    // CASE: Triple Aces
    testBank.deposit(10);
    testBank.setWager(10);
    testSlot.play(testBank, 'A', 'A', 'A'); // cheating...
    assert(testBank.balance() == 110);
    testBank.cashOut();

    cout << "all tests passed!" << endl;
    */
    Bank bank;
    SlotMachine s;
    //s.noDisplay();
    do
    {
         cout << endl;
         cout << "Move (d#/b#/p/c/q): ";
         string action;
         string message;
         int amount;
         getline(cin,action);
         if (action.size() == 0)
         {
             return( 0 );
         }
         else
         {
             switch (action[0])
             {
                 default:   // if bad move, nothing happens
                     cout << '\a' << endl;  // beep
                     continue;
                 case 'q':
                     return( 0 );
                     break;
                     
                 case 'b':  // get
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                         amount = 1;
                     if (bank.canWager(amount))
                     {
                         bank.setWager(amount);
                         cout << "$" << amount << " Bet Accepted!" << endl;
                     }
                     else
                     {
                         cout << "Invalid Bet" << endl;
                     }
                     break;
                 case 'p':
                     if (bank.getWager() == 0)
                     {
                         cout << "You Must Bet First Before Playing" << endl;
                     }
                     else
                     {
                         s.play( bank );
                     }
                     break;
                 case 'd':
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                     {
                         cout << "Invalid Bank Deposit" << endl;
                     }
                     else
                     {
                         bank.deposit( amount );
                         cout << "$" << bank.balance() << " Available To Bet" << endl;
                     }
                     break;
                 case 'c':
                     amount = bank.cashOut();
                     cout << "$" << amount << " Returned To You!" << endl;
                     amount = 0;
                     break;
             }
         }
         
    } while ( true );

    return 0;
}

