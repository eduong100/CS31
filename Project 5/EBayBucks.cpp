#include "EBayBucks.h"
#include "Auction.h"
using namespace std;


EBayBucks::EBayBucks() {
	earnedAward = 0;
}

void EBayBucks::addAuction(Auction a) {
	if (a.wasSuccessful()) {
		earnedAward = earnedAward + a.winningBid() * 0.01;
	}
}

double EBayBucks::earnings() const {
	return earnedAward;
}

double EBayBucks::issueCertificate() {
	double value = earnedAward;
	earnedAward = 0;
	return value;
}