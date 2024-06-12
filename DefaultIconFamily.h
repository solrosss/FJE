#ifndef DEFLAUTICONFAMILY_H
#define DEFAULTICONFAMILY_H

#include "IconFamily.h"

class DefaultIconFamily : public IconFamily {
public:
    std::string getIntermediateIcon() const override {
        return " ";
    }

    std::string getLeafIcon() const override {
        return " ";
    }
};

#endif // DEFAULTICONFAMILY_H
