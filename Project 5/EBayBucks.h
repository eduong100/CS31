#ifndef EBAYBUCKS_H
#define EBAYBUCKS_H

#include "Auction.h"
using namespace std;

class EBayBucks {
public:
	EBayBucks();
	void addAuction(Auction a);
	double earnings() const;
	double issueCertificate();
private:
	double earnedAward;
};

#endif