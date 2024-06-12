#ifndef RECTANGLESTYLE_H
#define RECTANGLESTYLE_H

#include "Style.h"
#include "include/json/json.h"
#include <iostream>

class RectangleStyle : public Style {
public:
    void render(const Json::Value& jsonData, const IconFamily& iconFamily) const override {
        renderNode(jsonData, iconFamily, 0);
    }

private:
    void renderNode(const Json::Value& node, const IconFamily& iconFamily, int depth) const {
        vector<string> format = {"├", "┤", "├", "|", "─", "┴", "┌", "┐", "└", "┘", "|", "─"};
        if (node.isObject()) {
            std::cout << std::string(depth, ' ') << format[6] << std::endl;
            for (const auto& key : node.getMemberNames()) {
                std::cout << std::string(depth, ' ') << format[4] << iconFamily.getIntermediateIcon() << " " << key << format[7]<< std::endl;
                renderNode(node[key], iconFamily, depth + 4);
            }
            std::cout << std::string(depth, ' ') << format[9] << std::endl;
        } else if (node.isArray()) {
            std::cout << std::string(depth, ' ') << format[11] << std::endl;
            for (const auto& item : node) {
                renderNode(item, iconFamily, depth + 4);
            }
            std::cout << std::string(depth, ' ') << format[1] << std::endl;
        } else {
            std::cout << std::string(depth, ' ') << format[4] << iconFamily.getLeafIcon() << " " << node.asString() << format[10]<< std::endl;
        }
    }
};

#endif // RECTANGLESTYLE_H
