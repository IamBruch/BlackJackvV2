//
// Created by emmas on 29. 6. 2025.
//

#ifndef BLACKJACKV2_DEALERHAND_H
#define BLACKJACKV2_DEALERHAND_H

#include "PlayerHand.h"

class DealerHand : public PlayerHand {
public:
    DealerHand();

    void showFirstCard() const;
};


#endif //BLACKJACKV2_DEALERHAND_H
