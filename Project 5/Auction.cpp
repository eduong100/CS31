#include "Auction.h"
#include <string>
using namespace std;


Auction::Auction(string description, double minprice) {
	mDescription = description;
	mMinimumPrice = minprice;
	mCurrentBid = 0;
	mTotalNumberOfBids = 0;
	mAuctionIsOpen = false;
}

void Auction::openAuction() {
	mAuctionIsOpen = true;
}

bool Auction::bid(double amount) {
	if (amount <= mCurrentBid || mAuctionIsOpen == false)
		return false;
	mCurrentBid = amount;
	mTotalNumberOfBids += 1;
	return true;
}

int Auction::numberOfBids() const {
	return mTotalNumberOfBids;
}

void Auction::closeAuction() {
	mAuctionIsOpen = false;
}

bool Auction::wasSuccessful() const {
	return mCurrentBid >= mMinimumPrice && !mAuctionIsOpen;
}

double Auction::winningBid() const {
	if (this->wasSuccessful())
		return mCurrentBid;
	return -1;
}

string Auction::getDescription() const {
	return mDescription;
}