#ifndef POKERFACEICONFAMILY_H
#define POKERFACEICONFAMILY_H

#include "IconFamily.h"

class PokerFaceIconFamily : public IconFamily {
public:
    std::string getIntermediateIcon() const override {
        return "♢";
    }

    std::string getLeafIcon() const override {
        return "♤";
    }
};

#endif // POKERFACEICONFAMILY_H
