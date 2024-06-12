#ifndef TREESTYLE_H
#define TREESTYLE_H

#include "Style.h"
#include "include/json/json.h"
#include <iostream>

class TreeStyle : public Style {
public:
    void render(const Json::Value& jsonData, const IconFamily& iconFamily) const override {
        renderNode(jsonData, iconFamily, "");
    }

private:
    void renderNode(const Json::Value& node, const IconFamily& iconFamily, const std::string& indent) const {
        vector<string> format = {"├", "┤", "├", "|", "─", "┴", "┌", "┐", "└", "┘", "|", "─"};
        if (node.isObject()) {
            for (const auto& key : node.getMemberNames()) {
                std::cout << indent << format[6] << iconFamily.getIntermediateIcon() << " " << key << std::endl;
                renderNode(node[key], iconFamily, indent + format[7] );
            }
        } else if (node.isArray()) {
            for (const auto& item : node) {
                renderNode(item, iconFamily, indent + format[11] );
            }
        } else {
            std::cout << indent  << format[1] << iconFamily.getLeafIcon() << " " << node.asString() << std::endl;
        }
    }
};

#endif // TREESTYLE_H
