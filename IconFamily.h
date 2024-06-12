#ifndef ICONFAMILY_H
#define ICONFAMILY_H

#include <string>

class IconFamily {
public:
    virtual std::string getIntermediateIcon() const = 0;
    virtual std::string getLeafIcon() const = 0;
    virtual ~IconFamily() = default;
};

#endif // ICONFAMILY_H
