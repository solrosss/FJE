#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include "IconFamily.h"
#include "Style.h"
#include "TreeStyle.h"
#include "RectangleStyle.h"
#include "PokerFaceIconFamily.h"
#include "DefaultIconFamily.h"

using namespace std;

class AbstractFactory {
private:
    string style, icon;
public:
    virtual ~AbstractFactory() {}
    virtual shared_ptr<Style> getStyle() = 0;
    virtual shared_ptr<IconFamily> getIcon() = 0;
};

class StyleFactory : public AbstractFactory {
private:
    string style, icon;
public:
    StyleFactory(string style, string icon):style(style), icon(icon) {}
    virtual shared_ptr<Style> getStyle() {
        if (style == "tree")
            return make_shared<TreeStyle>();
        else if (style == "rectangle")
            return make_shared<RectangleStyle>();
        else
            std::cerr << "Unknown style argument." << std::endl;
    }
    virtual shared_ptr<IconFamily> getIcon() {
        return nullptr;
    }
};

class IconFactory : public AbstractFactory {
private:
    string style, icon;
public:
    IconFactory(string style, string icon):style(style), icon(icon) {}
    virtual shared_ptr<Style> getStyle() {
        return nullptr;
    }
    virtual shared_ptr<IconFamily> getIcon() {
        if (icon == "default")
            return make_shared<DefaultIconFamily>();
        else if (icon == "pokerface")
            return make_shared<PokerFaceIconFamily>();
        else
            std::cerr << "Unknown icon_family argument." << std::endl;
    }
};


class FactoryProducer {
public:
    shared_ptr<AbstractFactory> createIconFactory(string style, string icon) {
        return make_shared<IconFactory>(style, icon);
    }
    shared_ptr<AbstractFactory> createStyleFactory(string style, string icon){
        return make_shared<StyleFactory>(style, icon);
    }
};



#endif // FACTORY_H
