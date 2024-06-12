#ifndef STYLE_H
#define STYLE_H

#include <string>
#include "IconFamily.h"
#include "include/json/json.h" 

class Style {
public:
    virtual void render(const Json::Value& jsonData, const IconFamily& iconFamily) const = 0;
    virtual ~Style() = default;
};

#endif // STYLE_H
