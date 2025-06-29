//
// Created by emmas on 29. 6. 2025.
//

#include "DealerHand.h"

#include <iostream>

DealerHand::DealerHand() : PlayerHand() {}

void DealerHand::showFirstCard() const {
    std::cout << "Dealers first card: " << handCards[0].toString() << std::endl;
}
