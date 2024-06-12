#ifndef JSONVISUALIZER_H
#define JSONVISUALIZER_H

#include "Style.h"
#include "IconFamily.h"
#include "include/json/json.h"

class JSONVisualizer {
public:
    JSONVisualizer(shared_ptr<Style> style, shared_ptr<IconFamily> iconFamily)
        : style(style), iconFamily(iconFamily) {}

    void visualize(const Json::Value& jsonData) const {
        style->render(jsonData, *iconFamily);
    }

private:
    shared_ptr<Style> style;
    shared_ptr<IconFamily> iconFamily;
};

#endif // JSONVISUALIZER_H
