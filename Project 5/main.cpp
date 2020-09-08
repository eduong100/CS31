#include <cassert>
#include <iostream>
#include "Auction.h"
#include "EBayBucks.h"
using namespace std;

int main() {
    Auction auction("4th Generation iPod", 50.00);
    EBayBucks bucks;

    assert(auction.numberOfBids() == 0);
    assert(auction.wasSuccessful() == false);
    assert(auction.getDescription() == "4th Generation iPod");
    assert(std::to_string(auction.winningBid()) == "-1.000000");

    // bids don't count if the auction isn't open...
    assert(auction.bid(100.00) == false);
    assert(auction.bid(200.00) == false);
    assert(auction.bid(300.00) == false);
    assert(auction.numberOfBids() == 0);
    assert(auction.wasSuccessful() == false);
    assert(std::to_string(auction.winningBid()) == "-1.000000");

    auction.openAuction();

    // an auction is not successful if the bids are too low...
    assert(auction.bid(-50.00) == false);   // negative bids are ignored
    assert(auction.bid(1.00) == true);
    assert(auction.bid(2.00) == true);
    assert(auction.bid(3.00) == true);
    assert(auction.bid(1.50) == false);     // bids lower than the currentBid value are ignored
    assert(auction.numberOfBids() == 3);
    assert(auction.wasSuccessful() == false);
    assert(std::to_string(auction.winningBid()) == "-1.000000");

    // an auction must be closed to be deemed successful
    assert(auction.bid(100.00) == true);
    assert(auction.numberOfBids() == 4);
    assert(auction.wasSuccessful() == false);

    auction.closeAuction();
    assert(auction.wasSuccessful() == true);
    assert(std::to_string(auction.winningBid()) == "100.000000");

    // bids don't count if the auction is closed...
    assert(auction.bid(500.00) == false);
    assert(auction.bid(600.00) == false);
    assert(auction.numberOfBids() == 4);

    assert(std::to_string(bucks.earnings()) == "0.000000");
    assert(std::to_string(bucks.issueCertificate()) == "0.000000");

    bucks.addAuction(auction);
    assert(std::to_string(bucks.earnings()) == "1.000000");
    assert(std::to_string(bucks.issueCertificate()) == "1.000000");
    // once a certificate is issued, the earned award gets reset to zero
    assert(std::to_string(bucks.earnings()) == "0.000000");

    Auction a("unsuccessful", 10000.00);
    a.openAuction();
    assert(a.bid(100.00) == true);
    a.closeAuction();
    assert(a.wasSuccessful() == false);

    // unsuccessful auctions don't raise the earned award
    bucks.addAuction(a);
    assert(std::to_string(bucks.earnings()) == "0.000000");

    //cout << "all tests passed!" << endl;
	return 0;
}