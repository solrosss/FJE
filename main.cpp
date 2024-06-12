#include <iostream>
#include <fstream>
#include <sstream>
#include "include/json/json.h"  // Assuming we're using the jsoncpp library
#include "JSONVisualizer.h"
#include "factory.h"

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    std::string json_file, style, icon_family;

    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " -f <json file> -s <style> -i <icon family>" << std::endl;
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; i++)
    {
        if (argv[i] == "-f")
        {
            json_file = argv[++i];
        }
        else if (argv[i] == "-s")
        {
            style = argv[i + 1];
        }
        else if (argv[i] == "-i")
        {
            icon_family = argv[i + 1];
        }
        else
        {
            std::cerr << "Unknown argument: " << argv[i] << std::endl;
            return EXIT_FAILURE;
        }
    }

    try {
        std::string jsonString = readFile(json_file);

        // Parse JSON data
        Json::Value jsonData;
        Json::CharReaderBuilder builder;
        std::string errs;

        std::istringstream s(jsonString);
        bool parsingSuccessful = Json::parseFromStream(builder, s, &jsonData, &errs);

        if (!parsingSuccessful) {
            std::cerr << "Failed to parse JSON: " << errs << std::endl;
            return EXIT_FAILURE;
        }

        // Initialize visualizer with TreeStyle and PokerFaceIconFamily
        FactoryProducer factoryproducer;
        shared_ptr<AbstractFactory> StyleFactory = factoryproducer.createStyleFactory(style, icon_family);
        shared_ptr<AbstractFactory> IconFactory = factoryproducer.createIconFactory(style, icon_family);
        shared_ptr<Style> Style = StyleFactory->getStyle();
        shared_ptr<IconFamily> Icon = IconFactory->getIcon();


        JSONVisualizer visualizer(Style, Icon);

        // Visualize the JSON data
        visualizer.visualize(jsonData);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
