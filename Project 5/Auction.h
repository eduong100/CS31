#ifndef AUCTION_H
#define AUCTION_H

#include <string>
using namespace std;

class Auction {
public:
	Auction(string description, double minprice);
	void openAuction();
	bool bid(double amount);
	int numberOfBids() const;
	void closeAuction();
	bool wasSuccessful() const;
	double winningBid() const;
	string getDescription() const;
private:
	string mDescription;
	double mMinimumPrice;
	double mCurrentBid;
	int mTotalNumberOfBids;
	bool mAuctionIsOpen;
};

#endif 

